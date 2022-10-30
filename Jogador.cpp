#include "Jogador.h"
using namespace personagens;
Jogador::Jogador() {
}

Jogador::~Jogador()
{
}

void Jogador::move() {
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        body.move(Vector2f(0.1f, 0.f));

    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        body.move(Vector2f(-0.1f, 0.f));

    }
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        body.move(Vector2f(0.f, -0.1f));

    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        body.move(Vector2f(0.f, 0.1f));

    }


}
