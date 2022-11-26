#pragma once
#include <SFML/Graphics.hpp>
#include <queue>

typedef struct {
	std::string  nome;
	int pontos;
}Colocado;

class Jogo;
class Ranking{
private:
	std::queue<Colocado> rank;
	sf::RenderWindow* window;
	sf::Font* font;
	sf::Texture* image;
	sf::Sprite* bg;
	std::vector<sf::Vector2f> coordsNomes;
	std::vector<sf::Vector2f> coordsPontos;
	std::vector<sf::Text> texts;

	Jogo* jogo;
public:
	Ranking(sf::RenderWindow* janela, Jogo* game);
	~Ranking();
	void addColocado(std::string nome);
	void addColocado(std::string nome, int  pontuacao);
	void mostrarRank();
	void drawAll();
};

