// headers here ...
#include <iostream>
#include <raylib.h>
#include <string>
#include <random>
using namespace std;

int main() {

    /***
    your project code here!
    ***/

    // Initialization (setting up the size of the screen)
    const int screenWidth = 1440;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "shapes i think");
    SetTargetFPS(60); // Set our game to run at 60 fps

    float rotation = 0.0f;

    srand(time(NULL));
    int basketballXOffset = 0;
    bool basketballXInrease = true;
    int basketballYOffset = 0;
    bool basketballYIncrease = true;


    // main loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key

        // periodically update the current rotation
        rotation += 0.2f;

        // basketball
        
        if (basketballXInrease) {
            basketballXOffset += rand() % 10;
        } else {
            basketballXOffset -= rand() % 10;
        }

        if (basketballXOffset > 200) {
            basketballXInrease = false;
        }
        if (basketballXOffset < -200) {
            basketballXInrease = true;
        }

        if (basketballYIncrease) {
            basketballYOffset += rand() % 10;
        } else {
            basketballYOffset -= rand() % 10;
        }

        if (basketballYOffset > 200) {
            basketballYIncrease = false;
        }
        if (basketballYOffset < -200) {
            basketballYIncrease = true;
        }
        

        cout << "OFFSET: " << basketballXOffset << endl;

        



        // drawing our screen
        BeginDrawing(); // starts drawing (puts down the pen)
            // whatever you want to do over here
            ClearBackground(RAYWHITE);
            DrawText("some sick looking shapes i think", 20, 20, 20, BLUE);

            // those weird round things
            DrawCircle(screenWidth/5, 120, 35, DARKBLUE); // center should appear 20% from the left near the top | format is generally center positions, radius, color
            DrawCircleGradient(Vector2 {screenWidth/5.0f, 220.0f}, 60.0f, GREEN, SKYBLUE); // for some reason it wants the center in a vector? first color is the gradiant
            DrawCircleLines(screenWidth/5, 340, 80, DARKBLUE);
            DrawEllipse(screenWidth/5, 120, 25, 20, YELLOW);
            DrawEllipseLines(screenWidth/5, 120, 30, 25, YELLOW);

            // idk they have like 2 pairs of equal sides
            DrawRectangle(screenWidth/4*2 - 60, 100, 120, 60, RED); // why do they do /4*2? Doing /2 accomplishes the same thing.
            DrawRectangleGradientH(screenWidth/4*2 - 90, 170, 180, 130, MAROON, GOLD);
            DrawRectangleLines(screenWidth/4*2 - 40, 320, 80, 60, ORANGE); // apparently uses QUAD internally and not lines, whatever that means

            // dorito
            DrawTriangle(
                Vector2 {screenWidth/4.0f * 3.0f, 30.0f}, // each vertice of the triangle has to be entered
                Vector2 {screenWidth/4.0f * 3.0f - 60.0f, 150.0f}, // we're going to the third quarter of the screen, then back and forth by 60 units
                Vector2 {screenWidth/4.0f * 3.0f + 60.0f, 150.0f}, // the top vertice is on a different y-level than the bottom vertices
                VIOLET // it is equilateral because the distance from the center is the same in both directions
            ); // 60 + 60 = 120, so the y-pos needs 120 units of distance
            
            DrawTriangleLines(
                Vector2 {screenWidth/4.0f * 3.0f, 200.0f},
                Vector2 {screenWidth/4.0f * 3.0f + 50, 200.0f+150.0f},
                Vector2 {screenWidth/4.0f * 3.0f - 50, 200.0f+150.0f},
                DARKBLUE
            );

            // miscellaneous polygons
            DrawPoly(Vector2 {screenWidth/4.0f*3.0f, 330}, 6, 80, rotation, BROWN); // brown 6 sided polygon with sides of 80 pixels wide and varying rotation
            DrawPolyLines(Vector2 {screenWidth/4.0f*3.0f, 330}, 6, 90, rotation, BROWN);
            DrawPolyLinesEx(Vector2 {screenWidth/4.0f*3, 330}, 6, 85, rotation, 6, BEIGE); // lets us give the lines thickness


            // my own thing
            DrawPoly(Vector2 {screenWidth/4.0f * 2.0f, screenHeight/4.0f * 2.0f}, 12, screenWidth/4.0f * 0.5f, rotation*2, MAROON);

            // basketball
            DrawPoly(Vector2 {screenWidth/4.0f*2.0f + basketballXOffset, screenHeight/4.0f*2.0f + basketballXOffset}, 50, 80, 0, BROWN);
            DrawPolyLinesEx(Vector2 {screenWidth/4.0f*2.0f + basketballXOffset, screenHeight/4.0f*2.0f + basketballXOffset}, 50, 90, 0, 10, BLACK);

        EndDrawing(); // ends drawing (picks up the pen)
    }

    // de-initialize
    CloseWindow();
    
    return 0;
}