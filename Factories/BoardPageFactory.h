#include "Factories.h"

class BoardPageFactory : public Factory {
public:
    BoardPageFactory() = default;
    void createMenuButton(Button&, Window& window);
};