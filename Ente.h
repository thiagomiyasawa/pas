#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Ente {
protected:
	RectangleShape body;
	RenderWindow* window;

public:
	Ente();
	~Ente();

	void setWindow(RenderWindow* w);
	void draw();
};


