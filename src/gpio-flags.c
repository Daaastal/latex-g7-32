#define GPIOD_FLAG_REQUESTED    (1UL << 0)  /* Вывод захвачен */
#define GPIOD_FLAG_DIR_OUT      (1UL << 1)  /* Направление: выход */
#define GPIOD_FLAG_OUT_HIGH     (1UL << 2)  /* Начальное состояние: высокий уровень */
#define GPIOD_FLAG_OPEN_DRAIN   (1UL << 3)  /* Тип выхода: открытый сток */
#define GPIOD_FLAG_PULL_UP      (1UL << 4)  /* Подтяжка к питанию */
#define GPIOD_FLAG_PULL_DOWN    (1UL << 5)  /* Подтяжка к земле */
#define GPIOD_FLAG_ACTIVE_LOW   (1UL << 6)  /* Активный низкий уровень */
#define GPIOD_FLAG_USED_AS_IRQ  (1UL << 7)  /* Используется как прерывание */
#define GPIOD_FLAG_EDGE_RISING  (1UL << 8)  /* Прерывание по переднему фронту */
#define GPIOD_FLAG_EDGE_FALLING (1UL << 9)  /* Прерывание по заднему фронту */
#define GPIOD_FLAG_DIR_ASIS     (1UL << 10) /* Не изменять направление */