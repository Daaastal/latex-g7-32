/** Дескриптор расширителя порта GPIO PCA9554 */
struct gpio_chip_pca9554 {
    /** Дескриптор чипа GPIO */
    struct gpio_chip;
    /** Клиент шины I2C */
    struct i2c_client client;
    /** Значение регистров Direction и Output Port */
    uint8_t dir, out;
};

// Адреса регистров PCA9554
#define GPIO_PCA9554_INPUT_REG     0x00
#define GPIO_PCA9554_OUTPUT_REG    0x01
#define GPIO_PCA9554_INVERT_REG    0x02
#define GPIO_PCA9554_DIRECTION_REG 0x03
