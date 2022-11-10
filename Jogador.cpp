#include "Jogador.h"
using namespace personagens;
Jogador::Jogador(int vidas, float x, float y, int id) : Personagem(vidas, x, y, id) {
    body.setPosition(0.f, 280.f);
    velocidadeX = 0;
}

Jogador::~Jogador()
{
}

void Jogador::move() {
    velocidadeX*=0.995f;
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        if(velocidadeX<0.1f)
            velocidadeX += 0.03f;

    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        if (velocidadeX > -0.1f)
        velocidadeX += -0.03f;

    }
    
    body.move(Vector2f(velocidadeX, velocidadeY));
    y += velocidadeY;
    x += velocidadeX;
    gravidade();
    



}

void Jogador::colidir(int ID) {

}
