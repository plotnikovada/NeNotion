#include <iostream>
#include <SFML/Graphics.hpp>
#include "interfaceSFML/interfaceSFML.h"
#include "Windows/Windows.h"
#include "Boards/Board.h"
#include "Constants/Constants.h"

void open_main_window(std::vector<Board>& list_of_boards);
void work_with_board_window(int number_of_page, Board& board, std::vector<Board>& list_of_boards);
void work_with_calendar_window(int number_of_page, Board& board, std::vector<Board>& list_of_boards);
void work_with_position_window(std::string page_name, int number_of_page, Board& board, std::vector<Board>& list_of_boards);
void work_with_picture_window(int x, int y, int number_of_page, Board& board, std::vector<Board>& list_of_boards);
void work_with_task_window(int number_of_page, Board& board, std::vector<Board>& list_of_boards);
void work_with_color_window(int number_of_page, Board& board, std::vector<Board>& list_of_boards);

void work_with_menu_window(int number_of_page, Board& board, std::vector<Board>& list_of_boards) {
    Window window("Menu");
    while (window.isOpen()) {
        MenuPage page(window);
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (page.back_button.is_pressed()) {
                window.close();
                work_with_board_window(number_of_page, board, list_of_boards);
            }
            if (page.calendar_button.is_pressed()) {
                window.close();
                work_with_calendar_window(number_of_page, board, list_of_boards);
            }
            if (page.picture_button.is_pressed()) {
                window.close();
                work_with_position_window("picture", number_of_page, board, list_of_boards);
            }
            if (page.text_button.is_pressed()) {
                board.add_text = true;
                window.close();
                work_with_board_window(number_of_page, board, list_of_boards);
            }
            if (page.task_button.is_pressed()) {
                window.close();
                work_with_task_window(number_of_page, board, list_of_boards);
            }
            if (page.color_button.is_pressed()) {
                window.close();
                work_with_color_window(number_of_page, board, list_of_boards);
            }
        }

        window.display();
    }
}

void work_with_board_window(int i, Board& board, std::vector<Board>& list_of_boards) {
    Window window("Board");
    while (window.isOpen()) {
        BoardPage page(window, i, board.color_ind);
        Event event;
        for (int j = 0; j < board.list_of_images.size(); ++j) {
            board.list_of_images[j].draw_image(window);
        }
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (page.menu_button.is_pressed()) {
                window.close();
                work_with_menu_window(i, board, list_of_boards);
            }

            if (event.type == Event::TextEntered and board.add_text) {
                if (board.text_height > 10) {
                    continue;
                }
                if (board.text_len > 80) {
                    board.user_text += L'\n' ;
                    board.text_len= 1;
                    board.text_height += 1;
                }
                switch (event.text.unicode)
                {

                    case 0xD:
                        board.user_text += L'\n' ;
                        board.text_len = 1;
                        break ;
                    case 0x8:
                        if ( !board.user_text.isEmpty())
                            board.user_text.erase(board.user_text.getSize()-1) ; board.text_len = (board.text_len + 79) % 81;
                        break ;
                    default :
                    {
                        board.user_text += static_cast<wchar_t>(event.text.unicode) ;
                        board.text_len += 1;
                    }
                }
            }
            if (page.back_button.is_pressed()) {
                window.close();
                open_main_window(list_of_boards);
            }
        }
        Text added(board.user_text, {300, 265}, 20, {0, 0, 0}, window);

        window.display();
    }
}

void work_with_position_window(std::string page_name, int number_of_page, Board& board, std::vector<Board>& list_of_boards) {
    Window window("Positions");
    while (window.isOpen()) {
        PositionsPage page(window);
        Event event;while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            for (int i = 0; i < 9; ++i) {
                if (page.list_of_buttons[i].is_pressed()) {
                    window.close();
                    if (page_name == "picture") {
                        work_with_picture_window(210 + (i / 3) * 500, 100 + (i % 3) * 250, number_of_page, board, list_of_boards);
                    }
                }
            }
        }
        window.display();

    }
}

void work_with_calendar_window(int number_of_page, Board& board, std::vector<Board>& list_of_boards) {
    Window window("Calendar");
    String task_text = board.calendar_text[board.calendar_task];
    int number_of_tasks = board.calendar_text_len[board.calendar_task].first;
    int task_len = board.calendar_text_len[board.calendar_task].second;

    while (window.isOpen()) {
        CalendarPage page(window);
        Event event;while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (page.back_button.is_pressed()) {
                window.close();
                work_with_menu_window(number_of_page, board, list_of_boards);
            }
            if (event.type == Event::TextEntered) {
                if (number_of_tasks > 10) {
                    continue;
                }
                switch (event.text.unicode)
                {

                    case 0xD:
                        task_text += L'\n' ;
                        task_len = 1;
                        number_of_tasks += 1;
                        break ;
                    case 0x8:
                        if ( !task_text.isEmpty()) {
                            task_text.erase(board.task_text.getSize()-1) ;
                            task_len = (board.task_len + 39) % 41;
                            if (task_len < 2) {
                                number_of_tasks -= 1;
                            }
                        }

                        break ;

                    default :
                    {
                        if (task_len > 40) {
                            continue;
                        }
                        task_text += static_cast<wchar_t>(event.text.unicode) ;
                        task_len += 1;
                    }
                }
            }
            board.calendar_text[board.calendar_task] = task_text;
            for (int i = 0; i < 14; ++i) {
                if (page.task_buttons[i].is_pressed()) {

                    board.calendar_text_len[i].first = number_of_tasks;
                    board.calendar_text_len[i].second = task_len;
                    board.calendar_task = i;
                    task_text = board.calendar_text[i];
                }
            }
        }
        for (int i = 0; i < 14; ++i) {
            Text added(board.calendar_text[i], {160 + (i % 7) * 215, 370 + (i / 7) * 210}, 20, {0, 0, 0}, window);
        }

        window.display();

    }
}

void work_with_picture_window(int x, int y, int number_of_page, Board& board, std::vector<Board>& list_of_boards) {
    Window window("Picture");
    while (window.isOpen()) {
        PicturePage page(window);
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (page.back_button.is_pressed()) {
                window.close();
                work_with_position_window("picture", number_of_page, board, list_of_boards);
            }
            if (page.picture_1.is_pressed()) {
                Image image("../picture_files/allpictures.png", {x, y}, {350, 250}, {0, 150});
                board.list_of_images.push_back(image);
                window.close();
                work_with_board_window(number_of_page, board, list_of_boards);
            }
            if (page.picture_2.is_pressed()) {
                Image image("../picture_files/allpictures.png", {x, y}, {190, 250}, {350, 150});
                board.list_of_images.push_back(image);
                window.close();
                work_with_board_window(number_of_page, board, list_of_boards);
            }
            if (page.picture_3.is_pressed()) {
                Image image("../picture_files/allpictures.png", {x, y}, {280, 200}, {550, 150});
                board.list_of_images.push_back(image);
                window.close();
                work_with_board_window(number_of_page, board, list_of_boards);
            }
            if (page.picture_4.is_pressed()) {
                Image image("../picture_files/allpictures.png", {x, y}, {270, 200}, {830, 150});
                board.list_of_images.push_back(image);
                window.close();
                work_with_board_window(number_of_page, board, list_of_boards);
            }
            if (page.picture_5.is_pressed()) {
                Image image("../picture_files/allpictures.png", {x, y}, {270, 250}, {1110, 150});
                board.list_of_images.push_back(image);
                window.close();
                work_with_board_window(number_of_page, board, list_of_boards);
            }
            if (page.picture_6.is_pressed()) {
                Image image("../picture_files/allpictures.png", {x, y}, {180, 250}, {160, 410});
                board.list_of_images.push_back(image);
                window.close();
                work_with_board_window(number_of_page, board, list_of_boards);
            }
            if (page.picture_7.is_pressed()) {
                Image image("../picture_files/allpictures.png", {x, y}, {230, 250}, {340, 410});
                board.list_of_images.push_back(image);
                window.close();
                work_with_board_window(number_of_page, board, list_of_boards);
            }
            if (page.picture_8.is_pressed()) {
                Image image("../picture_files/allpictures.png", {x, y}, {150, 300}, {580, 380});
                board.list_of_images.push_back(image);
                window.close();
                work_with_board_window(number_of_page, board, list_of_boards);
            }
            if (page.picture_9.is_pressed()) {
                Image image("../picture_files/allpictures.png", {x, y}, {200, 270}, {750, 370});
                board.list_of_images.push_back(image);
                window.close();
                work_with_board_window(number_of_page, board, list_of_boards);
            }
        }
        window.display();

    }
}

void open_main_window(std::vector<Board>& list_of_boards) {
    Window window("Main");
    while (window.isOpen()) {
        MainPage page(window);
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            for (int i = 0; i < 9; ++i) {
                if (page.list_of_buttons[i].is_pressed()) {
                    window.close();
                    work_with_board_window((i % 3) * 3 + (i / 3), list_of_boards[(i % 3) * 3 + (i / 3)], list_of_boards);
                }
            }
        }
        window.display();
    }
}

void work_with_color_window(int number_of_page, Board& board, std::vector<Board>& list_of_boards) {
    Window window("Colors");
    while (window.isOpen()) {
        ColorPage page(window);
        Event event;while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (page.back_button.is_pressed()) {
                window.close();
                work_with_menu_window(number_of_page, board, list_of_boards);
            }
            for (int i = 0; i < 9; ++i) {
                if (page.list_of_buttons[i].is_pressed()) {
                    board.color_ind = i;
                    window.close();
                    work_with_board_window(number_of_page, board, list_of_boards);
                }
            }

        }
        window.display();

    }
}

void work_with_task_window(int number_of_page, Board& board, std::vector<Board>& list_of_boards) {
    Window window("To do list");
    while (window.isOpen()) {
        TaskPage page(window, board.task_done);
        Event event;while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (page.back_button.is_pressed()) {
                window.close();
                work_with_menu_window(number_of_page, board, list_of_boards);
            }
            if (event.type == Event::TextEntered) {
                if (board.number_of_tasks > 10) {
                    continue;
                }
                switch (event.text.unicode)
                {

                    case 0xD:
                        board.task_text += L'\n' ;
                        board.task_len = 1;
                        board.number_of_tasks += 1;
                        break ;
                    case 0x8:
                        if ( !board.task_text.isEmpty()) {
                            board.task_text.erase(board.task_text.getSize()-1) ;
                            board.task_len = (board.task_len + 39) % 41;
                            if (board.task_len < 2) {
                                board.number_of_tasks -= 1;
                            }
                        }

                        break ;

                    default :
                    {
                        if (board.task_len > 40) {
                            continue;
                        }
                        board.task_text += static_cast<wchar_t>(event.text.unicode) ;
                        board.task_len += 1;
                    }
                }
            }
            for (int i = 0; i < 10; ++i) {
                if (page.list_of_buttons[i].is_pressed()) {
                    board.task_done[i] = not board.task_done[i];
                }
            }


        }
        Text added(board.task_text, {250, 183}, 42, {0, 0, 0}, window);
        window.display();

    }
}

int main() {
    std::vector<Board> list_of_boards(9);
    open_main_window(list_of_boards);
}
