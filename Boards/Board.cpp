#ifndef BOARD_H_
#define BOARD_H_
#include "Board.h"

Board::Board() {
    list_of_images = std::vector<Image>();
    user_text = "";
    add_text = false;
    text_len = 0;
    text_height = 0;
    task_text = "";
    task_len = 0;
    number_of_tasks = 0;
    task_done = std::vector<bool>(10, false);
    calendar_text = std::vector<String>(14, "");
    calendar_text_len = std::vector<std::pair<int, int>>(14, {0, 0});
    calendar_task = 0;
}

#endif