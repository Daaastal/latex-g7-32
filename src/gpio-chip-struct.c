/** Дескриптор чипа GPIO */
struct gpio_chip {
    /** Точка включения в очередь чипов */
    struct list_head list_entry;
    /** Имя чипа */
    char name[GPIOCHIP_NAME_SIZE];
    /** Данные чипа */
    void *private_data;
    /** Операции чипа */
    const struct gpio_chip_ops *ops;
    /** Базовый номер выводов */
    size_t base;
    /** Число выводов */
    size_t ngpio;
    /** Дескрипторы выводов чипа */
    struct gpio_desc *descs;
};