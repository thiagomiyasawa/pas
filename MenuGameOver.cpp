#include "MenuGameOver.h"


MenuGameOver::MenuGameOver(sf::RenderWindow* janela) {
    
    window = janela;
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();
    caixa = new CaixaDeTexto({ 455., 453. }, font);

    window->setPosition(sf::Vector2i(0, 0));

    font->loadFromFile("./times-new-roman-bold-italic.ttf");
    image->loadFromFile("./menu.png");

    bg->setTexture(*image);

}

MenuGameOver::~MenuGameOver() {
    window = nullptr;
    delete font;
    delete image;
    delete bg;
}

void MenuGameOver::set_values(int pontos) {
    window->setPosition(sf::Vector2i(0, 0));

    font->loadFromFile("./times-new-roman-bold-italic.ttf");
    image->loadFromFile("./menu.png");

    bg->setTexture(*image);
    sf::Text pontuacao;

    options = { "Game Over", "Pontos"};
    texts.resize(2);
    coords = { {477,55},{455,247} };
    sizes = { 124,103,103, };

    for (std::size_t i{}; i < texts.size(); ++i) {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setFillColor(sf::Color(228, 58, 20));
        texts[i].setPosition(coords[i]);
    }

    pontuacao.setFont(*font);
    pontuacao.setString(std::to_string(pontos));
    pontuacao.setCharacterSize(103);
    pontuacao.setFillColor(sf::Color(228, 58, 20));
    pontuacao.setPosition(455, 347);
    texts.push_back(pontuacao);

}

bool MenuGameOver::loop_events() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        else if (event.type == sf::Event::TextEntered) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                return true;
            }
            caixa->escrever(event);
            return false;
        }
    }
}

void MenuGameOver::draw_all() {
    window->clear();
    window->draw(*bg);
    caixa->drawTo(window);
    for (auto t : texts) {
        window->draw(t);
    }
    window->display();
}

 bool MenuGameOver::run_menu() {
        bool enter =loop_events();
        draw_all();
        return enter;
}

std::string MenuGameOver::getSting() {
    return caixa->getTexto();
}