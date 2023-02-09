#include "ColorPageFactory.h"
#include "../Constants/Constants.h"

void ColorPageFactory::createColorButton(Button& ColorButton, int x, int y, Window& window, Color color) {
    ColorButton.setAll("this", 80, 400, 180, white, color, x, y, window);
}