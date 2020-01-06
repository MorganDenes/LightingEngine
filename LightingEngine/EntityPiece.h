#ifndef LIGHTING_ENTITYPIECE
#define LIGHTING_ENTITYPIECE
#define PI 3.14159265f
#define TODEG (180.0f/PI)
#define TORAD (PI/180.0f)
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using namespace sf;


class EntityPiece
{
private:
	EntityPiece(const float &_xOffset, const float &_yOffset, Vector2i &_area);
	~EntityPiece(){ }

	void draw(RenderWindow&);

	void setCoords(const Vector2f &_coords) { myPiece.setPosition(_coords); }
	void setRotation(const float &_rotation){ myPiece.setRotation(_rotation); }
	void setColor(const sf::Color &_color){ myPiece.setFillColor(_color); }
	void setDefaultColor(const sf::Color &_color);
	void setDefaultSaturation(const float&);
	sf::Color getDefaultShade() const { return myDefaultShade; }

	void setDegree(const float &_degree){ myDegree = _degree; }
	float getDegree() const { return myDegree; }
	void setDistance(const float &_distance){ myDistance = _distance; }
	float getDistance() const { return myDistance; }
	void setArea(const Vector2f &_area){ myPiece.setSize(_area); }

	RectangleShape myPiece;

	sf::Color myDefaultColor;
	float myDefaultSaturation;
	sf::Color myDefaultShade;

	float myDegree;
	float myDistance;

	friend class Entity;
};


#endif

































