struct gpio_desc *gpiod_get(struct gpio_chip *gc, unsigned int pin,
						unsigned long flags)
{
    struct gpio_desc *desc;
    bool ret;
    
    if (!gpiochip_is_valid(gc) || pin >= gc->ngpio)
        return NULL;
    
    desc = gc->descs + pin;
    if (desc->flags & GPIOD_FLAG_REQUESTED)
        return NULL;  // Вывод уже используется
    
    desc->flags |= GPIOD_FLAG_REQUESTED;
    ret = gpiod_set_config(desc, flags);
    if (ret)
        return desc;
    
    desc->flags &= ~GPIOD_FLAG_REQUESTED;  // Откат при ошибке
    return NULL;
}

void gpiod_put(struct gpio_desc *desc)
{
    if (desc && (desc->flags & GPIOD_FLAG_REQUESTED))
        desc->flags &= ~GPIOD_FLAG_REQUESTED;
}
