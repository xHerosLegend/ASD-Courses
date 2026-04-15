//
// Created by Carmine Andreozzi on 18/03/26.
//

#ifndef ASD_CLASS_H
#define ASD_CLASS_H
#include <iostream>
using namespace std;

class Contenitore {
public:
    int qt = 0;

    Contenitore(int acqua = 0) : qt(acqua) {};
    ~Contenitore(){cout<<"Distruggo il contenitore \n";};

    int getQt() {
        return qt;
    };

    void versa(int lt) {
        if (lt > 0) {
            qt = qt+lt;
            cout<<"Hai versato "<<lt<<" Litri nell'anfora \n";
        }else {
            cerr<<"Input Non Valido";
        }
    }

    void togli(int lt) {
        if (lt >0) {
            qt = qt-lt;
            cout<<"Hai tolto "<<lt<<" Litri dall'anfora \n";
        }else {
            cerr<<"Input Non Valido";
        }
    }
};

class Anfora : public Contenitore{
protected:
    int capacita;
public:
    Anfora(int capacita_ = 0, int acqua_ = 0) : Contenitore(acqua_), capacita(capacita_){} ;
    ~Anfora(){cout<<"Distruggo l'anfora \n";};

    int get_capacita() {
        return capacita;
    };

    void riempi() {
        for (int i = qt; i<capacita;i++) {
            versa(1);
        }
        cout << "Hai riempito L'anfora \n";
    }

    void svuota() {
        togli(capacita);
        cout << "Hai svuotato L'anfora \n";
    }

    bool isVuota() {
        if (qt == 0) {
            return true;
        }
    }

    bool isPiena() {

        if (qt == capacita) {
            return true;
        }
    }

    void spostaContenuto(Anfora *p) {
        int litridaspostare_ = getQt(); // MI PRENDO QUANTI LITRI POSSO SPOSTARE
        int capacitamassima_ = (p->get_capacita() - p->getQt());
        int i;
        for (i = 0 ; i < capacitamassima_ && litridaspostare_ > 0; i ++) {
            p->versa(1);
            litridaspostare_--;
        }
        qt = litridaspostare_;
        cout<<"Ho Spostato "<<i<<" Litri \n";
    };
};

class Indovinello {
public:
    Anfora p1, p2;
    Indovinello() : p1(5,0),p2(3,0){};
    ~Indovinello(){cout<<"Distruggo L'indovinello \n";};

    //METODO MECCANICO
    /*
    void risolvi() {
        while (p1.getQt() != 4) {
            p1.riempi();
            p1.spostaContenuto(&p2);
            p2.svuota();
            p1.spostaContenuto(&p2);
            p1.riempi();
            p1.spostaContenuto(&p2);
            p2.svuota();

            cout<<"P1: "<<p1.getQt()<<"\n";
            cout<<"P2: "<<p2.getQt()<<"\n";
        }


    }*/

    //METODO AUTOMATICO
    void risolvi() {
         while (p1.getQt() !=4) {

            if (p1.isVuota()) {
                p1.riempi();
            }
            p1.spostaContenuto(&p2);
            if (p2.isPiena()) {
                p2.svuota();
            }

            cout<<"P1: "<<p1.getQt()<<"\n";
            cout<<"P2: "<<p2.getQt()<<"\n";
        }
    }

};

#endif //ASD_CLASS_H