#include "Jogo.h"

Jogo::Jogo():
window(VideoMode(400, 400), "SFML works!"),
jogador1() {
    
    jogador1.setWindow(&window);
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

        jogador1.move();
        window.clear();
        jogador1.draw();
        window.display();
    }


}
