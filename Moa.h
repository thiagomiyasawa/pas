#pragma once
#include "Inimigo.h"
namespace personagens {
    //olho que voa
    class Moa :
        public Inimigo
    {
    private:
            int invisivel;
    public:
        Moa(int vidas, Vector2f p);
        ~Moa();
        void move();
        
        void gravar();
        static Lista<Moa>* recuperar();
    };
}//fim do namespace
