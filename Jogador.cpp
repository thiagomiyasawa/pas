#include "Jogador.h"
using namespace personagens;
Jogador::Jogador(int vidas, Vector2f p, bool link1) : Personagem(vidas, Vector2f(40.,80.), p , 11, 1) {
    body->setPosition(p);
    if (link1) {
        textura.loadFromFile("sprites/Link1Idle.png");
    }
    else {
        textura.loadFromFile("sprites/Link2Idle.png");
    }
    body->setTexture(&textura);
    velocidade.x = 0;
    imune = 0;
    atacando = 0;
    tiro = new Projetil;
}

Jogador::~Jogador() {
    delete tiro;
}

void Jogador::move() {
    velocidade.x*=0.9f;
    if (imune) {
        imune--;
        if (!imune) {
            body->setFillColor(Color::Color(200, 238, 39));
        }
    }
    if (atacando>-2000) {
        atacando--;
        if (!atacando) {
            body->setFillColor(Color::Color(200, 238, 39));
        }
    }
    if (pulo > 1000000) {
        pulo = 10000;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        direcao = 1;
        if (velocidade.x < 0.1f)
            velocidade.x += 0.03f;

    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        direcao = -1;
        if (velocidade.x > -0.1f)
            velocidade.x += -0.03f;

    }
    if (Keyboard::isKeyPressed(Keyboard::Up) && pulo>160 && noChao) {
            velocidade.y += -0.7f;
            pulo = 0;

    }
    if (Keyboard::isKeyPressed(Keyboard::Z)) {
        if (atacando<=-1000) {
            atacando = 1000;
            body->setFillColor(Color(155, 157, 131));
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::X)) {
        if (!tiro->getAtivo()) {
            atira();
        }
    }
    posicao.y += velocidade.y;
    posicao.x += velocidade.x;
    body->setPosition(posicao);
    if(!noChao)
        gravidade();
    if (!vivo) {
        body->setFillColor(Color(200, 114, 185));
    }
    noChao = false;
    id = 1;


}
int Jogador::getAtacando() {
    return atacando;
}

int Jogador::getImune() {
    return imune;
}

int Jogador::getDirecao() {
    return direcao;
}

Projetil* Jogador::getTiro() {
    return tiro;
}

void Jogador::setImune() {
    imune = 3000;
}

void Jogador::atira() {
    if (direcao > 0) {
        tiro->setX(posicao.x + tamanho.x + 2);
        tiro->setY(posicao.y + 20);
        tiro->setVelocidadeX(1.f);
    }
    else {
        tiro->setX(posicao.x - (2+tiro->getLargura()));
        tiro->setY(posicao.y + 20);
        tiro->setVelocidadeX(-1.f);
    }
    tiro->setVelocidadeY(0);
    tiro->setAtivo(true);
}

void Jogador::setNoChao(bool estado) {
    noChao = estado;
    pulo++;
}