#include "Jogo.h"

Jogo::Jogo():
window(VideoMode(400, 400), "SFML works!") {
    jogador1 = new Jogador;
    jogador1->setWindow(&window);
    fase1 = new Fase(&window, jogador1);
    LEs = fase1->getListaEntidades();

    Executar();
}

Jogo::~Jogo(){
}

void Jogo::Executar() {
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

        }

        jogador1->move();
        window.clear();
        for (int i = 0; i < LEs->getSize(); i++) {
            Ente* temp = LEs->getItem(i);
            temp->draw();
        }
        window.display();
    }


}
