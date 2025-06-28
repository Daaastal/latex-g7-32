bool gpiochip_add(struct gpio_chip *gc, void *data, const struct gpio_chip_ops *ops)
{
    struct gpio_chip *entry;
    size_t idx, base = 0;
    
    if (gpiochip_is_valid(gc))
        return true;
    if (!(gc->ngpio && gc->descs))
        return false;
    
    // Ищем свободное место в диапазоне номеров
    list_for_each_entry(entry, &gpio_chips, list_entry) {
        if (entry->base >= base + gc->ngpio)
            break;
        base = entry->base + entry->ngpio;
    }
    
    // Автоматическое именование чипа
    if (strlen(gc->name) == 0)
        snprintf(gc->name, sizeof(gc->name), "%s%zu", GPIOCHIP_NAME_PREFIX, base);
    
    // Инициализация параметров чипа
    gc->base = base;
    gc->private_data = data;
    gc->ops = ops;
    
    // Инициализация дескрипторов выводов
    for (idx = 0; idx < gc->ngpio; ++idx) {
        gc->descs[idx].chip = gc;
        gc->descs[idx].offset = idx;
    }
    
    list_add_tail(&gc->list_entry, &gpio_chips);
    return true;
}
