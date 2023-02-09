#include <iostream>
#include "../interfaceSFML/interfaceSFML.h"

class Board {
public:
    Board();
    std::vector<Image> list_of_images;
    String user_text;
    size_t text_len;
    size_t text_height;
    bool add_text;
    int color_ind;
    String task_text;
    int task_len;
    int number_of_tasks;
    std::vector<bool> task_done;
    std::vector<String> calendar_text;
    std::vector<std::pair<int, int>> calendar_text_len;
    int calendar_task;

};

struct Colors : public Board{
    std::vector<sf::Color> board_colors = {
            sf::Color::White,
            sf::Color(160, 200, 100),
            sf::Color(170, 90, 240),
            sf::Color(150, 190, 230),
            sf::Color(205, 120, 190),
            sf::Color(250, 200, 200),
            sf::Color(130, 150, 120),
            sf::Color(220, 220, 100),
            sf::Color(140, 170, 200)
    };

};