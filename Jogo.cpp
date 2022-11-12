#include "Jogo.h"

Jogo::Jogo() {
    grafico = GerenciadorGrafico::getInstance();
    jogador1 = new Jogador(5,0.,280.);
    jogador1->setWindow(grafico->getWindow());
    fase1 = new Fase(grafico->getWindow(), jogador1);
    LEs = fase1->getListaEntidades();

    Executar();
}

Jogo::~Jogo(){
}

void Jogo::Executar() {
    while (grafico->isWindowOpen()) {
        grafico->Executar();
        jogador1->move();
        for (int i = 0; i < LEs->getSize(); i++) {
            Ente* temp = LEs->getItem(i);
            grafico->render(temp->getBody());
        }

        fase1->executar();
        grafico->display();
    }


}
float GerenciadorGrafico::dt(0.);