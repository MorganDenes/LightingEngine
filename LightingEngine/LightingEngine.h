#ifndef LIGHTING_LIGHTINGENGINE
#define LIGHTING_LIGHTINGENGINE
#include <SFML\/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "Entity.h"
#include "Light.h"
using namespace std;
using namespace sf;


class LightingEngine
{
public:

	LightingEngine(){ cout << "LightingEngine Created.\n"; };
	~LightingEngine();
	void Iterate();
	void setLayerCount(const int &_layer){ myLayerCount = _layer; }

	Entity* addEntity();
	Entity* getEntity(const int &_i){ return myEntities[_i]; }

	Light* addLight();
	Light* getLight(const int &_i){ return myLights[_i]; }

	void draw(RenderWindow&);
	float getDistance(const Vector2f&, const Vector2f&);
	float findAngle(const Vector2f&, const Vector2f&);

private:

	int myLayerCount = 1;
	vector<Entity*> myEntities;
	Entity* pEntity;
	vector<Light*> myLights;
	Light* pLight;
	float tempDistance;
	float tempf;
};


#endif






































