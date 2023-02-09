#include "Factories.h"

class PositionsPageFactory : public Factory {
public:
    void createPositionButton(Button&, int x, int y, Window& window);
};