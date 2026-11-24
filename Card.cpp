#include "Card.h"
#include <sstream> 
#include <string>
#include <raylib.h>
using namespace std;

void Card::ToggleDescription() {

    showDescription = !showDescription;

}

#include "card.h"
#include <algorithm>
#include <sstream>
#include <string>

void Card::DisplayDescription(int screenWidth, int screenHeight) const {
    const int boxX = 0;
    const int boxY = screenHeight / 2;
    const int boxWidth = screenWidth;
    const int boxHeight = screenHeight - boxY;

    DrawRectangle(boxX, boxY, boxWidth, boxHeight, GRAY);
    DrawLine(boxX, boxY, boxX + boxWidth, boxY, WHITE);

    const int paddingX = 40;
    const int paddingTop = 24;
    const int paddingBottom = 24;
    const int gapBetweenTextAndImage = 32;

    bool hasImage = (texture.id != 0 && texture.width > 0 && texture.height > 0);

    int maxImageWidth = hasImage ? min(360, boxWidth / 3) : 0;
    int maxImageHeight = boxHeight - paddingTop - paddingBottom;

    int textAreaWidth = hasImage
        ? (boxWidth - paddingX * 2 - maxImageWidth - gapBetweenTextAndImage) // condition ? ifTrue : ifFalse
        : (boxWidth - paddingX * 2);

    const int titleFontSize = 26;
    const int bodyFontSize = 19;
    const int lineSpacing = bodyFontSize + 6;
    const int maxBottomY = boxY + boxHeight - paddingBottom;

    int cursorX = boxX + paddingX;
    int cursorY = boxY + paddingTop;

    DrawText(text.c_str(), cursorX, cursorY, titleFontSize, BLACK);
    cursorY += titleFontSize + 14;

    istringstream words(description);
    string word;
    string currentLine;

    while (words >> word) {
        string candidate = currentLine.empty() ? word : (currentLine + " " + word);
        if (MeasureText(candidate.c_str(), bodyFontSize) > textAreaWidth && !currentLine.empty()) {
            if (cursorY + bodyFontSize > maxBottomY) {
                currentLine.clear();
                break;
            }
            DrawText(currentLine.c_str(), cursorX, cursorY, bodyFontSize, BLACK);
            cursorY += lineSpacing;
            currentLine = word;
        } else {
            currentLine = candidate;
        }
    }

    if (!currentLine.empty() && (cursorY + bodyFontSize <= maxBottomY)) {
        DrawText(currentLine.c_str(), cursorX, cursorY, bodyFontSize, BLACK);
    }

    if (hasImage) {
        float scaleX = static_cast<float>(maxImageWidth) / static_cast<float>(texture.width);
        float scaleY = static_cast<float>(maxImageHeight) / static_cast<float>(texture.height);
        float scale = min(scaleX, scaleY);

        float drawW = texture.width * scale;
        float drawH = texture.height * scale;
        float imgX = static_cast<float>(boxX + boxWidth - paddingX) - drawW;
        float imgY = static_cast<float>(boxY + paddingTop) + (maxImageHeight - drawH) * 0.5f;

        Rectangle src = { 0.0f, 0.0f, static_cast<float>(texture.width), static_cast<float>(texture.height) };
        Rectangle destination = { imgX, imgY, drawW, drawH };
        DrawTexturePro(texture, src, destination, { 0.0f, 0.0f }, 0.0f, WHITE);
    }
}