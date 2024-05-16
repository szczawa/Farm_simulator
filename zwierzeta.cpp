#include "zwierzeta.h"
#include "c_object.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#define _USE_MATH_DEFINES

#include <random>
#include <math.h>;
#include <algorithm>
#include <list>
#include <ctime>
using namespace std;
using namespace sf;


c_zwierzeta::c_zwierzeta(float x, float y) 
	: c_object(x, y) 
{
	
}

void c_zwierzeta::update() {
	double kat = (double)rand() / RAND_MAX * 2 * M_PI;

	double ddx = cos(kat);
	double ddy = sin(kat);

	dx = dx + 0.3 * ddx;
	dy = dy + 0.3 * ddy;

	dx = dx/ sqrt(dx * dx + dy * dy);
	dy = dy/ sqrt(dx * dx + dy * dy);

	x = x + 0.7 * dx;
	y = y + 0.7 * dy;

	if (x >= 300) {
		x = 300;
	}else if (x <= 80) { 
		x = 80; }

	if (y >= 420) { 
		y = 420;
	}
	else if (y <= 210) { 
		y = 210; }
	
	n = n + 1;
	
}

int c_zwierzeta::getn() {
	return n;
}

void c_zwierzeta::setn(int liczba) {
	n = liczba;
}





c_zwierzeta::~c_zwierzeta()
{
	cout << "destruktor c_zwierzeta " << endl;
}
