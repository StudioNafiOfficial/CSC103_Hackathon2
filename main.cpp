// headers here ...
#include <iostream>
#include <raylib.h>
#include <string>
using namespace std;

/**
 * Looking at: https://www.raylib.com/examples/textures/loader.html?name=textures_sprite_button
 */

int main() {

    /***
    your project code here!
    ***/

    
    const int screenWidth = 1440;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "cool title");

    Texture2D buttonTex = LoadTexture("resources/button.png"); // load the texture we'll use for the button

    int buttonState = 0; // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool buttonAction = false; // button action needs to be activated

    Vector2 mousePoint = {0.0f, 0.0f};

    SetTargetFPS(60); 

    // main loop
    while (!WindowShouldClose()) {

        mousePoint = GetMousePosition();
        buttonAction = false;

        // if (CheckCollisionPointRec(mousePoint, )) {

        // }

        // drawing our screen
        BeginDrawing(); 
            ClearBackground(RAYWHITE);
        EndDrawing();
    }

    
    CloseWindow();
    
    return 0;
}