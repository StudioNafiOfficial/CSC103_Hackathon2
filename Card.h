#ifndef CARD_H
#define CARD_H
#include <string>

class Card {
    public:
        float worldX;
        float worldY;
        float radius;
        std::string text;
        std::string description;
        bool showDescription;

        void ToggleDescription();
        void DisplayDescription(int screenWidth, int screenHeight) const;
};

#endif // CARD_H