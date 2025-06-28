static inline int gpio_pca9554_read_reg(struct i2c_client *client, uint8_t reg)
{
    uint8_t data;
    struct i2c_msg msgs[2];
    int ret;
    
    // Формирование сообщений для чтения
    msgs[0].flags = 0;
    msgs[0].len = sizeof(reg);
    msgs[0].buf = &reg;
    
    msgs[1].flags = I2C_MSG_FLAG_RD;
    msgs[1].len = sizeof(data);
    msgs[1].buf = &data;
    
    ret = i2c_master_xfer(client, msgs, ARRAY_SIZE(msgs));
    if (ret < 0)
        return ret;
    return data;
}

static inline int gpio_pca9554_write_reg(struct i2c_client *client, 
                                        uint8_t reg, uint8_t value)
{
    uint8_t buf[] = {reg, value};
    struct i2c_msg msg;
    
    msg.flags = 0;
    msg.len = sizeof(buf);
    msg.buf = buf;
    
    return i2c_master_xfer(client, &msg, 1);
}
