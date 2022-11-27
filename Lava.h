#pragma once
#include "Obstaculo.h"

namespace entidades {
    namespace obstaculos {
        class Lava :
            public Obstaculo
        {
        private:
            int dano;
        public:
            Lava(Vector2f coordenada, Vector2f tamanho);
            ~Lava();
            int getDano();
            void move();

            void gravar();
            static Lista<Lava>* recuperar();
        };
    }//fim do namespace
}//fim do namespace