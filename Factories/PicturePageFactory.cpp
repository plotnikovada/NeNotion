#include "PicturePageFactory.h"
#include "../Constants/Constants.h"

void PicturePageFactory::createPictureButton(Button & PictureButton, int x, int y, int size_x, int size_y, Window &window) {
    PictureButton.setAll(size_x, size_y, white, x, y, window);
}