// headers here ...
#include <iostream>
#include <raylib.h>
#include <string>
using namespace std;

int main() {

    /***
    your project code here!
    ***/

    // Initialization (setting up the size of the screen)
    const int screenWidth = 1440;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "cool title");
    SetTargetFPS(60); // Set our game to run at 60 fps

    string inputText;
    string outputText;
    cout << "Enter your text: ";
    cin >> inputText;
    outputText = "You said: " + inputText;

    // main loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key

        // drawing our screen
        BeginDrawing(); // starts drawing (puts down the pen)
            ClearBackground(RAYWHITE); // makes the background white
            DrawText(outputText.c_str(), 190, 200, 50, BLACK); // writes the text at (190, 200) in size 20 with light gray font
        EndDrawing(); // ends drawing (picks up the pen)
    }

    // de-initialize
    CloseWindow();
    
    return 0;
}