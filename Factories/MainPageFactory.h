#include "Factories.h"

class MainPageFactory : public Factory {

public:
    MainPageFactory() = default;

    void createBoardButton(Button&, int x, int y, Window& window);
};