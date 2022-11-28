#pragma once
//codigo adaptado do monitor Matheus burda
#include "SFML/Graphics.hpp"
#include "Fase.h"
#include <iostream>
#include <map>

using namespace sf;
using namespace std;

namespace gerenciadores {
    class GerenciadorGrafico {
    private:
        RenderWindow* window;
        Clock clock;
        static float dt;

        /* Singleton design pattern */
        static GerenciadorGrafico* instance;
        GerenciadorGrafico();
    public:
        ~GerenciadorGrafico();
        static GerenciadorGrafico* getInstance();

        void render(sf::RectangleShape* body);

        void render(sf::Text* text);

        void display();

        void clear();

        bool isWindowOpen() const;

        void closeWindow();

        void setWindowSize(Vector2u size);

        Vector2u getWindowSize() const;

        Vector2f getTopLeftPosition() const;

        float updateDeltaTime();

        float getDt();

        RenderWindow* getWindow() const;

        void Executar();

    };
}//fim do namespace

