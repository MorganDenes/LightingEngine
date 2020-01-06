#include "LightingEngine.h"


LightingEngine::~LightingEngine()
{
	while (!myEntities.empty())
	{
		delete myEntities[0];
		myEntities.erase(myEntities.begin() + 0);
	}

	while (!myLights.empty())
	{
		delete myLights[0];
		myLights.erase(myLights.begin() + 0);
	}

	cout << "LightingEngine Destroyed.\n";
}


Entity* LightingEngine::addEntity()
{
	myEntities.push_back(new Entity);
	cout << "Entity Count at " << myEntities.size() << endl;
	return myEntities.back();
}


Light* LightingEngine::addLight()
{
	myLights.push_back(new Light);
	return myLights.back();
}


void LightingEngine::draw(RenderWindow &_window)
{
	int LightSize = myLights.size();
	int EntitySize = myEntities.size();
	for (int i = 0; i < myLayerCount; i++)
	{
		for (unsigned int j = 0; j < EntitySize; j++)
		{
			pEntity = myEntities[j];
			if (pEntity->getLayer() == i)
			{
				for (unsigned int k = 0; k < LightSize; k++)
				{
					pLight = myLights[k];
					tempDistance = getDistance(pEntity->getCoords(), pLight->getCoords());
					if (tempDistance <= pLight->getReach())
					{
						pLight->setCalcBool(true);
						pLight->setEntityLightAngle(pEntity->getRotation() - findAngle(pEntity->getCoords(), pLight->getCoords()));
						pLight->setIntesityandDistanceReachToEntity(tempDistance);
					}
					else
					{
						pLight->setCalcBool(false);
					}
				}
				pEntity->draw(myLights, _window);
			}
		}
	}
}


float LightingEngine::getDistance(const Vector2f &_first, const Vector2f &_second)
{
	return sqrtf(powf(_first.x - _second.x, 2) + powf(_first.y - _second.y, 2));
}


float LightingEngine::findAngle(const Vector2f &_first, const Vector2f &_second)
{
	if ((_second.x - _first.x) >= 0)
	{
		if (_second.y - _first.y > 0)
			return (360.0f - atanf((_second.y - _first.y) / (_second.x - _first.x))*TODEG);
		else
		{
			if (_second.y - _first.y != 0)
				return atanf((_second.y - _first.y) / (_second.x - _first.x))*-TODEG;
			return 0;
		}
	}
	else
		return (180 - atanf((_second.y - _first.y) / (_second.x - _first.x))*TODEG);
}

#ifdef DEBUG
void LightingEngine::printVariables()
{

}
#endif

































