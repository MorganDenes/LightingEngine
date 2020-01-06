#ifndef LIGHTING_ENTITY
#define LIGHTING_ENTITY
#include <SFML\Graphics.hpp>
#include <SFML\System\Vector2.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include "EntityPiece.h"
#include "Light.h"
using namespace std;
using namespace sf;


class Entity
{
public:
	Entity();
	~Entity();

	void draw(vector<Light*>&, RenderWindow&);
	void draw(RenderWindow&);
	void setLayer(const int &_layer){ myLayer = _layer; }
	int getLayer(){ return myLayer; }

	void setCoords(const float &_x, const float &_y){ setCoords(Vector2f(_x, _y)); }
	void setCoords(const Vector2f&);
	Vector2f getCoords(){ return myCoords; }
	void setRotation(const float&);
	void iterateRotation(const float&);
	float getRotation(){ return myRotation; }
	void setColor(const Color&);
	sf::Color getColor(){ return myColor; }

	void setArea(const int &_x, const int &_y){ setArea(Vector2i(_x, _y)); }
	void setArea(const Vector2i&);
	Vector2i getArea(){ return myArea; }
	
	EntityPiece* getPiece(const int&_i){ return myPieces[_i]; }
	void setPieceArea(const int &_x, const int &_y){ setPieceArea(Vector2i(_x, _y)); }
	void setPieceArea(const Vector2i&);
	Vector2i getPieceArea(){ return myPieceArea; }
	int getPieceCount(){ return myArea.x*myArea.y; }

private:

	sf::Color calcImpact(const vector<Light*>&, const sf::Color&);
	float findAngle(const float &_x, const float &_y){ return findAngle(Vector2f(0, 0),Vector2f(_x, _y)); }
	float findAngle(const Vector2f&, const Vector2f&);

	int myLayer = 0;

	Vector2f myCoords;
	float myRotation;
	Color myColor;

	Vector2i myArea;

	vector<EntityPiece*> myPieces;
	Vector2i myPieceArea;
	int pieceCount = 0;

	Light* pLight;
	float tempMaxDistance;
	float tempAngle;
	float tempImpact;
	Vector3i tempColor;

	int tempi;
	int tempSize;
};

#endif

































