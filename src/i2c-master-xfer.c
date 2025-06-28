int i2c_master_xfer(struct i2c_client *client, struct i2c_msg *msgs, size_t num)
{
    struct i2c_adapter *adapter;
    int ret = -ETIMEDOUT;
    unsigned int try;
    unsigned long expire;
    size_t i;
    
    if (!i2c_client_is_valid(client))
        return -ENODEV;
    if (num == 0)
        return 0;
    
    for (i = 0; i < num; ++i) {
        msgs[i].addr = client->addr;
        if (client->flags & I2C_CLIENT_FLAG_TEN)
            msgs[i].flags |= I2C_MSG_FLAG_TEN;
    }
    
    msgs[num - 1].flags |= I2C_MSG_FLAG_STOP;
    
    adapter = client->adapter;
    expire = jiffies + msecs_to_jiffies(adapter->retries_timeout_ms);
    
    for (try = 0; try <= adapter->retries; ++try) {
        ret = adapter->ops->master_xfer(adapter, msgs, num);
        if (ret != -EAGAIN)
            break;
        if (time_after(jiffies, expire))
            break;
    }
    
    return ret;
}
