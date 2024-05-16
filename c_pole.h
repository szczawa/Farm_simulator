/*****************************************************************//**
 * \file   c_pole.h
 * \brief  plik naglowkowy modulu c_pole
 * 
 * \author Dawid
 * \date   June 2022
 *********************************************************************/
#ifndef C_POLE_H
#define C_POLE_H
#include "c_object.h"
#include "c_traktor.h"
#include <string>


using namespace std;

/**
 * @brief definicja klasy c_pole
 */
class c_pole: public c_object
{
private:
    /**
     *@brief prywatny atrybut wysokosc(wysokosc posiadanego pola)
     */
    float wysokosc = 300;
    /**
     *@brief prywatny atrybut szerokosc(szerokosc posiadanego pola)
     */
    float szerokosc = 200;
    /**
     *@brief prywatny atrybut powierzchnia(powierzchnia posiadanego pola)
     */
    int powierzchnia = 10;
    /**
     *@brief prywatny atrybut koszt siewu
     */
    int koszt_siewu = 100;
    /**
     *@brief prywatny atrybut cena_zboza 
     */
    int cena_zboza;
    /**
     *@brief prywatny atrybut zasiane, gdy wartoscia boola jest 1, na polu zasiane jest zboze
     */
    bool zasiane;
    /**
     *@brief prywatny atrybut do_zbioru, gdy wartoscia boola jest 1, zboze na polu jest gotowe do zbioru
     */
    bool do_zbioru;
    /**
     *@brief prywatny atrybut koszt_ulepszenia pola
     */
    int koszt_ulepszenia = 1000;
    /**
     *@brief prywatny atrybut licznik
     */
    int licznik = 0;
    /**
     *@brief prywatny atrybut red
     */
    int red = 146;
    /**
     *@brief prywatny atrybut green
     */
    int green = 104;
    /**
     *@brief prywatny atrybut blue
     */
    int blue = 41;
    /**
     *@brief prywatny atrybut koszt
     */
    int koszt = 1000;
    /**
     *@brief prywatny atrybut moneyfromsale
     */
    int moneyfromsale = 2000;


public: 
    /**
     *@brief konstruktor klasy c_pole
     * @param arg_x wspolrzedna x, prawego gornego rogu 
     * @param arg_y wspolrzedna y, prawego gornego rogu 
     * @param arg_zasiane parametr mowiacy czy na utworzonym polu ma byc zasiane zboze
     * @param arg_do_zbioru parametr mowiacy czy na utworzonym polu zboze ma byc gotowe do zbioru
     * @param arg_cena_zboza cena sprzedawanego zboza
     */
    c_pole(float arg_x, float arg_y, bool arg_zasiane, bool arg_do_zbioru, int arg_cena_zboza);

    /**
     * @brief wirtualna metoda dla klasy c_pole
     * 
     */
    void update() override;
    /**
     * @brief metoda pozwalajaca dokupic powierzchnie pola
     * @param money odpowida za zmiane salda
     *
     */
    void kupnopowierzniuprawnej(int& money);
    /**
     * @brief metoda pozwalajaca zasiac na polu zboze
     * @param money odpowida za zmiane salda
     *
     */
    void zasiej(int &money);
    /**
     * @brief metoda zwracajaca chroniony atrybut wysokosc
     */
    float getwysokosc();
    /**
     * @brief metoda zwracajaca chroniony atrybut szerokosc
     */
    float getszerokosc();
    /**
     * @brief metoda zwracajaca chroniony atrybut koszt
     */
    int getkoszt();
    /**
     * @brief metoda zwracajaca chroniony atrybut koszt_ulepszenia
     */
    int getkoszt_ulepszenia();
    /**
     * @brief metoda zwracajaca chroniony atrybut red
     */
    int getred();
    /**
     * @brief metoda zwracajaca chroniony atrybut green
     */
    int getgreen();
    /**
     * @brief metoda zwracajaca chroniony atrybut blue
     */
    int getblue();
    /**
     * @brief metoda zwracajaca chroniony atrybut moneyfromsale
     */
    int getmoneyfromsale();
    /**
     * @brief metoda pozwalajaca zebrac zboze z pola
     * @param money odpowida za zmiane salda
     *
     */
    void zbierz(int&money);
    /**
     * @brief destruktor klasy c_pole
     * 
     */
    ~c_pole();
};

#endif // C_POLE_H
