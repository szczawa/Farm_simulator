/*****************************************************************//**
 * \file   c_plansza.h
 * \brief  plik naglowkowy modulu c_plansza
 * 
 * \author Dawid
 * \date   June 2022
 *********************************************************************/

#ifndef C_PLANSZA_H
#define C_PLANSZA_H
#include <list>
#include <iostream>
#include "zwierzeta.h"
#include "c_object.h"

using namespace std;
/**
 * @definicja klasy c_plansza
 */
class c_plansza
{
    /**
     * @brief prywatny atrybut saldo (ilosc pieniedzy ktore posiada gracz)
     */
    int saldo = 2000000;
    /**
     * @brief prywatna lista zawieracja posiadane zwierzeta
     */
    list<c_zwierzeta*> zwierzeta;
public:
    
    

    /**
     * @brief konstruktor klasy c_plansza
     * 
     */
    c_plansza();
    /**
     * @brief destruktor klasy c_plansza
     *
     */
    ~c_plansza();
    /**
     * @brief metoda sluzaca do tworzenia zwierzat i wpisywaniu ich na liste
     * @param odpowiada za zmiane salda
     *
     */
    void dodaj_zwierze(int &money);
    /**
     * @brief metoda sluzaca do usuwaniu zwierzat 
     * @param odpowiada za zmiane salda
     *
     */
    void usun_zwierze(int &money);
    /**
     * @brief metoda zwracajaca chroniony atrybut saldo
     */
    int getsaldo();
    /**
     * @brief metoda pozwalajaca zmienic wartosc chronionionego atrybutu saldo
     */
    int &setsaldo();
    /**
     * @brief metoda zwracajaca chroniona liste zwierzat
     *  
     */
    list<c_zwierzeta*> getzwierzeta();
    /**
     * @brief metoda w ktorej zapisany jest algorytm rozmnazania zwierzat
     * 
     */
    void rozmnazanie();
    /**
     * @brief metoda wywolujaca update dla wszystkich zwierzat na liscie
     * 
     */
    void updatezwierzeta();
};
#endif // C_PLANSZA_H
