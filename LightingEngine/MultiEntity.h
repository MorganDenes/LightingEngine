#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "LightingEngine.h"
using namespace std;
using namespace sf;


class MultiEntity
{
public:

	void addEntity();
	void addLight();

	void setCoords();
	void setRotation();
	void iterateRotation();
	void setColor();

private:

	vector<Entity*> myEntities;//offset
	vector<Light*> myLights;//offset
};








































