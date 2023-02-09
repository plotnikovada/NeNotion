#include "Factories.h"

class MenuPageFactory : public Factory {
public:
    void createWidgetButton(Button& button, Window& window, std::string text, int x, int y);
};