#include "Factories.h"

class ColorPageFactory : public Factory {
public:
    void createColorButton(Button&, int x, int y, Window& window, Color color);
};