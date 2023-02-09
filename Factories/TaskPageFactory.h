#include "Factories.h"


class TaskPageFactory  : public Factory {
public:
    void createTaskButton(Button&, int x, int y, Window& window, Color color);
};