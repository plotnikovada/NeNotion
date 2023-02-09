#include "CalendarPageFactory.h"
#include "../Constants/Constants.h"

void CalendarPageFactory::createTaskButton(Button& TaskButton, int x, int y, Window& window, Color color) {
    TaskButton.setAll("", 80, 40, 40, black, color, x, y, window);
}
