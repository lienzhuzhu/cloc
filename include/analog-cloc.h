/**************
* analog-cloc.h
* Lien Zhu
* The cloc.
**************/

#define EXIT_FAILURE   -1
#define EXIT_SUCCESS    0

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 600

#define DEGREES_IN_A_CIRCLE 360
#define NUM_HOURS            12

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
    DrawCircleV( face_center, size - 30, RAYWHITE);

    float rect_width = 10;
    float rect_height = size;

    Rectangle tick_mark = {
        WINDOW_WIDTH / 2., WINDOW_HEIGHT / 2.,
        rect_width, rect_height
    };

    float degrees_between_ticks = 1. * DEGREES_IN_A_CIRCLE / NUM_HOURS;
    Vector2 rotation_origin = {rect_width / 2., rect_height};
    for (int i = 0; i < 12; i++) {
        DrawRectanglePro(tick_mark, rotation_origin, i * degrees_between_ticks, DARK_GREY);
    }
    DrawCircleV( face_center, size - 45, RAYWHITE);

    return EXIT_SUCCESS;
}

void draw_second_hand(int size, Time* time)
{
    float hand_width = 2;
    float hand_height = size - 35;
    Rectangle sec_hand = {
        WINDOW_WIDTH / 2., WINDOW_HEIGHT / 2.,
        hand_width, hand_height
    };
    Vector2 rotation_origin = {hand_width / 2., hand_height};

    int seconds = time->sec;
    DrawRectanglePro(sec_hand, rotation_origin, 6. * seconds, RED);
}

void draw_minute_hand(int size, Time* time)
{
    float hand_width = 10;
    float hand_height = size - 55;
    Rectangle min_hand = {
        WINDOW_WIDTH / 2., WINDOW_HEIGHT / 2.,
        hand_width, hand_height
    };
    Vector2 rotation_origin = {hand_width / 2., hand_height};
    int minutes = time->min;
    DrawRectanglePro(min_hand, rotation_origin, 6. * minutes, BLACK);
}

void draw_hour_hand(int size, Time* time)
{
    float hand_width = 15;
    float hand_height = size - 130;
    Rectangle hour_hand = {
        WINDOW_WIDTH / 2., WINDOW_HEIGHT / 2.,
        hand_width, hand_height
    };
    Vector2 rotation_origin = {hand_width / 2., hand_height};
    int hour = time->hour;
    DrawRectanglePro(hour_hand, rotation_origin, 30 * hour + time->min / 2., BLACK);
}
