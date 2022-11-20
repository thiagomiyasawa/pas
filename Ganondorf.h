#pragma once
#include "Inimigo.h"
namespace personagens {
    //Boss
    class Ganondorf :
        public Inimigo
    {
    private:
    public:
        Ganondorf(int vidas, Vector2f p);
        ~Ganondorf();
    };
}//fim do namespace
