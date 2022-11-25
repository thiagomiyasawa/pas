#include "CaixaDeTexto.h"

CaixaDeTexto::CaixaDeTexto(sf::Vector2f cord, sf::Font* fonte) {
	limite = 10;
	caixaTexto.setCharacterSize(103);
	caixaTexto.setFillColor(sf::Color(228, 58, 20));
	caixaTexto.setFont(*fonte);
	caixaTexto.setString("_");
	caixaTexto.setPosition(cord);
}

void CaixaDeTexto::inputLogic(int tecla) {
	if (tecla != DELETE_KEY && tecla != ENTER_KEY && tecla != ESCAPE_KEY) {
		texto << static_cast<char>(tecla);

	}
	else if (tecla == DELETE_KEY) {
		if (texto.str().length() > 0) {
			popBack();
		}
	}
	caixaTexto.setString(texto.str() + "_");
}

void CaixaDeTexto::popBack() {
	std::string t = texto.str();
	t.pop_back();
	texto.str("");
	texto << t;
	caixaTexto.setString(texto.str());
}
void CaixaDeTexto::drawTo(sf::RenderWindow* window) {
	window->draw(caixaTexto);
}
std::string CaixaDeTexto::getTexto() {
	return texto.str();
}
void CaixaDeTexto::escrever(sf::Event input) {
	int tecla = input.text.unicode;
	if (tecla < 128) {
		if (texto.str().length() <= limite) {
			inputLogic(tecla);
		}
		else if (texto.str().length() > limite && tecla == DELETE_KEY) {
			popBack();
		}
	}
}