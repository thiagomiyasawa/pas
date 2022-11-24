#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "CaixaDeTexto.h"
class MenuGameOver
{
private:
    int pos;
    bool pressed, theselect;


    sf::RenderWindow* window;
    sf::Font* font;
    sf::Texture* image;
    sf::Sprite* bg;
    CaixaDeTexto* caixa;


    std::vector<const char*> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<std::size_t> sizes;
protected:
    bool loop_events();
    void draw_all();
    sf::Keyboard::Key imputs();
public:
    MenuGameOver(sf::RenderWindow* janela);
    ~MenuGameOver();
    bool run_menu();
    std::string getSting();
    void set_values(int pontos);


};

