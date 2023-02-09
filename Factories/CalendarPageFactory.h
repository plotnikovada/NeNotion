#include "Factories.h"

class CalendarPageFactory : public Factory {
public:
    void createTaskButton(Button& TaskButton, int x, int y, Window& window, Color color);
};
