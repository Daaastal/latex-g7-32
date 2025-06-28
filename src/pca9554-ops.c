static int gpio_pca9554_get_direction(struct gpio_chip *gc, unsigned int offset)
{
    struct gpio_chip_pca9554 *priv = gc->private_data;
    return (priv->dir & offset);
}

static bool gpio_pca9554_direction_input(struct gpio_chip *gc, unsigned int offset)
{
    struct gpio_chip_pca9554 *priv = gc->private_data;
    int ret = gpio_pca9554_write_direction(priv, offset, 1);
    return (ret >= 0);
}

static bool gpio_pca9554_direction_output(struct gpio_chip *gc, 
                                         unsigned int offset, int value)
{
    struct gpio_chip_pca9554 *priv = gc->private_data;
    int ret;
    
    // Сначала устанавливаем выходное состояние
    ret = gpio_pca9554_write_output(priv, offset, value);
    if (ret < 0)
        return false;
    
    // Затем переключаем направление на выход
    ret = gpio_pca9554_write_direction(priv, offset, 0);
    return (ret >= 0);
}

static const struct gpio_chip_ops gpio_pca9554_ops = {
    .get_direction = gpio_pca9554_get_direction,
    .direction_input = gpio_pca9554_direction_input,
    .direction_output = gpio_pca9554_direction_output,
    .get = gpio_pca9554_get,
    .set = gpio_pca9554_set,
    .set_config = gpio_pca9554_set_config,
};
