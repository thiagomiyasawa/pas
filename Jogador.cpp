#include "Jogador.h"
using namespace personagens;
Jogador::Jogador(int vidas, float x, float y, int id) : Personagem(vidas, x, y, id) {
    body->setPosition(0.f, 280.f);
    body->setFillColor(Color::Color(58,238,39));
    velocidadeX = 0;
    imune = 0;
    atacando = 0;
}

Jogador::~Jogador()
{
}

void Jogador::move() {
    velocidadeX*=0.995f;
    if (imune) {
        imune--;
        if (!imune) {
            body->setFillColor(Color::Color(58, 238, 39));
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        if (velocidadeX < 0.1f)
            velocidadeX += 0.03f;

    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        if (velocidadeX > -0.1f)
            velocidadeX += -0.03f;

    }
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        if (noChao)
            velocidadeY += -0.7f;

    }
    y += velocidadeY;
    x += velocidadeX;
    body->setPosition(x,y);
    if(!noChao)
        gravidade();
    
    noChao = false;
    id = 1;


}


int Jogador::getImune() {
    return imune;
}

void Jogador::setImune() {
    imune = 3000;
}
