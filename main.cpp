#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <list>
#include <sstream>
#include <ctime>
using namespace std;
using namespace sf;

#include "c_object.h"
#include "c_plansza.h"
#include "c_pole.h"
#include "c_traktor.h"
#include "zwierzeta.h"

class przycisk_myszki {
private:
	c_plansza* plansza;
public:
	przycisk_myszki(c_plansza* arg_plansza)
	{
		plansza = arg_plansza;
	}
};

class Grafika_traktor : public Drawable
{
public:
	Grafika_traktor(float x, float y)
	{	
		texture.loadFromFile("traktor.png");
		sprite.setOrigin(25, 25);
		sprite.setTextureRect(IntRect(0, 0, 50, 50));
		sprite.setTexture(texture);
		
	}
	sf::Sprite sprite;
	Grafika_traktor() = delete;
	~Grafika_traktor() = default;
	void move(float x, float y)
	{
		sprite.setPosition(x, y);
	}
	

private:
	sf::Texture texture;
	void draw(RenderTarget& target, RenderStates state) const override
	{	
		target.draw(this->sprite, state);
	}
	
};

class Grafika_pole : public Drawable
{
public:
	Grafika_pole(float x, float y, c_pole *wsk, int kolor1, int kolor2, int kolor3)
	{	
		
		rectangle.setPosition(x, y);
		rectangle.setSize(Vector2f(wsk->getszerokosc(), wsk->getwysokosc()));
		rectangle.setOutlineColor(Color::Black);
		rectangle.setFillColor(Color(kolor1, kolor2, kolor3));
		rectangle.setOutlineThickness(5);
		

	}
	Grafika_pole() = delete;
	~Grafika_pole() = default;

	

private:
	RectangleShape rectangle;
	void draw(RenderTarget& target, RenderStates state) const override
	{
		target.draw(this->rectangle, state);
	}

};

class Grafika_zwierzeta : public Drawable
{
public:
	Grafika_zwierzeta(float x, float y)
	{

		circle.setPosition(x, y);
		circle.setRadius(promien);
		circle.setFillColor(Color::White);
		circle.setOrigin(this->promien, this->promien);


	}
	Grafika_zwierzeta() = delete;
	~Grafika_zwierzeta() = default;
	void move(float x, float y)
	{
		circle.setPosition(x, y);
	}


private:
	CircleShape circle;
	float promien = 8;
	void draw(RenderTarget& target, RenderStates state) const override
	{
		target.draw(this->circle, state);
	}

};

class rysuj_text
{

	Text source;
	Font mainGameFont; 
public:
	void drawText(const String& str, float xposition, float yposition, RenderWindow& window)
	{	
		mainGameFont.loadFromFile("arial.ttf");
		source.setFont(mainGameFont);
		source.setString(str);
		source.setCharacterSize(24); 
		source.setPosition(xposition, yposition);
		source.setFillColor(Color::White);
		window.draw(source);
	}
};

class lista_rysuj {
public:
	list<Grafika_zwierzeta*> lista_grafik;
	void sprawdz_zwierzeta(c_plansza* wsk) {
		for (auto& element : lista_grafik)
		{
			delete element;
		}

		lista_grafik.clear();

		for (auto& element : wsk->getzwierzeta())
		{	
			Grafika_zwierzeta* wsk1 = new Grafika_zwierzeta(element->getx(), element->gety());
			lista_grafik.push_back(wsk1);

				
		}
	}
	


};


int main(){
	//traktor
	c_traktor* traktor = new c_traktor(450, 450, 3);
	Grafika_traktor* grafikatraktor = new Grafika_traktor(traktor->getx(), traktor->gety());
	//pole
	c_pole* pole = new c_pole(750, 250,0, 0, 100);
	
	//utworzenie Okna
	RenderWindow window{ VideoMode{1200,900},"farma" };
	window.setFramerateLimit(60);

	//utworzenie t³a
	sf::Sprite sprite;
	sf::Texture texture;
	texture.loadFromFile("mapa.png");
	sprite.setTextureRect(IntRect(0, 0, 1200, 900));
	sprite.setTexture(texture);
	//dodanie eventu do zamykania
	Event wydarzenia;

	//Utworzenia planszy
	c_plansza* plansza = new c_plansza();
	//³apania z myszki
	przycisk_myszki* przycisk = new przycisk_myszki(plansza);


	rysuj_text text;


	lista_rysuj xd;
	
	bool wcisnieta_myszka = false;
	while (1)
	{
		window.draw(sprite);
		Grafika_pole* grafikapole = new Grafika_pole(pole->getx(), pole->sety(), pole, pole->getred(), pole->getgreen(), pole->getblue());
		
		plansza->updatezwierzeta();
		xd.sprawdz_zwierzeta(plansza);
		for (auto& element : xd.lista_grafik)
		{
			window.draw(*element);
		}
		window.draw(*grafikapole);
		traktor->update();
		grafikatraktor->sprite.setRotation(traktor->getkierunek());
		window.draw(*grafikatraktor);
		grafikatraktor->move(traktor->setx(), traktor->sety());
		
		text.drawText("Stan konta: "+ to_string(plansza->getsaldo()) + "$", 0, 10, window);
		text.drawText("Ilosc zwierzat: " + to_string(xd.lista_grafik.size()), 0, 40, window);
		text.drawText("Koszt siewu: " + to_string(pole->getkoszt()) + "$", 400, 10, window);
		text.drawText("Potencjalny zysk: " + to_string(pole->getmoneyfromsale()) + "$", 400, 40, window);
		text.drawText("Koszt ulepszenia pola: " + to_string(pole->getkoszt_ulepszenia()) + "$", 800, 10, window);
		text.drawText("Koszt ulepszenia traktora: " + to_string(traktor->getkoszt_ulepszenia_traktora()) + "$", 800, 40, window);
		
		sf::Vector2i position = sf::Mouse::getPosition();
		int x = window.getPosition().x;
		int y = window.getPosition().y;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if ((wcisnieta_myszka == false) && (position.x - x) > 1100 && (position.x - x) < 1200 && (position.y - y) > 860 && (position.y - y) < 920 &&
				(traktor->getx()>pole->getx() && (traktor->getx())<(pole->getx()) + pole->getszerokosc() && (traktor->gety())>pole->gety() && (traktor->gety())<(pole->gety()) + pole->getwysokosc()))
			{
				wcisnieta_myszka = true;
				cout << "zbierz" << endl;
				pole->zbierz(plansza->setsaldo());
				
			}
			if ((wcisnieta_myszka == false) && (position.x - x) > 930 && (position.x - x) < 1040 && (position.y - y) > 860 && (position.y - y) < 920 &&
				(traktor->getx() > pole->getx() && (traktor->getx()) < (pole->getx()) + pole->getszerokosc() && (traktor->gety()) > pole->gety() && (traktor->gety()) < (pole->gety()) + pole->getwysokosc()))
			{
				wcisnieta_myszka = true;
				cout << "zasiej" << endl;
				pole->zasiej(plansza->setsaldo());
				
			}
			if ((wcisnieta_myszka == false) && (position.x - x) > 170 && (position.x - x) < 280 && (position.y - y) > 860 && (position.y - y) < 920 &&
				(traktor->getx()) > 70 && (traktor->getx()) < 460 && (traktor->gety()) > 600 && (traktor->gety()) < 710)
			{
				wcisnieta_myszka = true;
				cout << "ulepsz traktor" << endl;
				traktor->ulepsztraktor(plansza->setsaldo());
				
			}
			if ((wcisnieta_myszka == false) && (position.x - x) > 10 && (position.x - x) < 120 && (position.y - y) > 860 && (position.y - y) < 920 &&
				(traktor->getx()) > 70 && (traktor->getx()) < 460 && (traktor->gety()) > 600 && (traktor->gety()) < 710)
			{
				wcisnieta_myszka = true;
				cout << "dokup pole" << endl;
				pole->kupnopowierzniuprawnej(plansza->setsaldo());
				
			}
			if ((wcisnieta_myszka == false) && (position.x - x) > 330 && (position.x - x) < 440 && (position.y - y) > 860 && (position.y - y) < 920 &&
				(traktor->getx()) > 70 && (traktor->getx()) < 460 && (traktor->gety()) > 600 && (traktor->gety()) < 710)
			{
				wcisnieta_myszka = true;
				cout << "kup owce" << endl;
				plansza->dodaj_zwierze(plansza->setsaldo());
				
			}
			if ((wcisnieta_myszka == false) && (position.x - x) > 490 && (position.x - x) < 600 && (position.y - y) > 860 && (position.y - y) < 920 &&
				(traktor->getx()) > 70 && (traktor->getx()) < 460 && (traktor->gety()) > 600 && (traktor->gety()) < 710)
			{
				wcisnieta_myszka = true;
				cout << "sprzedaj owce" << endl;
				plansza->usun_zwierze(plansza->setsaldo());
				
			}
			
		

		}
		else
		{
			wcisnieta_myszka = false;
		}

		pole->update();
		plansza->rozmnazanie();
		
		
		window.pollEvent(wydarzenia);
		if (wydarzenia.type == Event::Closed)
		{
			window.close();
			break;
		}

		
		
		window.display();
	}

}