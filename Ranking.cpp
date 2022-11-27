#include "Ranking.h"
#include "Jogo.h"
Ranking::Ranking(sf::RenderWindow* janela, Jogo* game){
    window = janela;
    jogo = game;
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    window->setPosition(sf::Vector2i(0, 0));

    font->loadFromFile("./times-new-roman-bold-italic.ttf");
    image->loadFromFile("./menu.png");

    bg->setTexture(*image);
    coordsNomes = { {535,136},{535,186},{535,236},{535,286}, {535,336} };
    coordsPontos = { {895,136},{895,186},{895,236},{895,286}, {895,336} };
    //recupera();
    Colocado teste;
    teste.nome = "a";
    teste.pontos = -1;
    for (int i = 0; i < 5; i++) {
        rank.push(teste);
    }

}

Ranking::~Ranking() {
    
    window = nullptr;
    jogo = nullptr;
    delete font;
    delete image;
    delete bg;
}

void Ranking::addColocado(std::string nome) {
    Colocado jogador;
    jogador.nome = nome;
    jogador.pontos = jogo->getPontos();
    if (rank.size() < 5) {
        rank.push(jogador);
    }
    else {
        
        bool posicionado = false;
        Colocado aux;
        for (int i = 0; i < 5; i++) {
            aux = rank.front();
            rank.pop();
            if (!posicionado) {
                if (aux.pontos > jogador.pontos) {
                    rank.push(aux);
                }
                else if (aux.pontos < jogador.pontos) {
                    rank.push(jogador);
                    if (i < 4) {
                        rank.push(aux);
                        posicionado = true;
                    }

                }
                else if (i < 4) {
                    rank.push(aux);
                    rank.push(jogador);
                    posicionado = true;
                }
            }
            else if(i < 4) {
                rank.push(aux);
            }
        }
    }
}

void Ranking::addColocado(std::string nome, int pontuacao) {
    Colocado jogador;
    jogador.nome = nome;
    jogador.pontos = pontuacao;
    if (rank.size() < 5) {
        rank.push(jogador);
    }
    else {

        bool posicionado = false;
        Colocado aux;
        for (int i = 0; i < 5; i++) {
            aux = rank.front();
            rank.pop();
            if (!posicionado) {
                if (aux.pontos > jogador.pontos) {
                    rank.push(aux);
                    posicionado = true;
                }
                else if (aux.pontos < jogador.pontos) {
                    rank.push(jogador);
                    if (i < 4) {
                        rank.push(aux);
                        posicionado = true;
                    }

                }
                else if (i < 4) {
                    rank.push(aux);
                    rank.push(jogador);
                    posicionado = true;
                }
            }
            else if(i<4) {
                rank.push(aux);
            }
        }
    }
}

void Ranking::mostrarRank() {
    texts.resize(10);
    Colocado aux;
    int i;
    for (i = 0; i < 5 && !rank.empty(); i++) {
        aux = rank.front();
        texts[i].setFont(*font);
        texts[i].setString(aux.nome);
        texts[i].setCharacterSize(52);
        texts[i].setFillColor(sf::Color(228, 58, 20));
        texts[i].setPosition(coordsNomes[i]);

        texts[i + 5].setFont(*font);
        texts[i + 5].setString(std::to_string(aux.pontos));
        texts[i + 5].setCharacterSize(52);
        texts[i + 5].setFillColor(sf::Color(228, 58, 20));
        texts[i + 5].setPosition(coordsPontos[i]);
        rank.pop();
        rank.push(aux);

    }
    sf::Text texto;
    texto.setFont(*font);
    texto.setString("esc para sair");
    texto.setCharacterSize(90);
    texto.setFillColor(sf::Color(228, 58, 20));
    texto.setPosition({568,513});
    texts.push_back(texto);
    bool ativo = true;
    while (ativo) {
        drawAll();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            ativo = false;
        }
    }
}

void Ranking::drawAll() {
    window->clear();
    window->draw(*bg);
    for (auto t : texts) {
        window->draw(t);
    }
    window->display();
}

void Ranking::salva() {
    ofstream gravador("save/batata.dat", ios::out);

    if (!gravador)
    {
        return;
    }
    while (!rank.empty()) {
        Colocado temp = rank.front();
        rank.pop();
        gravador << endl << temp.nome << ' ' << temp.pontos;
    }

    gravador.close();
}

void Ranking::recupera() {
    ifstream recuperador("save/ranking.dat", ios::in);
    string nome;
    int pontos;
    if (!recuperador) {
        return;
    }

    while (!recuperador.eof()) {
        recuperador >> nome >> pontos;
        addColocado(nome, pontos);
    }
    
    recuperador.close();
}
