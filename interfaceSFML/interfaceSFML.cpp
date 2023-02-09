#include <iostream>
#include <SFML/Graphics.hpp>
#include "interfaceSFML.h"
#include "../Constants/Constants.h"


Window::Window(std::string name) {
    window = sf::RenderWindow(VideoMode(height_of_window, lenght_of_window), name);
}

bool Window::isOpen() {
    return window.isOpen();
}

bool Window::pollEvent(Event event) {
    return window.pollEvent(event);
}

void Window::close() {
    window.close();
}

void Window::display() {
    window.display();
}


Screen::Screen(int width, int height, sf::Color screen_color) {
    screen = sf::RectangleShape(sf::Vector2f(width, height));
    screen.setFillColor(screen_color);
    screen.setOutlineThickness(2.f);
    screen.setPosition(50.f, 50.f);
}

void Screen::change_color(sf::Color new_color) {
    screen.setFillColor(new_color);
}

Button::Button() = default;

Screen::Screen() = default;

Text::Text() = default;

void Screen::draw_screen(sf::RenderWindow& window) {
    window.draw(screen);
};


Text::Text(std::string user_text, std::pair<int, int> coords, int size, sf::Color color, sf::RenderWindow& window) {
    sf::Font font;
    text_object = sf::Text();
    font.loadFromFile("../Fonts/font.ttf");
    text_object.setFont(font);
    text_object.setString(user_text);
    text_object.setCharacterSize(size);
    text_object.setFillColor(color);
    text_object.setPosition(coords.first, coords.second);
    window.draw(text_object);
}

void Text::change_color(sf::Color new_color) {
    text_object.setFillColor(new_color);
}

void Text::change_text(std::string new_text) {
    text_object.setString(new_text);
}


void Text::draw_text(sf::RenderWindow& window) {
    window.draw(text_object);
}

void Button::draw_button(sf::RenderWindow& window) {

}

void Button::setAll(std::string text, int heighOfText, int lenght, int height, sf::Color text_color, sf::Color button_color, int x, int y, sf::RenderWindow& window0) {
    rectangle = sf::RectangleShape(sf::Vector2f(lenght, height));
    rectangle.setFillColor(button_color);
    rectangle.setOutlineThickness(2.f);
    rectangle.setPosition(sf::Vector2f(x, y));
    sf::Font font;
    button_text = sf::Text();
    font.loadFromFile("../Fonts/font.ttf");
    button_text.setFont(font);
    button_text.setString(text);
    button_text.setCharacterSize(heighOfText);
    button_text.setFillColor(text_color);
    button_text.setPosition(x + 50, y + (height - heighOfText) / 2);
    window0.draw(rectangle);
    window0.draw(button_text);
    window = &window0;
}

void Button::setAll(int lenght, int height, sf::Color button_color, int x, int y, sf::RenderWindow& window0) {
    rectangle = sf::RectangleShape(sf::Vector2f(lenght, height));
    rectangle.setFillColor(button_color);
    rectangle.setOutlineThickness(2.f);
    rectangle.setPosition(sf::Vector2f(x, y));
    window0.draw(rectangle);
    window = &window0;
}

sf::Vector2f Button::GetCursorPosition(sf::RenderWindow &window) {
    sf::Vector2f cursorPosition;
    cursorPosition = (sf::Vector2f) sf::Mouse::getPosition(window);
    cursorPosition = window.mapPixelToCoords((sf::Vector2i) cursorPosition);
    return cursorPosition;
}

bool Button::IsInsideRect(sf::Vector2f cursorPosition, sf::RectangleShape *rectangle) {
    sf::Vector2f position = rectangle->getPosition();
    sf::Vector2f size = rectangle->getSize();
    sf::Vector2f scale = rectangle->getScale();
    size = {size.x * scale.x, size.y * scale.y};
    if (cursorPosition.x >= position.x && cursorPosition.x <= position.x + size.x &&
        cursorPosition.y >= position.y && cursorPosition.y <= position.y + size.y) {
        return 1;
    }
    return 0;
}

bool Button::is_pressed() {
    if (window == NULL) return 0;
    sf::Vector2f cursorPosition = GetCursorPosition(*window);
    sf::Vector2f scale = rectangle.getScale();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!IsInsideRect(cursorPosition, &rectangle) && !isLeftButtonPressed) {
            isInsideRect = false;
        }
        isLeftButtonPressed = true;
    } else {
        isLeftButtonPressed = false;
        isInsideRect = true;
        return 0;
    }
    if (!isInsideRect) return 0;
    return 1;
}

Image::Image(std::string image_name, std::pair<int, int> coords, std::pair<int, int> size, std::pair<int, int> picture_coords) {
    texture = sf::Texture();
    texture.loadFromFile(image_name);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(picture_coords.first, picture_coords.second, size.first, size.second));
    sprite.setPosition(coords.first, coords.second);
}

void Image::draw_image(sf::RenderWindow &window) {
    window.draw(sprite);
}