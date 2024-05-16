/*****************************************************************//**
 * \file   zwierzeta.h
 * \brief plik naglowkowy modulu zwierzeta
 * 
 * \author Dawid
 * \date   June 2022
 *********************************************************************/
#ifndef C_ZWIERZETA_H
#define C_ZWIERZETA_H
#include "c_object.h"
#include <string>
#include <random>
#include <math.h>
#include <algorithm>
#include <list>
using namespace std;

/**
 * @brief definicja klasy c_zwierzeta
 */

class c_zwierzeta : public c_object
{

private:
    /**
     * @brief prywatny atrybut dx odpowiadajacy za poruszanie zwierzat
     */
    double dx=0;
    /**
     * @brief prywatny atrybut dy odpowiadajacy za poruszanie zwierzat
     */
    double dy=0;
    /**
     * @brief prywatny atrybut n odpowiadajacy za rozmnazanie zwierzat
     */
    int n = 0;

public:
	/**
	 * @brief konstruktor klasy c_zwierzeta
	 * 
	 * \param arg_x wspolrzedna x utworzonego zwierzecia
	 * \param arg_y wspolrzedna y utworzonego zwierzecia
	 */
    c_zwierzeta(float arg_x, float arg_y);
    /**
     * @brief metoda zwracajaca prywatny atrybut n
     * 
     */
    int getn();
    /**
     * @brief metoda pozwalajca zmieniac wartosc prywatnego atrybutu n
     * 
     * \param liczba wartosc jaka chcemy aby przyjal prywatny atrybut n
     */
    void setn(int liczba);
    /**
     * @brief wirtualne metoda dla klasy c_zwierzeta
     * 
     */
    void update();
    /**
     * @brief destruktor klasy c_zwierzeta
     * 
     */
    ~c_zwierzeta();
    
};

#endif // C_ZWIERZETA_H