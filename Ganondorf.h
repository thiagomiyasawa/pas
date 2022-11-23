#pragma once
#include "Inimigo.h"
namespace personagens {
    //Boss
    class Ganondorf :
        public Inimigo
    {
    private:
        int irritado;
        sf::Color corOriginal;
    public:
        Ganondorf(int vidas, Vector2f p);
        ~Ganondorf();
        void move();

        void gravar();
        static Ganondorf* recuperar();
    };
}//fim do namespace
