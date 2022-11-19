#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Ente {
protected:
	RectangleShape* body;
	RenderWindow* window;
	Vector2f tamanho;
public:
	Ente(Vector2f t);
	~Ente();

	void setWindow(RenderWindow* w);
	void draw();
	float getLargura() const;
	float getAltura() const;
	RectangleShape* getBody() const;
};


