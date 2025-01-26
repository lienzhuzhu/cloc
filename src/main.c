/*******************************************************************
* Analog Cloc
* Lien Zhu
* A remake of https://github.com/educ8s/Cpp-Analog-Clock-with-raylib
* but getting rid of the OOP nonsense.
*******************************************************************/

#include <stdio.h>

#include "raylib.h"
#include "analog-cloc.h"

int main(void)
{
    Time time;
    Color LIGHT_BLUE = {225, 239, 240, 255};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Analog Cloc");
    SetTargetFPS(15); // WHY???

    while(!WindowShouldClose()) {
        /*update_time(&time);*/
        BeginDrawing();
        ClearBackground(LIGHT_BLUE);
        draw_cloc_face(250);
        EndDrawing();
    }

    CloseWindow();

    return EXIT_SUCCESS;
}
