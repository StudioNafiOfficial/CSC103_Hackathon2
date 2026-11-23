#ifndef CARD_H
#define CARD_H
#include <string>

class Card {
    public:
        float worldX;
        float worldY;
        float radius;
        std::string text; // i hear its good practice to not use namespaces in header files so im hoping it's true
        std::string description;
        bool showDescription;

        void ToggleDescription();
        void DisplayDescription(int screenWidth, int screenHeight) const;
};

#endif // CARD_H