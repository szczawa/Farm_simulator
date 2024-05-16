#include "c_pole.h"
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

c_pole::c_pole(float arg_x, float arg_y, bool arg_zasiane, bool arg_do_zbioru, int arg_cena_zboza)
        : c_object(arg_x, arg_y) {
    zasiane = arg_zasiane;
    do_zbioru = arg_do_zbioru;
    cena_zboza = arg_cena_zboza;

            }


void c_pole::kupnopowierzniuprawnej(int& money) {
    
    if (zasiane != 1) {
        if (wysokosc <= 500 && szerokosc <= 400) {
            if (koszt_ulepszenia <= money) {
                money = money - koszt_ulepszenia;
                powierzchnia = powierzchnia + 10;
                koszt = koszt + (powierzchnia * koszt_siewu);
                moneyfromsale = moneyfromsale + cena_zboza* powierzchnia*2;
                koszt_ulepszenia = koszt_ulepszenia + 1000;
                wysokosc = wysokosc + 10;
                szerokosc = szerokosc + 10;


            }
            else {
                cout << "Nie stac cie" << endl;
            };
        }
        else {
            cout << "Osiagnieto maksymalna powierzchnie pola!" << endl;
        }
    }
    else {
        cout << "Nie mozna dokupic gdy zboze jest zasiane" << endl;
    }

};

void c_pole::zasiej(int& money) {

    


    if (zasiane == 0 && do_zbioru == 0 && money>=koszt) {
        
        
         
            zasiane = 1;
            do_zbioru = 0;
            money = money - koszt;
        
        cout << "zboze zostalo zasiane" << endl;
        
        


    }
    else if (zasiane == 1 && do_zbioru == 0) {
        cout << "zboze rosnie" << endl;
    }
    else if (zasiane == 1 && do_zbioru == 1) {
        cout << "nie mozna zasiac, zboze gotowe do zbioru" << endl;
    }
    else if (zasiane == 0 && do_zbioru == 1) {
        cout << "bład algorytmu" << endl;
    }
    else if (zasiane == 0 && do_zbioru == 0 && money < koszt) {
        cout << "nie stac cie" <<endl;
    }

};
void c_pole::zbierz(int &money) {

    



    if (zasiane == 1 && do_zbioru == 1) {
        
            zasiane = 0;
            do_zbioru = 0;
            money = money + moneyfromsale;
            cout << "zboze zostalo zebrane" << endl;
            red = 146;
            green = 104;
            blue = 41;
         
        

    }
    else if (zasiane == 1 && do_zbioru == 0) {
        cout << "zboze rosnie" << endl;
    }
    else if (zasiane == 0 && do_zbioru == 0) {
        cout << "nie ma co zbierac" << endl;
    }
    else if (zasiane == 0 && do_zbioru == 1) {
        cout << "bład algorytmu" << endl;
    }

};

void c_pole::update() {

    if (zasiane == 1 && do_zbioru == 0) {
            
            licznik = licznik + 1;
            if (licznik == 300) {
                do_zbioru = 1;
                cout << "zboze gotowe do zbioru" << endl;
                licznik = 0;
                red = 245;
                green = 242;
                blue = 159;
            };
            if (licznik > 0 && licznik < 35) {
                red = 25;
                green = 51;
                blue = 0;
            };
            if (licznik >= 35 && licznik < 70) {
                red = 51;
                green = 102;
                blue = 0;
            };
            if (licznik >= 70 && licznik < 110) {
                red = 76;
                green = 153;
                blue = 0;
            };
            if (licznik >= 110 && licznik < 145) {
                red = 102;
                green = 204;
                blue = 0;
            };
            if (licznik >= 145 && licznik < 180) {
                red = 128;
                green = 255;
                blue = 0;
            };
            if (licznik >= 180 && licznik < 215) {
                red = 255;
                green = 255;
                blue = 0;
            };
            if (licznik >= 215 && licznik < 250) {
                red = 255;
                green = 255;
                blue = 51;
            };
            if (licznik >= 250 && licznik < 275) {
                red = 255;
                green = 255;
                blue = 102;
            };

        

    }
};

float c_pole::getwysokosc() {
    return wysokosc;
}
float c_pole::getszerokosc() {
    return szerokosc;
}
int c_pole::getkoszt() {
    return koszt;
};
int c_pole::getkoszt_ulepszenia() {
    return koszt_ulepszenia;
};
int c_pole::getred() {
    return red;
};
int c_pole::getgreen() {
    return green;
};
int c_pole::getblue() {
    return blue;
};
int c_pole::getmoneyfromsale() {
    return moneyfromsale;
};

c_pole::~c_pole()
    {
        cout<<"destruktor c_pola " <<endl;
    }
