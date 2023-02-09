#include "MenuPageFactory.h"
#include "../Constants/Constants.h"

void MenuPageFactory::createWidgetButton(Button& button, Window& window, std::string button_text, int x, int y) {
    button.setAll(button_text, height_of_button_text, 1300, 80, white, blue, x, y, window);
}