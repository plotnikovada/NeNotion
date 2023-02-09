#ifndef WINDOWS_H_
#define WINDOWS_H_
#include "Windows.h"
#include "../Boards/Board.h"
#include "../Constants/Constants.h"


MainPage::MainPage(Window& window) {
    page = Screen(height_of_screen, lenght_of_screen, white);
    page.draw_screen(window);
    Text text("CHOOSE BOARD", {coor_x_main_text, coor_y_main_text}, height_of_main_text, black, window);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            list_of_buttons.push_back(Button());
            factory.createBoardButton(list_of_buttons.back(), 210 + i * 500, 150 + j * 250, window);
        }
    }
}

void MainPage::render(Window &window) {
    page = Screen(height_of_screen, lenght_of_screen, white);
    page.draw_screen(window);
}

BoardPage::BoardPage(Window &window, int board_number, int color_ind) {
    Colors colors;
    page = Screen(height_of_screen, lenght_of_screen, colors.board_colors[color_ind]);
    page.draw_screen(window);
    Text text("BOARD #" + std::to_string(board_number), {coor_x_main_text, coor_y_main_text}, 60, black, window);
    menu_button = Button();
    factory.createMenuButton(menu_button, window);
    back_button = Button();
    factory.createBackButton(back_button, window, 100, 700);
}

MenuPage::MenuPage(Window &window) {
    page = Screen(height_of_screen, lenght_of_screen, white);
    page.draw_screen(window);
    Text text("CHOOSE WIDGET", {coor_x_main_text, coor_y_main_text}, height_of_main_text, black, window);
    color_button = Button();
    picture_button = Button();
    text_button = Button();
    task_button = Button();
    calendar_button = Button();
    back_button = Button();
    factory.createWidgetButton(color_button, window, "Choose color", 150, 200);
    factory.createWidgetButton(picture_button, window, "Choose Picture", 150, 330);
    factory.createWidgetButton(text_button, window, "Add text", 150, 460);
    factory.createWidgetButton(task_button, window, "To do list", 150, 590);
    factory.createWidgetButton(calendar_button, window, "Go to calendar", 150, 720);
    factory.createBackButton(back_button, window, 150, 80);
}

PositionsPage::PositionsPage(Window &window) {
    page = Screen(height_of_screen, lenght_of_screen, white);
    page.draw_screen(window);
    Text text("CHOOSE POSITION", {coor_x_main_text, coor_y_main_text}, height_of_main_text, black, window);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            list_of_buttons.push_back(Button());
            factory.createPositionButton(list_of_buttons.back(), 210 + i * 500, 150 + j * 250, window);
        }
    }
}

CalendarPage::CalendarPage(Window &window) {
    page = Screen(height_of_screen, lenght_of_screen, white);
    page.draw_screen(window);
    Text text("CALENDAR", {coor_x_main_text, coor_y_main_text}, height_of_main_text, black, window);
    back_button = Button();
    factory.createBackButton(back_button, window, 1400, 80);
    Image image("../picture_files/calendar.png", {130, 250}, {1600, 470}, {50, 150});
    image.draw_image(window);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 7; ++j) {
            task_buttons.push_back(Button());
            factory.createTaskButton(task_buttons.back(), 160 + j * 215, 330 + i * 210, window, black);
        }
    }
}

PicturePage::PicturePage(Window &window) {
    page = Screen(height_of_screen, lenght_of_screen, white);
    page.draw_screen(window);
    Text text("CHOOSE A PICTURE", {500, coor_y_main_text}, height_of_main_text, black, window);
    back_button = Button();
    factory.createBackButton(back_button, window, 1400, 80);
    picture_1 = Button();
    factory.createPictureButton(picture_1, 350, 250, 130, 250, window);
    picture_2 = Button();
    factory.createPictureButton(picture_2, 190, 250, 500, 250, window);
    picture_3 = Button();
    factory.createPictureButton(picture_3, 280, 200, 700, 250, window);
    picture_4 = Button();
    factory.createPictureButton(picture_4, 270, 200, 1000, 250, window);
    picture_5 = Button();
    factory.createPictureButton(picture_5, 1300, 250, 270, 250, window);
    picture_6 = Button();
    factory.createPictureButton(picture_6, 180, 250, 400, 500, window);
    picture_7 = Button();
    factory.createPictureButton(picture_7, 230, 250, 620, 500, window);
    picture_8 = Button();
    factory.createPictureButton(picture_8, 150, 300, 920, 500, window);
    picture_9 = Button();
    factory.createPictureButton(picture_9, 200, 300, 1200, 500, window);
    Image image1("../picture_files/allpictures.png", {130, 250}, {350, 250}, {0, 150});
    image1.draw_image(window);
    Image image2("../picture_files/allpictures.png", {500, 250}, {190, 250}, {350, 150});
    image2.draw_image(window);
    Image image3("../picture_files/allpictures.png", {700, 250}, {280, 200}, {550, 150});
    image3.draw_image(window);
    Image image4("../picture_files/allpictures.png", {1000, 250}, {270, 200}, {830, 150});
    image4.draw_image(window);
    Image image5("../picture_files/allpictures.png", {1300, 250}, {270, 250}, {1110, 150});
    image5.draw_image(window);
    Image image6("../picture_files/allpictures.png", {400, 500}, {180, 250}, {160, 410});
    image6.draw_image(window);
    Image image7("../picture_files/allpictures.png", {620, 500}, {230, 250}, {340, 410});
    image7.draw_image(window);
    Image image8("../picture_files/allpictures.png", {920, 500}, {150, 300}, {580, 380});
    image8.draw_image(window);
    Image image9("../picture_files/allpictures.png", {1200, 500}, {200, 300}, {750, 370});
    image9.draw_image(window);
}

ColorPage::ColorPage(Window &window) {
    Colors colors;
    page = Screen(height_of_screen, lenght_of_screen, white);
    page.draw_screen(window);
    Text text("CHOOSE COLOR", {coor_x_main_text, coor_y_main_text}, height_of_main_text, black, window);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            list_of_buttons.push_back(Button());
            factory.createColorButton(list_of_buttons.back(), 210 + i * 500, 150 + j * 250, window, colors.board_colors[i * 3 + j]);
        }
    }
}

TaskPage::TaskPage(Window &window, std::vector<bool>& task_done) {
    back_button = Button();
    page = Screen(height_of_screen, lenght_of_screen, white);
    page.draw_screen(window);
    Text text("TO DO LIST", {coor_x_main_text, coor_y_main_text}, height_of_main_text, black, window);
    for (int i = 0; i < 10; ++i) {
        list_of_buttons.push_back(Button());
        sf::Color button_color;
        if (task_done[i]) {
            button_color = green;
        } else {
            button_color = black;
        }
        factory.createTaskButton(list_of_buttons.back(), 200, 200 + 50 * i, window, button_color);
    }
    factory.createBackButton(back_button, window, 1400, 80);
}

#endif