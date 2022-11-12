#include "GerenciadorGrafico.h"

#include <cstring>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720

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
    window(new RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Zelda", Style::Titlebar | Style::Close)),
    view(Vector2f(WIDTH / 2, HEIGHT / 2), Vector2f(WIDTH, HEIGHT)),
    texturesMap(),
    fontsMap() { }

GerenciadorGrafico::~GerenciadorGrafico() {
    map<const char*, Texture*>::iterator it;

    for (it = texturesMap.begin(); it != texturesMap.end(); ++it) {
        delete (it->second);
    }

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
    view.setSize(size.x, size.y);
    window->setView(view);
}

    /* Returns the window size. */
Vector2u GerenciadorGrafico::getWindowSize() const {
    return Vector2u(window->getSize().x, window->getSize().y);
}

    /* Returns the top left position of screen. */
Vector2f GerenciadorGrafico::getTopLeftPosition() const {
    return Vector2f(window->getView().getCenter().x - window->getSize().x / 2, window->getView().getCenter().y - window->getSize().y / 2);
}

    /* Changes the view position. */
void GerenciadorGrafico::centerView(Vector2f pos) {
    view.setCenter(Vector2f(pos.x, pos.y));
    window->setView(view);
}

    /* Returns a texture to be used by an entity. */
Texture* GerenciadorGrafico::loadTexture(const char* path) {
    /* Tries to find an existing texture linked by the path to it. */
    map<const char*, Texture*>::iterator it = texturesMap.begin();
    while (it != texturesMap.end()) {
        if (!strcmp(it->first, path))
            return it->second;
        it++;
    }

    /* If not found, must load it. */
    Texture* tex = new Texture();

    if (!tex->loadFromFile(path)) {
        cout << "ERROR loading file " << path << endl;
        exit(1);
    }

    texturesMap.insert(pair<const char*, Texture*>(path, tex));

    return tex;
}

/* Returns a font pointer to be used by texts. */
Font* GerenciadorGrafico::loadFont(const char* path) {
    /* Tries to find an existing font linked by the path to it */
    map<const char*, Font*>::iterator it = fontsMap.begin();
    while (it != fontsMap.end()) {
        if (!strcmp(it->first, path))
            return it->second;
        it++;
    }

    /* If not found, must load it. */
    Font* font = new Font();

    if (!font->loadFromFile(path)) {
        cout << "ERROR loading file " << path << endl;
        exit(1);
    }

    fontsMap.insert(pair<const char*, Font*>(path, font));

    return font;
}

float GerenciadorGrafico::updateDeltaTime() {   
    dt = clock.getElapsedTime().asSeconds();
    return 0.0f;
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



}
