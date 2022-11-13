#pragma once
#include "Inimigo.h"
namespace personagens {
    //olho que voa
    class Moa :
        public Inimigo
    {
    private:
    public:
        Moa(int vidas, float x, float y);
        ~Moa();
    };
}//fim do namespace
