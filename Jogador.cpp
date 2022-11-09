#include "Jogador.h"
using namespace personagens;
Jogador::Jogador() : Personagem(3, 0., 280.) {
    body.setPosition(0.f, 280.f);
}

Jogador::~Jogador()
{
}

void Jogador::move() {
    velocidadeX = 0;
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        velocidadeX += 0.1f;

    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        velocidadeX += -0.1f;

    }
    body.move(Vector2f(velocidadeX, velocidadeY));
    y += velocidadeY;
    x += velocidadeX;
    gravidade();
    



}
