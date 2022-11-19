#pragma once
#include "Inimigo.h"
namespace personagens {
    //olho que voa
    class Moa :
        public Inimigo
    {
    private:
    public:
        Moa(int vidas, Vector2f p);
        ~Moa();
        void move();
    };
}//fim do namespace
