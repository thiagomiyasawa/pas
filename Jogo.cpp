#include "Jogo.h"

Jogo::Jogo() {
    grafico = GerenciadorGrafico::getInstance();
    link1 = new Jogador(5, Vector2f(0., 280.));
    link1->setWindow(grafico->getWindow());
    menu = new Menu(grafico->getWindow());
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
        fase = new PrimeiraFase(grafico->getWindow(), link1);
    //}
    
    estado = 0;
    time = 0;
    LEs = fase->getListaEntidades();

    Executar();
}

Jogo::~Jogo(){
    delete grafico;
    delete link1;
    delete link2;
    delete LEs;
    delete fase;
    delete menu;
    menu = nullptr;
}

void Jogo::Executar() {
    while (grafico->isWindowOpen() && link1->getVivo()  /* && link2->getVivo() */ ) {
        if (estado == 0) {
            menu->run_menu(&estado);
            if (estado == 2) {
                link2 = new Jogador(5, Vector2f(0., 280.));
                link2->setWindow(grafico->getWindow());
                estado = 1;
            }
        }
        if (estado == 1) {
            grafico->Executar();
            link1->move();
            for (int i = 0; i < LEs->getSize(); i++) {
                Entidade* temp = LEs->getItem(i);
                if (temp != nullptr)
                    grafico->render(temp->getBody());
            }

            fase->executar();
            grafico->display();
            time = grafico->getDt();
        }
        
    }


}
void Jogo::setEstado(int valor) {
    estado = valor;
}
