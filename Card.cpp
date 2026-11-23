#include "Card.h"
#include <raylib.h>


void Card::ToggleDescription() {

    showDescription = !showDescription;

}

void Card::DisplayDescription(int screenWidth, int screenHeight) const {
    const int boxX = 0;
    const int boxY = screenHeight / 2;
    const int boxWidth = screenWidth;
    const int boxHeight = screenHeight / 2;

    DrawRectangle(boxX, boxY, boxWidth, boxHeight, GRAY);

    // border along the top edge of the panel
    DrawLine(boxX, boxY, boxX + boxWidth, boxY, WHITE);

    const int titleFontSize = 28;
    const int padding = 32;
    const int bodyFontSize = 20;

    DrawText(text.c_str(), boxX + padding, boxY + padding, titleFontSize, BLACK);
    DrawText(
        description.c_str(),
        boxX + padding,
        boxY + padding + titleFontSize + 16,
        bodyFontSize,
        BLACK
    );
}
