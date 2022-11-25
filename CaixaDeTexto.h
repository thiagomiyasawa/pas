#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<sstream>


#define ESCAPE_KEY 27
#define ENTER_KEY 13
#define DELETE_KEY 8

class CaixaDeTexto
{
private:
	sf::Text caixaTexto;
	std::ostringstream texto;
	int limite;
	void inputLogic(int tecla);
	void popBack();

public:
	CaixaDeTexto(sf::Vector2f cord, sf::Font* fonte);
	std::string getTexto();
	void drawTo(sf::RenderWindow* window);
	void escrever(sf::Event input);
};

