bool i2c_adapter_add(struct i2c_adapter *adapter, void *data,
                     const struct i2c_adapter_ops *ops)
{
    if (adapter == NULL || ops->startup == NULL)
        return false;
    
    adapter->private_data = data;
    adapter->ops = ops;
    
    if (adapter->retries_timeout_ms == 0)
        adapter->retries_timeout_ms = MSEC_PER_SEC;
    if (adapter->retries == 0)
        adapter->retries = UINT_MAX;
    
    if (strlen(adapter->name) == 0)
        snprintf(adapter->name, sizeof(adapter->name), "%s%u",
                I2C_ADAPTER_NAME_PREFIX, adapter->nr);
    
    INIT_LIST_HEAD(&adapter->client_list);
    
    if (!adapter->ops->startup(adapter))
        return false;
    
    list_add_tail(&adapter->list_entry, &i2c_adapters);
    return true;
}
