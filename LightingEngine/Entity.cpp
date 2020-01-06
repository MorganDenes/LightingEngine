#include "Entity.h"


Entity::Entity()
{
	cout << "Entity Created.\n";
	myPieceArea = Vector2i(10, 10);
	myCoords = Vector2f(0, 0);
	myArea = Vector2i(0, 0);
}


Entity::~Entity()
{
	while (!myPieces.empty())
	{
		delete myPieces[0];
		myPieces.erase(myPieces.begin() + 0);
	}
	cout << "Entity Destroyed.\n";
}


void Entity::draw(vector<Light*> &_lights, RenderWindow &_window)
{
	int LightSize = _lights.size();
	for (int k = 0; k < pieceCount; k++)
	{ 
		for (unsigned int l = 0; l < LightSize; l++)
		{
			pLight = _lights[l];
			if (pLight->getCalcBool())
			{
				tempAngle = getPiece(k)->getDegree() + pLight->getEntityLightAngle();
				if (tempAngle <= 0)
					tempAngle += 360;
				else if (tempAngle > 360)
					tempAngle -= 360;
				tempImpact = pLight->getIntesityandDistanceReachToEntity()*(abs(tempAngle - 180.0f) / 180.0f);
				pLight->setImpact(Vector3i(int(tempImpact*pLight->getColor().r), int(tempImpact*pLight->getColor().g), int(tempImpact*pLight->getColor().b)));
			}
		}
		getPiece(k)->setColor(calcImpact(_lights, getPiece(k)->getDefaultShade()));
	}

	for (unsigned int i = 0; i < pieceCount; i++)
		myPieces[i]->draw(_window);
}


void Entity::draw(RenderWindow &_window)
{
	for (unsigned int i = 0; i < pieceCount; i++)
	{
		myPieces[i]->setColor(getPiece(i)->getDefaultShade());
		myPieces[i]->draw(_window);
	}
}


void Entity::setArea(const Vector2i &_area)
{
	float i, j, tempi, tempj;
	myArea = _area;

	while (!myPieces.empty()) { delete myPieces[0]; myPieces.erase(myPieces.begin() + 0); }

	tempi = (myArea.x - 1) / 2.0f * float(myPieceArea.x);
	tempj = (myArea.y - 1) / 2.0f * float(myPieceArea.y);
	tempMaxDistance = sqrtf(powf(tempi, 2.0f) + powf(tempj, 2.0f));
	for (i = -tempi; i <= tempi; i += myPieceArea.x)
	{
		for (j = -tempj; j <= tempj; j += myPieceArea.y)
		{
			myPieces.push_back(new EntityPiece(i, j, myPieceArea));
			myPieces.back()->setRotation(myRotation);
			myPieces.back()->setCoords(myCoords);
			myPieces.back()->setDefaultSaturation(cosf((abs(i / tempi) + abs(j / tempj)) / 8.0f * PI + 0.7f) + 0.22f);
			myPieces.back()->setDefaultColor(myColor);
			myPieces.back()->setDegree(findAngle(i, j));
			myPieces.back()->setDistance( sqrtf(powf(i, 2.0f) + powf(j, 2.0f)) / tempMaxDistance );
		}
	}
}

void Entity::setPieceArea(const Vector2i &_pieceArea)
{
	myPieceArea = _pieceArea;
	setArea(myArea);
	pieceCount = getPieceCount();
}


void Entity::setCoords(const Vector2f &_coords)
{
	unsigned int i;
	myCoords = _coords;

	for (i = 0; i < pieceCount; i++)
		myPieces[i]->setCoords(_coords);
}


void Entity::setRotation(const float &_rotation)
{
	unsigned int i;
	myRotation = _rotation;

	for (i = 0; i < pieceCount; i++)
		myPieces[i]->setRotation(_rotation);
}


void Entity::iterateRotation(const float &_rotate)
{
	setRotation(myRotation + _rotate);
}


void Entity::setColor(const Color &_color)
{
	myColor = _color;

	for (unsigned int i = 0; i < pieceCount; i++)
		myPieces[i]->setDefaultColor(_color);
}


sf::Color Entity::calcImpact(const vector<Light*> &_lights, const sf::Color &_shade)
{
	int LightSize = _lights.size();
	tempColor = Vector3i(int(_shade.r), int(_shade.g), int(_shade.b));
	tempSize = 0;

	for (unsigned int i = 0; i < LightSize; i++)
	{
		pLight = _lights[i];
		if (pLight->getCalcBool())
		{
			tempColor += pLight->getImpact();
			tempSize++;
		}
	}

	tempi = tempColor.x / (tempSize + 1);
	if (tempi < _shade.r)
		tempColor.x = _shade.r;
	else
		tempColor.x = tempi;

	tempi = tempColor.y / (tempSize + 1);
	if (tempi < _shade.g)
		tempColor.y = _shade.g;
	else
		tempColor.y = tempi;

	tempi = tempColor.z / (tempSize + 1);
	if (tempi < _shade.b)
		tempColor.z = _shade.b;
	else
		tempColor.z = tempi;

	return sf::Color(tempColor.x, tempColor.y, tempColor.z );
}



float Entity::findAngle(const Vector2f &_first, const Vector2f &_second)
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


























