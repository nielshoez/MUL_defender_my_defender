/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** setup rects
*/

#include "my.h"

sfIntRect get_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfVector2f get_vector(float x, float y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}
