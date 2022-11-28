#include "GerenciadorGrafico.h"

#include <cstring>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720

using namespace gerenciadores;

/* Singleton design pattern - Only one instance will be created */
GerenciadorGrafico* GerenciadorGrafico::instance = nullptr;

/* Returns a pointer to the Graphics. */
GerenciadorGrafico* GerenciadorGrafico::getInstance() {
    if (instance == nullptr) {
        instance = new GerenciadorGrafico();
    }
    return instance;
}

GerenciadorGrafico::GerenciadorGrafico() :
    window(new RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Zelda", Style::Titlebar | Style::Close)){ 
}

GerenciadorGrafico::~GerenciadorGrafico() {
    delete (window);
}

/* Give a pointer to a body and it will be drawn to the screen. */
void GerenciadorGrafico::render(RectangleShape* body) {
    window->draw(*body);
}

/* Give a pointer to a Text and it will be drawn to the screen */
void GerenciadorGrafico::render(sf::Text* text) {
    window->draw(*text);
}

/* Display everything that was drawn. */
void GerenciadorGrafico::display() {
    if (isWindowOpen())
        window->display();
}

/* Clear the window to re-display stuff. */
void GerenciadorGrafico::clear() {
    if (isWindowOpen())
        window->clear();
}

/* Returns if the window is open. */
bool GerenciadorGrafico::isWindowOpen() const {
    return window->isOpen();
}

    /* CAUTION: Call the close window function - SFML window will close. */
void GerenciadorGrafico::closeWindow() {
    window->close();
}

    /* Sets window size to its parameters */
void GerenciadorGrafico::setWindowSize(Vector2u size) {
    window->setSize(sf::Vector2u(size.x, size.y));
}

    /* Returns the window size. */
Vector2u GerenciadorGrafico::getWindowSize() const {
    return Vector2u(window->getSize().x, window->getSize().y);
}

    /* Returns the top left position of screen. */
Vector2f GerenciadorGrafico::getTopLeftPosition() const {
    return Vector2f(window->getView().getCenter().x - window->getSize().x / 2, window->getView().getCenter().y - window->getSize().y / 2);
}



float GerenciadorGrafico::updateDeltaTime() {   
    dt = clock.getElapsedTime().asSeconds();
    return 0.0f;
}

float GerenciadorGrafico::getDt()
{
    return dt;
}

RenderWindow* GerenciadorGrafico::getWindow() const {
    return window;
}

void GerenciadorGrafico::Executar() {
    Event event;

    while (window->pollEvent(event)) {
        if (event.type == Event::Closed)
            closeWindow();
    }
     clear();

     updateDeltaTime();

}
float GerenciadorGrafico::dt(0.);