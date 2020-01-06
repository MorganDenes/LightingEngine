#ifndef LIGHTING_LIGHT
#define LIGHTING_LIGHT
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Light
{
public:

	Light(){ cout << "Light Created.\n"; }
	~Light(){ cout << "Light Destroyed.\n"; }

	void setCalcBool(const bool &_bool){ myCalc = _bool; }
	bool getCalcBool() const { return myCalc; }

	void setCoords(const sf::Vector2f &_coords){ myCoords = _coords; }
	sf::Vector2f getCoords() const { return myCoords; }
	void setIntensity(const float &_intensity){ myIntensity = _intensity; }
	float getIntensity() const { return myIntensity; }
	void setReach(const int &_reach){ myReach = _reach; }
	int getReach() const { return myReach; }
	void setColor(const sf::Color &_color){ myColor = _color; }
	sf::Color getColor() const { return myColor; }

	void setIntesityandDistanceReachToEntity(const float &_distance){ myIntensityandDistanceReachToEntity = (1 - _distance / myReach*myIntensity); }
	float getIntesityandDistanceReachToEntity() const { return myIntensityandDistanceReachToEntity; }
	void setEntityLightAngle(const float &_angle){ myEntityLightAngle = _angle; }
	float getEntityLightAngle() const { return myEntityLightAngle; }

	void setImpact(const Vector3i &_impact){ myImpact = _impact; }
	Vector3i getImpact() const { return myImpact; }

private:

	bool myCalc = false;
	sf::Vector2f myCoords;
	float myIntensity = 1;
	int myReach;
	sf::Color myColor;

	float myEntityLightAngle;
	float myIntensityandDistanceReachToEntity;
	Vector3i myImpact = Vector3i(0, 0, 0);
};


#endif




























