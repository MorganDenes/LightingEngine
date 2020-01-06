#include "EntityPiece.h"


EntityPiece::EntityPiece(const float &_xOffset, const float &_yOffset, Vector2i &_area)
{
	myPiece.setSize(Vector2<float>(_area));
	myPiece.setOrigin(-_xOffset + _area.x / 2, -_yOffset + _area.y / 2);
	myPiece.setPosition(0, 0);
}


void EntityPiece::draw(RenderWindow &_window)
{
	_window.draw(myPiece);
}


void EntityPiece::setDefaultColor(const sf::Color &_color)
{
	myDefaultColor = _color;
	myDefaultShade = sf::Color(Uint8(_color.r*myDefaultSaturation), Uint8(_color.g*myDefaultSaturation), Uint8(_color.b*myDefaultSaturation));
}


void EntityPiece::setDefaultSaturation(const float &_saturation)
{
	myDefaultSaturation = _saturation;
	myDefaultShade = sf::Color(Uint8(myDefaultColor.r*_saturation), Uint8(myDefaultColor.g*_saturation), Uint8(myDefaultColor.b*_saturation));
}



























