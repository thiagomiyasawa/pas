#pragma once
#include "Inimigo.h"
namespace personagens {
    //Boss
    class Ganondorf :
        public Inimigo
    {
    private:
    public:
        Ganondorf(int vidas, float x, float y);
        ~Ganondorf();
    };
}//fim do namespace
