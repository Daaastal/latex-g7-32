/** Дескриптор вывода GPIO */
struct gpio_desc {
    /** Имя вывода */
    const char *name;
    /** Дескриптор чипа GPIO */
    struct gpio_chip *chip;
    /** Смещение вывода */
    unsigned int offset;
    /** Флаги вывода */
    unsigned long flags;
};
