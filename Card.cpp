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
    // bottom-half panel bounds in screen coordinates
    const int boxX = 0;
    const int boxY = screenHeight / 2;
    const int boxWidth = screenWidth;
    const int boxHeight = screenHeight - boxY; // avoids rounding loss on odd heights

    // draw panel background and a crisp top divider line
    DrawRectangle(boxX, boxY, boxWidth, boxHeight, GRAY);
    DrawLine(boxX, boxY, boxX + boxWidth, boxY, WHITE);

    // layout spacing constants (in pixels)
    const int paddingX = 40;
    const int paddingTop = 24;
    const int paddingBottom = 24;
    const int gapBetweenTextAndImage = 32;

    // confirm the texture was uploaded and has valid dimensions
    bool hasImage = (texture.id != 0 && texture.width > 0 && texture.height > 0);

    // cap the image slot width to 360px or 1/3 of the panel width, whichever is smaller
    int maxImageWidth = hasImage ? min(360, boxWidth / 3) : 0;
    int maxImageHeight = boxHeight - paddingTop - paddingBottom;

    // give text the full horizontal width when no image is present; otherwise
    // reserve space on the right for the image plus a gap between text and image
    int textAreaWidth = hasImage
        ? (boxWidth - paddingX * 2 - maxImageWidth - gapBetweenTextAndImage)
        : (boxWidth - paddingX * 2);

    const int titleFontSize = 26;
    const int bodyFontSize = 19;
    const int lineSpacing = bodyFontSize + 6;
    const int maxBottomY = boxY + boxHeight - paddingBottom; // Lower vertical limit for text

    // start text cursor at the top-left of the inner padded area
    int cursorX = boxX + paddingX;
    int cursorY = boxY + paddingTop;

    // draw card title and advance cursor below it
    DrawText(text.c_str(), cursorX, cursorY, titleFontSize, BLACK);
    cursorY += titleFontSize + 14;

    // stream words from 'description'
    istringstream words(description);
    string word;
    string currentLine;

    while (words >> word) {
        // test adding the next word to the current line
        string candidate = currentLine.empty() ? word : (currentLine + " " + word);

        // if the candidate line exceeds available width and already has text, wrap
        if (MeasureText(candidate.c_str(), bodyFontSize) > textAreaWidth && !currentLine.empty()) {
            // stop before drawing if the next line would pass the bottom margin
            if (cursorY + bodyFontSize > maxBottomY) {
                currentLine.clear();
                break;
            }
            DrawText(currentLine.c_str(), cursorX, cursorY, bodyFontSize, BLACK);
            cursorY += lineSpacing;
            currentLine = word; // start the new line with the word that didn't fit
        } else {
            currentLine = candidate;
        }
    }

    // flush any remaining partial line at the end of the description if it fits
    if (!currentLine.empty() && (cursorY + bodyFontSize <= maxBottomY)) {
        DrawText(currentLine.c_str(), cursorX, cursorY, bodyFontSize, BLACK);
    }

    if (hasImage) {
        // compute uniform scale so the image fits inside (maxImageWidth x maxImageHeight)
        // without stretching or distorting its original aspect ratio
        float scaleX = static_cast<float>(maxImageWidth) / static_cast<float>(texture.width);
        float scaleY = static_cast<float>(maxImageHeight) / static_cast<float>(texture.height);
        float scale = min(scaleX, scaleY);

        float drawW = texture.width * scale;
        float drawH = texture.height * scale;

        // align image flush with the right padding and vertically centered in the panel
        float imgX = static_cast<float>(boxX + boxWidth - paddingX) - drawW;
        float imgY = static_cast<float>(boxY + paddingTop) + (maxImageHeight - drawH) * 0.5f;

        // 'src' selects the entire source texture; 'destination' places and scales it on screen
        Rectangle src = { 0.0f, 0.0f, static_cast<float>(texture.width), static_cast<float>(texture.height) };
        Rectangle destination = { imgX, imgY, drawW, drawH };
        DrawTexturePro(texture, src, destination, { 0.0f, 0.0f }, 0.0f, WHITE);
    }
}