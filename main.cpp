// headers here ...
#include <iostream>
#include <raylib.h>
#include <string>
using namespace std;

/**
 * Looking at: https://www.raylib.com/examples.html
 */

int main() {

    /***
    your project code here!
    ***/
    
    const int screenWidth = 1440;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "cool title");

    int boxPositionY = screenHeight/2 - 40;
    int scrollSpeed = 4;    

    SetTargetFPS(60); 

    // main loop
    while (!WindowShouldClose()) {

        boxPositionY -= static_cast<int>(GetMouseWheelMove()*scrollSpeed));

        // drawing our screen
        BeginDrawing(); 
            ClearBackground(RAYWHITE);

            DrawRectangle(screenWidth/2 - 40, boxPositionY, 80, 80, MAROON);

            DrawText(TextFormat("Box position Y: %03i", boxPositionY), 10, 40, 20, LIGHTGRAY);
            
        EndDrawing();
    }

    
    CloseWindow();
    
    return 0;
}