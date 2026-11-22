#include "Milestone.h"
#include "Card.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <raylib.h>
#include <string>
#include <vector>

using namespace std;

int main() {
    // screen dimensions
    const int screenWidth = 1440;
    const int screenHeight = 1080;

    // initialize window and set fps
    InitWindow(screenWidth, screenHeight, "Timeline Scroll - Raylib");
    SetTargetFPS(60);

    // milestone years
    const vector<int> years = {
        2025, 2012, 2000, 1975, 1950, 1925,
        1900, 1850, 1800, 1700, 1600, 1500
    };

    // vector of milestone years
    vector<Milestone> milestones;

    // making sure the years are positioned nicely
    float currentY = 220.0f;
    const float pixelsPerYear = 4.0f;
    const float minGap = 140.0f;

    // positioning for each milestone
    for (size_t i = 0; i < years.size(); ++i) {
        if (i > 0) { // first milestone should just be at y=220
            float yearDelta = static_cast<float>(years[i - 1] - years[i]);
            float spacing = max(minGap, yearDelta * pixelsPerYear);
            currentY += spacing;
        }
        milestones.push_back({years[i], currentY, 36.0f});
    }

    // Specific hand-picked card positions: {worldX, worldY, radius, text}
    vector<Card> cards = {
        {720.0f,  220.0f, 34.0f, "A"},
        {540.0f,  310.0f, 30.0f, "A"},
        {930.0f,  390.0f, 40.0f, "A"},
        {650.0f,  480.0f, 28.0f, "A"},
        {860.0f,  560.0f, 36.0f, "A"},
        {480.0f,  650.0f, 32.0f, "A"},
        {980.0f,  740.0f, 38.0f, "A"},
        {720.0f,  830.0f, 42.0f, "A"},
        {560.0f,  920.0f, 30.0f, "A"},
        {890.0f, 1010.0f, 35.0f, "A"},
        {640.0f, 1110.0f, 32.0f, "A"},
        {940.0f, 1200.0f, 38.0f, "A"},
        {510.0f, 1290.0f, 28.0f, "A"},
        {760.0f, 1380.0f, 40.0f, "A"},
        {960.0f, 1480.0f, 34.0f, "A"},
        {600.0f, 1570.0f, 36.0f, "A"},
        {830.0f, 1670.0f, 30.0f, "A"},
        {470.0f, 1760.0f, 38.0f, "A"},
        {720.0f, 1860.0f, 42.0f, "A"},
        {950.0f, 1950.0f, 32.0f, "A"},
        {580.0f, 2050.0f, 34.0f, "A"},
        {840.0f, 2140.0f, 36.0f, "A"},
        {670.0f, 2240.0f, 28.0f, "A"},
        {920.0f, 2340.0f, 40.0f, "A"},
        {500.0f, 2440.0f, 35.0f, "A"},
        {750.0f, 2540.0f, 32.0f, "A"},
        {970.0f, 2640.0f, 38.0f, "A"},
        {610.0f, 2740.0f, 30.0f, "A"},
        {860.0f, 2840.0f, 36.0f, "A"},
        {530.0f, 2940.0f, 34.0f, "A"},
        {720.0f, 3050.0f, 42.0f, "A"},
        {940.0f, 3160.0f, 32.0f, "A"},
        {620.0f, 3270.0f, 38.0f, "A"},
        {870.0f, 3380.0f, 30.0f, "A"},
        {490.0f, 3490.0f, 36.0f, "A"},
        {760.0f, 3600.0f, 34.0f, "A"},
        {960.0f, 3710.0f, 40.0f, "A"},
        {590.0f, 3820.0f, 28.0f, "A"},
        {820.0f, 3930.0f, 35.0f, "A"},
        {720.0f, 4050.0f, 38.0f, "A"}
    };

    // set up our camera
    Camera2D camera = {0};
    camera.target = {0.0f, 0.0f};
    camera.offset = {0.0f, 0.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    // scroll boundaries
    const float minScrollY = 0.0f;
    float lowestContentY = milestones.back().worldY;
    for (const Card& card : cards) {
        lowestContentY = max(lowestContentY, card.worldY);
    }
    const float maxScrollY = max(minScrollY, lowestContentY - (screenHeight * 0.5f));

    // getting where we want to scroll to
    float scrollTargetY = minScrollY;
    const float scrollSpeed = 95.0f;
    const float smoothness = 12.0f;

    while (!WindowShouldClose()) {
        // getting time between each frame
        float dt = GetFrameTime();


        // calculating our scroll
        float wheel = GetMouseWheelMove();
        if (wheel != 0.0f) {
            scrollTargetY -= wheel * scrollSpeed;
        }
        if (IsKeyDown(KEY_DOWN)) {
            scrollTargetY += scrollSpeed * 8.0f * dt;
        }
        if (IsKeyDown(KEY_UP)) {
            scrollTargetY -= scrollSpeed * 8.0f * dt;
        }

        scrollTargetY = clamp(scrollTargetY, minScrollY, maxScrollY);

        // updating our camera
        float t = 1.0f - exp(-smoothness * dt);
        camera.target.y += (scrollTargetY - camera.target.y) * t;
        camera.target.y = clamp(camera.target.y, minScrollY, maxScrollY);

        BeginDrawing();
            ClearBackground(BLACK);

            // while the cameras running...
            BeginMode2D(camera);
                for (const Card& card : cards) { // for every card
                    DrawCircleV({card.worldX, card.worldY}, card.radius, WHITE); // draw them where they should be
                    DrawText(card.text.c_str(), card.worldX, card.worldY, 14, BLACK);
                }
            EndMode2D();

            // writing the text for the milestones
            const float trackX = 115.0f;
            const int fontSize = 26;

            DrawLineEx({trackX, 0.0f}, {trackX, static_cast<float>(screenHeight)}, 1.0f, Fade(RAYWHITE, 0.15f));

            for (const Milestone& m : milestones) { // for every milestone within our milestones
                float screenY = m.worldY - camera.target.y;

                if (screenY >= -60.0f && screenY <= static_cast<float>(screenHeight) + 60.0f) {
                    string label = to_string(m.year);
                    int textWidth = MeasureText(label.c_str(), fontSize);

                    int textX = static_cast<int>(trackX) - textWidth - 24;
                    int textY = static_cast<int>(screenY) - (fontSize / 2);

                    DrawText(label.c_str(), textX, textY, fontSize, Fade(WHITE, 0.92f));
                }
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}