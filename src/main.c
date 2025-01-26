/*******************************************************************
* Analog Cloc
* Lien Zhu
* A remake of https://github.com/educ8s/Cpp-Analog-Clock-with-raylib
* but getting rid of the OOP nonsense.
*******************************************************************/

#include <stdio.h>

#include "raylib.h"
#include "analog-cloc.h"

#define size 250

int main(void)
{
    Time time;
    Color LIGHT_BLUE = {225, 239, 240, 255};
    Vector2 face_center = { WINDOW_WIDTH / 2., WINDOW_HEIGHT / 2. };

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Analog Cloc");
    SetTargetFPS(15); // WHY???

    while(!WindowShouldClose()) {
        update_time(&time);
        BeginDrawing();
        ClearBackground(LIGHT_BLUE);
        draw_cloc_face(size);
        draw_second_hand(size, &time);
        DrawCircleV( face_center, 15, DARK_GREY);
        EndDrawing();
    }

    CloseWindow();

    return EXIT_SUCCESS;
}
