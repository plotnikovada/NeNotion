#include "Factories.h"

class PicturePageFactory : public Factory {
public:
    void createPictureButton(Button&, int x, int y, int size_x, int size_y, Window& window);
};