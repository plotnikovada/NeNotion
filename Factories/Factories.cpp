#include "Factories.h"
#include "../Constants/Constants.h"

void Factory::createBackButton(Button& BackButton, Window& window, int x, int y) {
    BackButton.setAll("Back", height_of_button_text,200, 100, white, blue, x, y, window);
}