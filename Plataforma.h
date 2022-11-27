#pragma once
#include "Obstaculo.h"

namespace entidades {
    namespace obstaculos {
        class Plataforma :
            public Obstaculo
        {
        private:
        public:
            Plataforma(Vector2f coordenada, Vector2f tamanho);
            ~Plataforma();
            void move();
            void gravar();
            static Lista<Plataforma>* recuperar();
        };
    }//fim do namespace
}//fim do namespace