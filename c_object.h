/*****************************************************************//**
 * \file   c_object.h
 * \brief  plik naglowkowy modulu c_object
 * 
 * \author Dawid
 * \date   June 2022
 *********************************************************************/
#ifndef C_OBJECT_H
#define C_OBJECT_H
#include <list>

/**
 * @brief definicja klasy abstratcyjnej c_object
 * 
 */
class c_object
{
protected:
    /**
     * @brief wspolrzedna x obiektu
     */
    float x;
    /**
     * @brief wspolrzedna y obiektu
     */
    float y;
    
public:
    /**
     * @brief konstruktor obiektu
     * @param arg_x pozycja x 
     * @param arg_y pozycja y
     */
    
    c_object( float arg_x,float arg_y ); 

    /**
     * @brief metoda wirtualna update
     */
    virtual void update()=0;
    /**
     * @brief metoda zwracajaca chroniony atrybut x 
     */
    float getx();
    /**
     * @brief metoda zwracajaca chroniony atrybut y
     */
    float gety();
    /**
     * @brief metoda pozwalajaca zmienic chroniony atrybut x
     */
    float &setx();
    /**
     * @brief metoda pozwalajaca zmienic chroniony atrybut y
     */
    float &sety();
    /**
     * @brief destruktor klasy c_object
     */

    virtual ~c_object();                              
};


#endif // C_OBJECT_H
