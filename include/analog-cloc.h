/**************
* analog-cloc.h
* Lien Zhu
* The cloc.
**************/

#define EXIT_FAILURE   -1
#define EXIT_SUCCESS    0

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 600

#include <stdio.h>
#include "raylib.h"

Color DARK_GREY = {45, 45, 45, 255};
Color LIGHT_GREY = {229, 229, 229, 255};

/*void update_cloc();*/

int draw_cloc(int size)
{
    if (size < 200) {
        printf("Size must be greater than 200\n");
        return EXIT_FAILURE;
    }

    Vector2 face_center = { WINDOW_WIDTH / 2., WINDOW_HEIGHT / 2. };
    DrawCircleV( face_center, size, DARK_GREY);
    DrawCircleV( face_center, size - 30, LIGHT_GREY);
    DrawCircleV( face_center, size - 40, RAYWHITE);
    DrawCircleV( face_center, 20, DARK_GREY);

    return EXIT_SUCCESS;
}
