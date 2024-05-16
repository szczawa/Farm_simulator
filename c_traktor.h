/*****************************************************************//**
 * \file   c_traktor.h
 * \brief  plik naglowkowy modulu c_traktor
 * 
 * \author Dawid
 * \date   June 2022
 *********************************************************************/
#ifndef C_TRAKTOR_H
#define C_TRAKTOR_H
#include "c_object.h"
#include <string>
using namespace std;

/**
 * @brief definicja klasy c_traktor
 */
class c_traktor: public c_object             
{
private:                             

    /**
     * @brief prywatny atrybut predkosc
     */
    float predkosc;
    /**
     * @brief prywatny atrybut koszt_ulepszenia_traktora
     */
    int koszt_ulepszenia_traktora = 1000;
    /**
     * @brief prywatny atrybut kierunek
     */
    float kierunek = 0;
    
public:
    
    /**
     * @brief konstruktor klasy c_traktor
     * 
     * \param arg_x wspolrzedna x traktora
     * \param arg_y wspolrzedna y traktora
     * \param arg_predkosc wartosc predkosci traktora
     */
    c_traktor(float arg_x, float arg_y, float arg_predkosc);

    /**
     * @brief wirtualna metoda update dla klasy c_traktor
     * 
     */
    void update() override;
    /**
     * @brief metoda pozwalajca ulepszyc traktor
     * 
     * \param money odpowida za zmiane salda
     */
    void ulepsztraktor(int& money);
    /**
     * @brief metoda zwracajca prywatny atrybut predkosc 
     *
     */
    float getpredkosc();
    /**
     * @brief metoda zwracajaca prywatny atrybut koszt_ulepsznia_traktora
     * 
     */
    int getkoszt_ulepszenia_traktora();
    /**
     * @brief metoda zwracajaca prywatnty atrybut kierunek
     * 
     */
    float getkierunek();
    /**
     * @brief destruktor klasy c_traktor
     * 
     */
    ~c_traktor();
};

#endif // C_TRAKTOR_H
