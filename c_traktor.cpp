#include "c_traktor.h"
#include "c_object.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace std;
using namespace sf;

c_traktor::c_traktor(float arg_x, float arg_y, float arg_predkosc)
            : c_object( arg_x, arg_y )
{   
    x = arg_x;
    y = arg_y;
    predkosc = arg_predkosc;
}
void c_traktor::update() {
	if (x >=1175) {
		x = x - 1;
	}
	if (x <= 25) {
		x = x + 1;
	}
	if (y <= 110) {
		y = y + 1;
	}
	if (y >= 775) {
		y = y - 1;
	}
	if (x >= 53 && x <= 63 && y > 180 && y < 445) {
		x = x - 1;
	}
	if (x >= 315 && x <= 325 && y > 180 && y < 445) {
		x = x + 1;
	}
	if ((x > 53 && x < 325 && y >= 180 && y <= 190)) {
		y = y - 1;
	}
	if ((x > 53 && x < 325 && y >= 435 && y <= 445)) {
		y = y + 1;
	}
	
	


		if (1 == Keyboard::isKeyPressed(Keyboard::Right) && x > 25 && x < 1175 && y>110 && y < 775 && !(x > 53 && x < 325 && y > 180 && y < 445))
		{
			kierunek = 180.f;
			x = x + predkosc;

		}

		else if (1 == Keyboard::isKeyPressed(Keyboard::Left) && x > 25 && x < 1175 && y>110 && y < 775 && !(x > 53 && x < 325 && y > 180 && y < 445))
		{
			kierunek = 0;
			x = x - predkosc;

		}

		else if (1 == Keyboard::isKeyPressed(Keyboard::Up) && x > 25 && x < 1175 && y>110 && y < 775 && !(x > 53 && x < 325 && y > 180 && y < 445))
		{
			kierunek = 90.f;
			y = y - predkosc;

		}

		else if (1 == Keyboard::isKeyPressed(Keyboard::Down) && x > 25 && x < 1175 && y>110 && y < 775 && !(x > 53 && x < 325 && y > 180 && y < 445))
		{
			kierunek = -90.0f;
			y = y + predkosc;

		}
		
	
   
}

void c_traktor:: ulepsztraktor(int& money) {

    if (koszt_ulepszenia_traktora <= money) {
        money = money - koszt_ulepszenia_traktora;
        predkosc = predkosc + 1;
        koszt_ulepszenia_traktora = koszt_ulepszenia_traktora + 1000;


    }
    else {
        cout << "Nie stac cie " << endl;
    };
};

float c_traktor::getpredkosc() {
	return predkosc;
};
int c_traktor::getkoszt_ulepszenia_traktora() {
	return koszt_ulepszenia_traktora;
};
float c_traktor::getkierunek() {
	return kierunek;
};

c_traktor::~c_traktor()
    {
        cout<<"destruktor c_traktor " <<endl;
    }
