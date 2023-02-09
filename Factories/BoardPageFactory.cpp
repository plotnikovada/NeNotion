#include "BoardPageFactory.h"
#include "../Constants/Constants.h"

void BoardPageFactory::createMenuButton(Button& MenuButton, Window& window) {
    MenuButton.setAll("Menu", height_of_button_text,200, 100, white, blue, 1500, 700, window);
}