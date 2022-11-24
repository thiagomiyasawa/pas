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

        void setIrritado(int i);

        void gravar();
        static Lista<Ganondorf>* recuperar();
    };
}//fim do namespace
