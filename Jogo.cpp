#include "Jogo.h"

Jogo::Jogo() {
    grafico = GerenciadorGrafico::getInstance();
    link1 = new Jogador(5, Vector2f(0., 280.));
    link1->setWindow(grafico->getWindow());
    /*cout << "quantos jogadadores ?" << endl;
    int n;
    cin >> n;
    getchar();
    if (n == 2) {
        link2 = new Jogador(5., 0., 280., false);
        link2->setWindow(grafico->getWindow());
        fase1 = new Fase(grafico->getWindow(), link1, link2);
        
    }
    else {*/
        link2 = nullptr;
        fase1 = new Fase(grafico->getWindow(), link1);
    //}
    
    LEs = fase1->getListaEntidades();

    Executar();
}

Jogo::~Jogo(){
    delete grafico;
    delete link1;
    delete link2;
    delete LEs;
    delete fase1;
}

void Jogo::Executar() {
    while (grafico->isWindowOpen() /*link1->getVivo()  && link2->getVivo()*/) {
        grafico->Executar();
        link1->move();
        for (int i = 0; i < LEs->getSize(); i++) {
            Entidade* temp = LEs->getItem(i);
            if(temp!=nullptr)
                 grafico->render(temp->getBody());
        }

        fase1->executar();
        grafico->display();
    }


}
float GerenciadorGrafico::dt(0.);