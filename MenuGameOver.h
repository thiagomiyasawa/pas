#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "CaixaDeTexto.h"
class MenuGameOver
{
private:
    



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
public:
    MenuGameOver(sf::RenderWindow* janela);
    ~MenuGameOver();
    bool run_menu();
    std::string getSting();
    void set_values(int pontos);


};

