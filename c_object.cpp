#include <iostream>
#include "c_object.h"
using namespace std;


c_object::c_object(float arg_x,float arg_y )
    {
       this ->x=arg_x;
       this->y=arg_y;
    }

void c_object::update(){};
float c_object::getx() {
    return x;
};
float c_object::gety() {
    return y;
};
float &c_object::setx() {
    return x;
};
float& c_object::sety() {
    return y;
};
c_object::~c_object()
    {
        cout<<"destruktor klasy C_Object"<<endl;
    }

