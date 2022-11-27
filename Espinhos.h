#pragma once
#include "Obstaculo.h"

namespace entidades {
    namespace obstaculos {
        class Espinhos :
            public Obstaculo
        {
        private:
            int dano;
        public:
            Espinhos(Vector2f coordenada, Vector2f tamanho);
            ~Espinhos();
            int getDano();
            void move();

            void gravar();
            static Lista<Espinhos>* recuperar();
        };
    }//fim do namespace
}//fim do namespace
