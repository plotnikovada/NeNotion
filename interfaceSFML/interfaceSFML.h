#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class Window {
private:
    sf::RenderWindow& window;
public:
    Window(std::string name);
    bool isOpen();
    bool pollEvent(Event event);
    void close();
    void display();
};



class Button {
private:
    sf::RenderWindow* window = 0;
    sf::RectangleShape rectangle;
    sf::Text button_text;
    bool isLeftButtonPressed = false;
    bool isInsideRect = true;
public:
    Button();
    bool IsInsideRect(sf::Vector2f cursorPosition, sf::RectangleShape *rectangle);
    sf::Vector2f GetCursorPosition(sf::RenderWindow &window);
    void setAll(std::string text, int heighOfText, int lenght, int height, sf::Color text_color, sf::Color button_color, int x, int y, sf::RenderWindow& window);
    void setAll(int lenght, int height, sf::Color button_color, int x, int y, sf::RenderWindow& window);
    void draw_button(sf::RenderWindow& window);
    bool is_pressed();
};

class Text {
private:
    sf::Text text_object;
public:
    Text();
    Text(std::string user_text, std::pair<int, int> coords, int size, sf::Color color, sf::RenderWindow& window);
    void change_color(sf::Color new_color);
    void change_text(std::string new_text);
    void draw_text(sf::RenderWindow& window);
};

class Screen {
private:
    sf::RectangleShape screen;
public:
    Screen();
    Screen(int width, int height, sf::Color color);
    void change_color(sf::Color new_color);
    void draw_screen(sf::RenderWindow& window);
};


class Image {
private:
    sf::Image image;
    sf::Sprite sprite;
    sf::Texture texture;
public:
    Image();
    Image(std::string image_name, std::pair<int, int> coords, std::pair<int, int> size, std::pair<int, int> picture_coord);
    void draw_image(sf::RenderWindow& window);
};


//using Window = sf::RenderWindow;
using Event = sf::Event;
using VideoMode = sf::VideoMode;
using String = sf::String;
using Color = sf::Color;



