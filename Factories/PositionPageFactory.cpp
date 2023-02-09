#include "PositionPageFactory.h"
#include "../Constants/Constants.h"

void PositionsPageFactory::createPositionButton(Button& PositionButton, int x, int y, Window& window) {
    PositionButton.setAll("this", 80, 400, 180, white, blue, x, y, window);
}