#include "Jogador.h"
using namespace personagens;
Jogador::Jogador() {
    body.setPosition(0.f, 280.f);
    x = 0.;
    y = 280.;
    NoChao = true;
    velocidadey = 0;
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
    if (Keyboard::isKeyPressed(Keyboard::Down)) {

    }
    body.move(Vector2f(0.f, velocidadey));
    y += velocidadey;
    if (y >= 280) {
        NoChao = true;
        velocidadey = 0;
    }
    if (NoChao) {
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            velocidadey = -2;
            NoChao = false;
        }
    }
    else {
        velocidadey += 0.01f;
    }



}
