#include "Milestone.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <raylib.h>
#include <string>
#include <vector>

using namespace std;

int main() {
    const int screenWidth = 1440;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Timeline Scroll - Raylib");
    SetTargetFPS(60);

    const vector<int> years = {
        2025, 2012, 2000, 1975, 1950, 1925,
        1900, 1850, 1800, 1700, 1600, 1500
    };

    vector<Milestone> milestones;

    float currentY = 220.0f;
    const float pixelsPerYear = 4.0f;
    const float minGap = 140.0f;

    for (size_t i = 0; i < years.size(); ++i) {
        if (i > 0) {
            float yearDelta = static_cast<float>(years[i - 1] - years[i]);
            float spacing = max(minGap, yearDelta * pixelsPerYear);
            currentY += spacing;
        }
        milestones.push_back({years[i], currentY, 36.0f});
    }

    Camera2D camera = {0};
    camera.target = {0.0f, 0.0f};
    camera.offset = {0.0f, 0.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    const float minScrollY = 0.0f;
    const float lastMilestoneY = milestones.back().worldY;
    const float maxScrollY = max(minScrollY, lastMilestoneY - (screenHeight * 0.5f));

    float scrollTargetY = minScrollY;
    const float scrollSpeed = 95.0f;
    const float smoothness = 12.0f;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

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

        float t = 1.0f - exp(-smoothness * dt);
        camera.target.y += (scrollTargetY - camera.target.y) * t;
        camera.target.y = clamp(camera.target.y, minScrollY, maxScrollY);

        BeginDrawing();
            ClearBackground(BLACK);

            BeginMode2D(camera);
                const float centerX = screenWidth * 0.5f;
                for (const Milestone& m : milestones) {
                    DrawCircleV({centerX, m.worldY}, m.circleRadius, WHITE);
                }
            EndMode2D();

            const float trackX = 115.0f;
            const int fontSize = 26;

            DrawLineEx({trackX, 0.0f}, {trackX, static_cast<float>(screenHeight)}, 1.0f, Fade(RAYWHITE, 0.15f));

            for (const Milestone& m : milestones) {
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