#include <iostream>
#include "../Factories/Factories.h"
#include "../Factories/BoardPageFactory.h"
#include "../Factories/MainPageFactory.h"
#include "../Factories/MenuPageFactory.h"
#include "../Factories/CalendarPageFactory.h"
#include "../Factories/ColorPageFactory.h"
#include "../Factories/PicturePageFactory.h"
#include "../Factories/PositionPageFactory.h"
#include "../Factories/TaskPageFactory.h"

class Page {
public:
    Screen page;
};

class MainPage : Page {
private:
    MainPageFactory factory;
public:
    std::vector<Button> list_of_buttons;
    MainPage(Window& window);
    void render(Window& window);
};

class BoardPage : Page{
private:
    BoardPageFactory factory;
public:

    std::vector<Image> list_of_widgets;
    Button menu_button;
    Button back_button;
    BoardPage(Window& window, int number_of_page, int color_ind);
};

class MenuPage: Page {
private:
    MenuPageFactory factory;
public:
    Button color_button;
    Button picture_button;
    Button text_button;
    Button task_button;
    Button calendar_button;
    Button back_button;
    MenuPage(Window& window);
    void render(Window& window);
};

class PositionsPage: Page {
private:
    PositionsPageFactory factory;
public:
    std::vector<Button> list_of_buttons;
    PositionsPage(Window& window);
    void render(Window& window);
};

class CalendarPage: Page {
private:
    std::vector<Text> list_of_text;
    CalendarPageFactory factory;
public:
    Button back_button;
    std::vector<Button> task_buttons;
    CalendarPage(Window& window);
    void render(Window& window);

};

class PicturePage: Page {
private:
    PicturePageFactory factory;
public:
    Button back_button;
    Button picture_1;
    Button picture_2;
    Button picture_3;
    Button picture_4;
    Button picture_5;
    Button picture_6;
    Button picture_7;
    Button picture_8;
    Button picture_9;
    PicturePage(Window& window);
    void render(Window& window);

};

class ColorPage: Page {
private:
    ColorPageFactory factory;
public:
    Button back_button;
    Button add_text_button;
    std::vector<Button> list_of_buttons;
    ColorPage(Window& window);
    void render(Window& window);
};

class TaskPage: Page {
private:
    TaskPageFactory factory;
public:
    Button back_button;
    std::vector<Button> list_of_buttons;
    TaskPage(Window& window, std::vector<bool>& task_done);
    void render(Window& window);

};