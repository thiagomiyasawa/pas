#include "Jogador.h"
#include "Lista.h"
using namespace personagens;
Jogador::Jogador(int vidas, Vector2f p, int ID) : Personagem(vidas, Vector2f(40.,80.), p , ID, 1) {
    body->setPosition(p);
    if (id==11) {
        textura.loadFromFile("sprites/Link1Idle.png");
    }
    else if(id==12) {
        textura.loadFromFile("sprites/Link2Idle.png");
    }
    else {
        printf("valor invalido");
    }
    body->setTexture(&textura);
    velocidade.x = 0;
    imune = 0;
    atacando = 0;
    pulo = 160;
}

Jogador::~Jogador() {
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
    if (id == 11) {
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
        if (Keyboard::isKeyPressed(Keyboard::Up) && pulo > 160 && noChao) {
            velocidade.y += -0.7f;
            pulo = 0;

        }
        if (Keyboard::isKeyPressed(Keyboard::M)) {
            if (atacando <= -1000) {
                atacando = 1000;
                body->setFillColor(Color(155, 157, 131));
            }
        }
    }
    if (id == 12) {
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            direcao = 1;
            if (velocidade.x < 0.1f)
                velocidade.x += 0.03f;

        }
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            direcao = -1;
            if (velocidade.x > -0.1f)
                velocidade.x += -0.03f;

        }
        if (Keyboard::isKeyPressed(Keyboard::W) && pulo > 160 && noChao) {
            velocidade.y += -0.7f;
            pulo = 0;

        }
        if (Keyboard::isKeyPressed(Keyboard::B)) {
            if (atacando <= -1000) {
                atacando = 1000;
                body->setFillColor(Color(155, 157, 131));
            }
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


void Jogador::setImune() {
    imune = 3000;
}

void Jogador::setNoChao(bool estado) {
    noChao = estado;
    pulo++;
}

void Jogador::gravar() {
    ofstream gravador("save/jogador.dat", ios::app);
    
    if (!gravador)
    {
        return;
    }
    gravador << numVidas << ' '
             << posicao.x << ' '
             << posicao.y << ' '
             << velocidade.x << ' '
             << velocidade.y << ' '
             << id <<  endl;
    gravador.close();
}

Lista<Jogador>* Jogador::recuperar() {
    ifstream recuperador("save/jogador.dat", ios::in);
    Lista<Jogador>* l = new Lista<Jogador>;
    int vidas;
    Vector2f p;
    Vector2f v;
    int ID;
    if (!recuperador) {
        return nullptr;
    }
    while (!recuperador.eof()) {
        recuperador >> vidas >> p.x >> p.y >> v.x >> v.y >> ID;

        Jogador* temp = new Jogador(vidas, p, ID);
        temp->setVelocidade(v);
        l->push(temp);
    }
    recuperador.close();
    return l;


}

