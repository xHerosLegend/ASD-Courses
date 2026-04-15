//
// Created by Carmine Andreozzi on 19/03/26.
//
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

bool controllo_numeri(int &numattuale, int numusciti[], int max_num);
void reset_numeri(int numusciti[]);

int main() {

    fstream problema, soluzioni,esito;
    problema.open("/Users/carmineandreozzi/Filetxt/Problema.txt");
    soluzioni.open("/Users/carmineandreozzi/Filetxt/Soluzione.txt");
    esito.open("/Users/carmineandreozzi/Filetxt/Esito.txt",ios::out);
    if (!problema.is_open() || !soluzioni.is_open()) {
        perror("Errore: file non aperto! , Motivo");
        return 1;
    }

    int num = 0;
    char simbolo_1, File_symbol;
    int confronto[5] = {0};
    bool verificato1 = true;
    bool verificato2 = true;
    int numeripossibili = 0;
    int uscito[10] = {0};
    string riga1, riga2;
    int i = 0, j = 0;
    int num_da_confrontare = 0;

    while ((getline(soluzioni, riga1)) && (getline(problema, riga2))) {

        istringstream ss(riga1);
        istringstream File_symbol_lenght(riga2);

        numeripossibili = riga2.length() + 1;
        j = 0;
        reset_numeri(uscito);

        ss >> num_da_confrontare;
        uscito[j] = num_da_confrontare;

        while ((ss >> simbolo_1 >> num) && (File_symbol_lenght >> File_symbol)) {
            
            if (controllo_numeri(num, uscito, numeripossibili)) {
                verificato2 = false;
            } else {
                if (simbolo_1 != File_symbol) {
                    cout << "Simbolo ERRATI: " << simbolo_1 << " -- " << File_symbol;
                    verificato2 = false;
                } else {
                    if (simbolo_1 == '>') {
                        if (num_da_confrontare <= num) {
                            cout << "ERRATO: ";
                            verificato1 = false;
                        }
                    } else if (simbolo_1 == '<') {
                        if (num_da_confrontare >= num) {
                            cout << "ERRATO: ";
                            verificato1 = false;
                        }
                    }
                }
            }
            cout << num_da_confrontare << " " << simbolo_1 << " " << num << " _ ";
            num_da_confrontare = num;
            j++;
            uscito[j] = num;
        }

        if (verificato2) {
            confronto[i] = verificato1 ? 1 : 0;
        } else {
            confronto[i] = 0;
        }

        verificato1 = true;
        verificato2 = true;
        i++;
        cout << "\n";
    }

    for (i = 0; i < 5; i++) {
        cout << confronto[i] << " - ";
    }

    for (i = 0; i < 5; i++) {
        if (confronto[i] == 1) {
            esito<<"Corretta\n";
        }else {
            esito<<"Sbagliata\n";
        }
    }


    return 0;
}

bool controllo_numeri(int &numattuale, int numusciti[], int max_num) {
    int size = sizeof(numusciti);
    bool uscito = false;

    if (max_num >= numattuale) {
        for (int i = 0; i < size; i++) {
            if (numusciti[i] == numattuale) {
                cout<<"ERRATO NUM_UGUALI ("<<numattuale<<") ("<<numusciti[i]<<") _";
                uscito = true;
            }
        }
    } else {
        return true;
    }

    return uscito;
}

void reset_numeri(int numusciti[]) {
    int size = sizeof(numusciti);
    for (int i = 0; i < size; i++) {
        numusciti[i] = 0;
    }
}