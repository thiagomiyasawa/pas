#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu {
    int pos;
    bool pressed, theselect;

    sf::RenderWindow* window;
    sf::RectangleShape* winclose;
    sf::Font* font;
    sf::Texture* image;
    sf::Sprite* bg;


    std::vector<const char*> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<std::size_t> sizes;

protected:
    int loop_events();
    void draw_all();

public:
    Menu(sf::RenderWindow* janela);
    ~Menu();
    void set_values(int tipo);
    int run_menu();
};

