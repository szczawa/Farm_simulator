#include "c_plansza.h"



c_plansza::c_plansza()
{
    
}

void c_plansza::dodaj_zwierze(int &money) {
    if (money >= 500) {
        c_zwierzeta* zwierze = new c_zwierzeta(200, 300);
        zwierzeta.push_back(zwierze);
        money = money - 500;
    }
}
void c_plansza::usun_zwierze(int &money) {
   
    if (zwierzeta.size() > 0) {
        zwierzeta.pop_front();
        money = money + 500;
    }
}

void c_plansza::updatezwierzeta() {
    for (auto& element : zwierzeta)
    {
        element->update();
    }
   
}
void c_plansza::rozmnazanie() {
    int ilosc = zwierzeta.size();
    int x = 0;
    if (ilosc < 100) {
        if (ilosc > 1) {
            for (auto& element : zwierzeta)
            {
                x = element->getn() + x;

            }

        }
        if (x > 1000) {
            c_zwierzeta* zwierze = new c_zwierzeta(200, 300);
            zwierzeta.push_back(zwierze);
            x = 0;
            int i = 0;
            for (auto& element : zwierzeta)
            {

                element->setn(0);
                if (i == ilosc) {
                    element->setn(-200 * (ilosc - 1));
                }

                i++;


            }

        }
    }

}

int &c_plansza::setsaldo() {
    return saldo;
}
int c_plansza::getsaldo() {
    return saldo;
}
list<c_zwierzeta*> c_plansza::getzwierzeta() {
    return zwierzeta;
};
c_plansza  ::~c_plansza()
{
    cout<<"destruktor planszy";
}
