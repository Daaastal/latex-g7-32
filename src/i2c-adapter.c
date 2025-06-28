/** Структура дескриптора шины I2C */
struct i2c_adapter {
    /** Точка включения в очередь шин */
    struct list_head list_entry;
    /** Имя шины */
    char name[I2C_NAME_SIZE];
    /** Номер шины */
    unsigned int nr;
    /** Скорость шины */
    unsigned int speed;
    /** Число попыток выполнения тразакции в режиме ведущего */
    unsigned int retries;
    /** Интервал времени на все попытки транзакции ведущим, мс */
    unsigned int retries_timeout_ms;
    /** Список устройств на шине */
    struct list_head client_list;
    /** Операции над шиной I2C */
    const struct i2c_adapter_ops *ops;
    /** Данные шины I2C */
    void *private_data;
};
