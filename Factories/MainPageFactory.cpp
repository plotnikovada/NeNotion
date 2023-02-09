#include "MainPageFactory.h"
#include "../Constants/Constants.h"

void MainPageFactory::createBoardButton(Button& BoardButton, int x, int y, Window& window) {
    BoardButton.setAll("add Board", height_of_button_text, 400, 180, white, blue, x, y, window);
}