#ifndef CARD_H
#define CARD_H

#include "raylib.h"
#include <string>

class Card {
    public:
        float worldX;
        float worldY;
        float radius;
        std::string text;
        std::string description;
        std::string imageLink;
        bool showDescription;
        Texture2D texture{};

        void ToggleDescription();
        void DisplayDescription(int screenWidth, int screenHeight) const;
};

#endif // CARD_H