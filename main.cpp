// headers here ...
#include <iostream>
#include <raylib.h>
#include <string>
using namespace std;

int main() {

    /***
    your project code here!
    ***/

    
    const int screenWidth = 1440;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "cool title");
    SetTargetFPS(60); 

    // main loop
    while (!WindowShouldClose()) {

        // drawing our screen
        BeginDrawing(); 
            ClearBackground(RAYWHITE);
        EndDrawing();
    }

    
    CloseWindow();
    
    return 0;
}