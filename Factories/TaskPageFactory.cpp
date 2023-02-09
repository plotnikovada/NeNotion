#include "TaskPageFactory.h"
#include "../Constants/Constants.h"

void TaskPageFactory::createTaskButton(Button& TaskButton, int x, int y, Window& window, Color color) {
    TaskButton.setAll("", 80, 30, 30, black, color, x, y, window);
}