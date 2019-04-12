/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** issou quoi
*/

#include "my.h"

static unsigned int new_seed(void)
{
    int fd = open("/dev/urandom", O_RDONLY);
    int res = 0;

    if (fd == -1)
        return (0);
    if (read(fd, &res, 7) == -1)
        new_seed();
    close(fd);
    if (res < 0)
        res = res *-1;
    return (res);
}

static float get_random_y_pos(void)
{
    static int i = 0;

    if (i == 0)
        srand(new_seed());
    i++;
    return ((float) (rand() % (900 - 200 + 1) + 200));
}

static float center_y_value(float y)
{
    float new_y = 0;

    if ((y >= 250 && y < 370) || y <= 250)
        new_y = 300;
    if (y >= 370 && y <= 490)
        new_y = 420;
    if (y >= 491 && y <= 620)
        new_y = 545;
    if (y >= 621 && y <= 740)
        new_y = 670;
    if (y > 740)
        new_y = 790;
    return (new_y);
}

int random_rect(void)
{
    int res = rand() % (6 - 1 + 1) + 1;
    return (res);
}

sfVector2f new_random_pos(void)
{
    sfVector2f new_pos;

    new_pos.x = 1300;
    new_pos.y = get_random_y_pos();
    new_pos.y = center_y_value(new_pos.y);
    return (new_pos);
}
