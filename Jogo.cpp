#include "Jogo.h"

Jogo::Jogo() {
    grafico = GerenciadorGrafico::getInstance();
    link1 = new Jogador(5, Vector2f(0., 280.),11);
    link1->setWindow(grafico->getWindow());
    menu = new Menu(grafico->getWindow());
    fim = false;
   

    link2 = nullptr;
    
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
    while (grafico->isWindowOpen() ) {
        while ((link1->getVivo() || (link2 != nullptr && link2->getVivo())) && !fim) {
            int output = 0;
            if (estado == 0) {
                output = menu->run_menu();
                if (output == 1)/*iniciar*/ {
                    menu->set_values(2);
                    estado = 1;
                }
                else if (output == 2)/*continuar*/ {
                    continuar();
                    estado = 3;
                }
                else if (output == 3)/*RANKING*/ {

                }
            }
            else if (estado == 1) {
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
            else if (estado == 2) {
                output = menu->run_menu();
                if (output == 1)/*fase 1*/ {
                    time = grafico->getDt();
                    fase = new PrimeiraFase(grafico->getWindow(), link1, link2,time);
                    LEs = fase->getListaEntidades();
                    numFase = 1;
                }
                else if (output == 2)/*fase 2*/ {
                    time = grafico->getDt();
                    fase = new SegundaFase(grafico->getWindow(), link1, link2, time);
                    LEs = fase->getListaEntidades();
                    numFase = 2;
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
                if (fase->getTempo(time) >= fase->getTempoRestante()) {
                    if (numFase == 1) {
                        trocaFase();
                    }
                    else {
                        fim = true;
                    }
                }
            }
            else if (estado == 4) {
                output = menu->run_menu();
                if (output == 1)/*resume*/ {
                    fase->salvar(pontuacao, time);
                    estado = 3;
                }
                else if (output == 2)/*menu*/ {
                    resetarJogo();
                }
                else if (output == 3)/*salvar e sair*/ {
                    fase->salvar(pontuacao, time);
                    grafico->closeWindow();
                    
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                estado = 4;
                menu->set_values(4);
            }
        }
        resetarJogo();
    }
}

void Jogo::addPontos(int valor) {
    pontuacao += valor;
    printf("%d\n", pontuacao);
}

void Jogo::resetarJogo() {
    delete link1;
    if(link2!= nullptr)
        delete link2;
    delete fase;
    LEs = nullptr;

    link1 = new Jogador(5, Vector2f(0., 280.), 11);
    link1->setWindow(grafico->getWindow());
    link2 = nullptr;
    pontuacao = 0;
    estado = 0;
    time = 0;
    menu->set_values(1);
}

void Jogo::continuar() {
    ifstream recuperador("save/fase.dat", ios::in);
    int qualFase;
    int pontos;
    float tempo;

    recuperador >> qualFase >> pontos >> tempo;

    pontuacao = pontos;

    if (qualFase == 1) {
        fase = PrimeiraFase::recuperar(grafico->getWindow());
    }
    else if (qualFase == 2) {
        fase = SegundaFase::recuperar(grafico->getWindow());
    }

    fase->setTempoRestante(tempo);
}

void Jogo::trocaFase() {
    delete fase;
    fase = new SegundaFase(grafico->getWindow(), link1, link2, grafico->getDt());
    time = grafico->getDt();
    LEs = fase->getListaEntidades();
    numFase = 2;
    link1->setX(0.);
    link1->setY(280.);
    link1->setVelocidadeX(0);
    link1->setVelocidadeY(0);
    if (link2 != nullptr) {
        link2->setX(0.);
        link2->setY(280.);
        link2->setVelocidadeX(0);
        link2->setVelocidadeY(0);
    }
}

int Jogo::pontuacao(0);