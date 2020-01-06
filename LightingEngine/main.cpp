#include <SFML\Graphics.hpp>
//#include <boost/thread.hpp>
#include <iostream>
#include <math.h>
#include "LightingEngine.h"
#include "Entity.h"
using namespace std;
using namespace sf;

int main()
{
	int i = 0;
	Vector2i tempVector; 
	sf::Clock myClock;
	sf::Time myTime;
	int othercount = 0;
	int countgrow = 0;

	RenderWindow window(VideoMode(1600, 900), "SFML works!");
	window.setMouseCursorVisible(false);
	View windowView(Vector2f(0, 0), Vector2f(800, 450));
	window.setView(windowView);

	sf::RectangleShape mouseRect;
	mouseRect.setSize(Vector2f(5, 5));
	mouseRect.setOrigin(Vector2f(2.5, 2.5));
	mouseRect.setFillColor(sf::Color::Green);

	LightingEngine myEngine;

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			myEngine.addEntity();
			myEngine.getEntity(y + x*10)->setColor(sf::Color::Black);
			myEngine.getEntity(y + x*10)->setArea(5, 5);
			myEngine.getEntity(y + x*10)->setPieceArea(10, 10);
			myEngine.getEntity(y + x*10)->setCoords((x - 5)*50, (y - 5)*50);
			//myEngine.getEntity(y + x * 10)->setRotation(y + x * 10);
		}
	}



	myEngine.addLight();
	myEngine.getLight(0)->setColor(sf::Color::Red);
	myEngine.getLight(0)->setReach(700);
	myEngine.addLight();
	myEngine.getLight(1)->setColor(sf::Color::Green);
	myEngine.getLight(1)->setReach(700);
	myEngine.addLight();
	myEngine.getLight(2)->setColor(sf::Color::Blue);
	myEngine.getLight(2)->setReach(700);

	myEngine.addLight();
	myEngine.getLight(3)->setColor(sf::Color::White);
	myEngine.getLight(3)->setReach(500);

	float count = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		tempVector = Mouse::getPosition(window);
		mouseRect.setPosition(float(tempVector.x - 800) / 2, float(tempVector.y - 450) / 2);
		myEngine.getLight(3)->setCoords(Vector2f(float(tempVector.x - 800) / 2, float(tempVector.y - 450) / 2));
		count += 1;
		othercount++;
		myEngine.getLight(0)->setCoords(Vector2f(cos(count*TORAD)*110, sin(count*TORAD)*310));
		myEngine.getLight(1)->setCoords(Vector2f(-cos(count*TORAD)*210, -sin(count*TORAD)*210));
		myEngine.getLight(2)->setCoords(Vector2f(cos(count*TORAD)*310, -sin(count*TORAD)*110));

		window.clear();
		myEngine.draw(window);
		window.draw(mouseRect);
		window.display();
		
		myTime = myClock.getElapsedTime();
		if (myTime.asMilliseconds() > 1000)
		{
			myClock.restart();
			cout << othercount - countgrow << endl;
			countgrow = othercount;
		}
	}
	return 1;
}





























