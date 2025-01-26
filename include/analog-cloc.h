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
#include <time.h>

#include "raylib.h"

Color DARK_GREY = {45, 45, 45, 255};
Color LIGHT_GREY = {229, 229, 229, 255};

typedef struct {
    int hour;
    int min;
    int sec;
} Time;

// Gets the time stamp to draw
void update_time(Time* curr_t)
{
    time_t t = time(NULL);
    struct tm* now = localtime(&t);

    curr_t->hour = now->tm_hour;
    curr_t->min = now->tm_min;
    curr_t->sec = now->tm_sec;
}

int draw_cloc_face(int size)
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

int draw_hour_hand();
int draw_minute_hand();
int draw_second_hand();
