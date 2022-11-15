#include "Jogo.h"

Jogo::Jogo() {
    grafico = GerenciadorGrafico::getInstance();
    link1 = new Jogador(5,0.,280.);
    link1->setWindow(grafico->getWindow());
    fase1 = new Fase(grafico->getWindow(), link1);
    LEs = fase1->getListaEntidades();

    Executar();
}

Jogo::~Jogo(){
}

void Jogo::Executar() {
    while (grafico->isWindowOpen()) {
        grafico->Executar();
        link1->move();
        for (int i = 0; i < LEs->getSize(); i++) {
            Entidade* temp = LEs->getItem(i);
            grafico->render(temp->getBody());
        }

        fase1->executar();
        grafico->display();
    }


}
float GerenciadorGrafico::dt(0.);