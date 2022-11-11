#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Ente {
protected:
	RectangleShape body;
	RenderWindow* window;
	float largura;
	float altura;

public:
	Ente(float l, float a);
	~Ente();

	void setWindow(RenderWindow* w);
	void draw();
	float getLargura() const;
	float getAltura() const;
	virtual void move();
};


