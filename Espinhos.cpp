#include "Espinhos.h"

Espinhos::Espinhos(Vector2f coordenada, Vector2f tamanho) :
	Obstaculo(coordenada, tamanho, 32)
{
	textura.loadFromFile("sprites/espinhos.png");
	body->setTexture(&textura);
	dano = 1;
}

Espinhos::~Espinhos()
{
}

int Espinhos::getDano() {
	return dano;
}

void Espinhos::gravar() {
    ofstream gravador("save/espinhos.dat", ios::app);

    if (!gravador)
    {
        return;
    }
    gravador << posicao.x << ' '
             << posicao.y <<endl;
    gravador.close();
}