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
        {720.0f,  220.0f, 34.0f, "Support Vector Machines", "A Support Vector Machine (SVM) is a supervised machine learning algorithm used mainly for classification and regression. Its primary goal is to find a boundary—called a hyperplane—that separates data classes with the widest possible margin.", false},
        {540.0f,  300.0f, 30.0f, "A", "Pretend this is a unique description.", false},
        {930.0f,  370.0f, 40.0f, "A", "Pretend this is a unique description.", false},
        {650.0f,  445.0f, 28.0f, "A", "Pretend this is a unique description.", false},
        {860.0f,  520.0f, 36.0f, "A", "Pretend this is a unique description.", false},
        {480.0f,  595.0f, 32.0f, "A", "Pretend this is a unique description.", false},
        {980.0f,  670.0f, 38.0f, "A", "Pretend this is a unique description.", false},
        {720.0f,  745.0f, 42.0f, "A", "Pretend this is a unique description.", false},
        {560.0f,  820.0f, 30.0f, "A", "Pretend this is a unique description.", false},
        {890.0f,  895.0f, 35.0f, "A", "Pretend this is a unique description.", false},
        {640.0f,  970.0f, 32.0f, "A", "Pretend this is a unique description.", false},
        {940.0f, 1045.0f, 38.0f, "A", "Pretend this is a unique description.", false},
        {510.0f, 1120.0f, 28.0f, "A", "Pretend this is a unique description.", false},
        {760.0f, 1195.0f, 40.0f, "A", "Pretend this is a unique description.", false},
        {960.0f, 1270.0f, 34.0f, "A", "Pretend this is a unique description.", false},
        {600.0f, 1345.0f, 36.0f, "A", "Pretend this is a unique description.", false},
        {830.0f, 1420.0f, 30.0f, "A", "Pretend this is a unique description.", false},
        {470.0f, 1495.0f, 38.0f, "A", "Pretend this is a unique description.", false},
        {720.0f, 1570.0f, 42.0f, "A", "Pretend this is a unique description.", false},
        {950.0f, 1645.0f, 32.0f, "A", "Pretend this is a unique description.", false},
        {580.0f, 1720.0f, 34.0f, "A", "Pretend this is a unique description.", false},
        {840.0f, 1795.0f, 36.0f, "A", "Pretend this is a unique description.", false},
        {670.0f, 1870.0f, 28.0f, "A", "Pretend this is a unique description.", false},
        {920.0f, 1945.0f, 40.0f, "A", "Pretend this is a unique description.", false},
        {500.0f, 2020.0f, 35.0f, "A", "Pretend this is a unique description.", false},
        {750.0f, 2095.0f, 32.0f, "A", "Pretend this is a unique description.", false},
        {970.0f, 2170.0f, 38.0f, "A", "Pretend this is a unique description.", false},
        {610.0f, 2245.0f, 30.0f, "A", "Pretend this is a unique description.", false},
        {860.0f, 2320.0f, 36.0f, "A", "Pretend this is a unique description.", false},
        {530.0f, 2395.0f, 34.0f, "A", "Pretend this is a unique description.", false},
        {720.0f, 2465.0f, 42.0f, "A", "Pretend this is a unique description.", false},
        {940.0f, 2515.0f, 32.0f, "A", "Pretend this is a unique description.", false},
        {620.0f, 2560.0f, 38.0f, "A", "Pretend this is a unique description.", false},
        {870.0f, 2595.0f, 30.0f, "A", "Pretend this is a unique description.", false},
        {490.0f, 2625.0f, 36.0f, "A", "Pretend this is a unique description.", false},
        {760.0f, 2650.0f, 34.0f, "A", "Pretend this is a unique description.", false},
        {960.0f, 2740.0f, 40.0f, "A", "Pretend this is a unique description.", false},
        {590.0f, 2830.0f, 28.0f, "A", "Pretend this is a unique description.", false},
        {820.0f, 2920.0f, 35.0f, "A", "Pretend this is a unique description.", false},
        {720.0f, 3010.0f, 38.0f, "B", "Pretend this is a REALLY unique description.", false}
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

    Vector2 mousePoint = {0, 0};

    int activeCardIndex = -1; // -1 means no description box is currently shown

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

                    int circleTextFontSize = clamp(static_cast<int>(card.radius * 0.45f), 10, 24); // between 10 and 24 so its not abnormally small or large
                    int circleTextWidth = MeasureText(card.text.c_str(), circleTextFontSize);

                    int circleTextX = static_cast<int>(card.worldX) - (circleTextWidth/2);
                    int circleTextY = static_cast<int>(card.worldY) - (circleTextFontSize/2);

                    DrawText(card.text.c_str(), circleTextX, circleTextY, circleTextFontSize, BLACK);
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

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
                bool clickedAnyCard = false;

                // Check top-most drawn cards first if any overlap
                for (int i = static_cast<int>(cards.size()) - 1; i >= 0; --i) {
                    if (CheckCollisionPointCircle(mouseWorldPos, {cards[i].worldX, cards[i].worldY}, cards[i].radius)) {
                        if (activeCardIndex == i) {
                            activeCardIndex = -1; // Clicking the open card again closes it
                        } else {
                            activeCardIndex = i;  // Clicking a different card switches to it
                        }
                        clickedAnyCard = true;
                        break;
                    }
                }

                // clicking empty space should also close the box
                if (!clickedAnyCard) {
                    activeCardIndex = -1;
                }
            }

            for (const Card& card : cards) {
                if (activeCardIndex >= 0 && activeCardIndex < static_cast<int>(cards.size())) {
                    cards[activeCardIndex].DisplayDescription(screenWidth, screenHeight);
                }
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}