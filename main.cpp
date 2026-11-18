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

    int numFrames = 3;

    InitWindow(screenWidth, screenHeight, "cool title");

    Texture2D buttonTex = LoadTexture("resources/rectanglebutton.png"); // load the texture we'll use for the button

    int buttonState = 0; // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool buttonAction = false; // button action needs to be activated

    float frameHeight = static_cast<float>(buttonTex.height)/numFrames;
    Rectangle sourceRec = {0, 0, static_cast<float>(buttonTex.width), frameHeight};
    Rectangle buttonBounds = {screenWidth/2.0f - buttonTex.width/2.0f, screenHeight/2.0f - static_cast<float>(buttonTex.height)/numFrames/2.0f, static_cast<float>(buttonTex.width), frameHeight};

    Vector2 mousePoint = {0.0f, 0.0f};

    SetTargetFPS(60); 

    // main loop
    while (!WindowShouldClose()) {

        mousePoint = GetMousePosition();
        buttonAction = false;

        if (CheckCollisionPointRec(mousePoint, buttonBounds)) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                buttonState = 2;
            } else {
                buttonState = 1;
            }
        } else {
            buttonState = 0;
        }

        sourceRec.y = buttonState*frameHeight;


        // drawing our screen
        BeginDrawing(); 
            ClearBackground(RAYWHITE);
            DrawTextureRec(buttonTex, sourceRec, Vector2 {buttonBounds.x, buttonBounds.y}, WHITE);
        EndDrawing();
    }

    UnloadTexture(buttonTex);
    CloseWindow();
    
    return 0;
}