bool i2c_client_register(struct i2c_client *client)
{
    struct i2c_adapter *adapter;
    bool ret = true, is_slave;
    
    if (client == NULL)
        return false;
    
    is_slave = (client->flags & I2C_CLIENT_FLAG_SLAVE);
    if (is_slave && client->callback == NULL)
        return false;
    
    adapter = client->adapter;
    if (!i2c_adapter_is_valid(adapter))
        return false;
    
    if (is_slave && adapter->ops->slave_register)
        ret = adapter->ops->slave_register(client);
    
    if (ret)
        list_add_tail(&client->list_entry, &adapter->client_list);
    
    return ret;
}
