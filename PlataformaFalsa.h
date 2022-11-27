#pragma once
#include "Obstaculo.h"

namespace entidades {
    namespace obstaculos {
        class PlataformaFalsa :
            public Obstaculo
        {
        private:
            int ativo;
        public:
            PlataformaFalsa(Vector2f coordenada, Vector2f tamanho);
            ~PlataformaFalsa();
            void move();

            void setAtivo(int a);
            int getAtivo();
            void reduzAtivo();

            void gravar();
            static Lista<PlataformaFalsa>* recuperar();
        };
    }//fim do namespace
}//fim do namespace