#include "Jogo.h"

Jogo::Jogo() {
    grafico = GerenciadorGrafico::getInstance();
    link1 = new Jogador(5, Vector2f(0., 280.),11);
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
    //}
    
    estado = 0;
    time = 0;
    menu->set_values(1);
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
        int output=0;
        if (estado == 0) {
            output = menu->run_menu();
            if (output == 1)/*iniciar*/ {
                menu->set_values(2);
                estado = 1;
            }
            else if (output ==2)/*RANKING*/ {
                
            }
        }
        else if (estado==1) {
            output = menu->run_menu();
            if (output == 2)/*2jogadores*/ {
                link2 = new Jogador(5, Vector2f(0., 280.), 12);
                link2->setWindow(grafico->getWindow());
            }
            if (output != 0) {
                menu->set_values(3);
                estado = 2;
            }
        }
        else if (estado==2) {
            output = menu->run_menu();
            if (output == 1)/*fase 1*/ {
                fase = new PrimeiraFase(grafico->getWindow(), link1, link2);
                LEs = fase->getListaEntidades();
            }
            else if (output == 2)/*fase 2*/ {
                fase = new SegundaFase(grafico->getWindow(), link1, link2);
                LEs = fase->getListaEntidades();
            }
            if (output != 0) {
                estado = 3;
            }
        }
        else if (estado == 3) {
            grafico->Executar();
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
