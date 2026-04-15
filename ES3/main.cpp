//
// Created by Carmine Andreozzi on 25/03/26.
//
#include <iostream>
#include <string>
#include <exception>
class Impiegato {
private:
    std::string nome_;
    int salario_ = 0;
public:
    Impiegato(std::string nome = "" ,int salario = 0) : nome_(std::move(nome)), salario_(salario){};
    virtual ~Impiegato(){std::cout<<"Distruggo Impiegato\n";};

    void setSalario(int salario) {
        salario_ = salario;
    };
    virtual int getSalario() {
        return  salario_;
    };

    virtual  void show() {
        std::cout<<"Nome: "<<nome_<<", Salario: "<<salario_<<", ";
    }

};

class Manager :public Impiegato {
private:
    int bonus_ = 0;
public:
    Manager(std::string nome = "",int salario = 0,int bonus = 0) : Impiegato(std::move(nome),salario) , bonus_(bonus){};
    ~Manager() override {std::cout<<"Distruggo Manager \n";} ;

    void setBonus(int bonus) {
        bonus_ = bonus;
    };
    int getBonus() {
        return bonus_;
    };
    int getSalario() override {
        return  ( Impiegato::getSalario() + bonus_);
    };

    void show() override {
        Impiegato::show();
        std::cout<<"Bonus: "<<bonus_;
    };

};

class Node {
private:
    Impiegato *data;
    Node *next;
    Node *prev;
public:
    Node(Impiegato *data_) : data(data_) , next(nullptr),prev(nullptr){};
    ~Node(){std::cout<<"Distruggo Il Nodo\n";};

    void setNext(Node *next_) {
        next = next_;
    };
    Node *getNext() {
        return next;
    };
    void setPrev(Node *prev_) {
        prev = prev_;
    };
    Node *getPrev() {
        return prev;
    };
    Impiegato *getdata() {
      return data;
    };
};

class LinkedList {
private:
    Node *front;
    Node *back;
    Node *current;
public:
    LinkedList() : front(nullptr),back(nullptr),current(nullptr){};
    virtual ~LinkedList() {
        while (front != nullptr) {
            Node *tmp = front;
            front = front->getNext();
            std::cout<<"Distruggo: ";
            tmp->getdata()->show();
            std::cout<<"\n";
            delete tmp->getdata();
            delete tmp;
        }
    };

    bool isEmpty() {
        return front==nullptr;
    };

    LinkedList *insertaAtFront(Impiegato *ex) {
        Node *newNode = new Node(ex);
        if (isEmpty()) {
            front=back=newNode;
        }else {
            front->setPrev(newNode);
            newNode->setNext(front);
            front = newNode;
        }
        std::cout<<"Inserisco: ";
        ex->show();
        std::cout<<"\n";
        return this;
    };

    LinkedList *insertAtBack(Impiegato *ex) {
        Node *newNode = new Node(ex);
        if (isEmpty()) {
            front=back=newNode;
        }else {
            back->setNext(newNode);
            newNode->setPrev(back);
            back = newNode;
        }
        std::cout<<"Inserisco: ";
        ex->show();
        std::cout<<"\n";
        return this;
    }

    Impiegato *removeFromFront() {
        try {
            Node *tmp = front;
            Impiegato *a = tmp->getdata();
            if (isEmpty()) {
                throw std::runtime_error("Lista Vuota");
            }else if (front == back) {
                front=back=nullptr;
            }else {
                front= front->getNext();
                front->setPrev(nullptr);
            }
            std::cout<<"Elimino da Davanti: ";
            a->show();
            delete tmp;
            return  a;

        }catch (const std::exception(&ex)) {
            std::cerr<<"Errore: "<<ex.what();
        }
    };

    Impiegato *removeFromBack() {
        try {
            Node*tmp = front;
            Impiegato *a = tmp->getdata();
            if (isEmpty()) {
                throw std::runtime_error("Lista Vuota");
            }else if (back==front) {
                back=front=nullptr;
            }else {
                back = back->getPrev();
                back->setNext(nullptr);
            }
            std::cout<<"Elimino da Dietro: ";
            a->show();
            delete tmp;
            return  a;
        }catch (const std::exception(&ex)) {
            std::cerr<<"Eccezzione: "<<ex.what();
        }
    }

    // Qui Mi Gestisco Il Node Current

    bool atFront() {
        return front == current;
    }

    bool atBack() {
        return back ==current;
    }

    LinkedList *forwards() {
        if (isEmpty()) {
            throw std::runtime_error("Lista Vuota");
        }else {
            if (current == nullptr) {
                current = front;
            }
            if (!atBack()) {
                current = current->getNext();
            }
            return this;
        }
    };

    /* LinkedList *backwards() {
         if (isEmpty()) {
             throw std::runtime_error("Lista Vuota");
         }else {
             if (current == nullptr) {
                 current=front;
             }
             if (!atFront()) {
                 current = current->getPrev();
             }
             return this;
         }
     }
     */



    LinkedList *goFront() {
        if (isEmpty()) {
            throw std::runtime_error("Lista Vuota");
        }else {
            current = front;
            return this;
        }
    };

    friend void stampaLista(LinkedList*);
    friend int sommaSalari(LinkedList*);
};

void stampaLista(LinkedList *lista) {
    if (lista->isEmpty()) {
        throw std::runtime_error("Lista Vuota");
    }else {
        lista->current = lista->front;
        std::cout<<"Lista Impiegati :\n";
        while (lista->current != nullptr) {
            lista->current->getdata()->show();
            std::cout<<"\n";
            lista->current = lista->current->getNext();
        }
    }
}

int operator+(Impiegato& a,Impiegato& b) {
    return a.getSalario() + b.getSalario();
};

int operator+(int a,Impiegato& b) {
    return a + b.getSalario();
};


// PARLANDO CON IL PROF, VA USATO UN DUMMY "Impiegato" che viene usato per contare tutti i salari, quindi qui non devo ritornare un int ma un Impiegato
int sommaSalari(LinkedList *lista) {
    if (lista->isEmpty()) {
        throw std::runtime_error("Lista Vuota");
    }else {
        int totale = 0;
        lista->goFront();
        while (lista->current != nullptr) {
            totale = totale + (lista->current->getdata()->getSalario());
            lista->current=lista->current->getNext();
        }
        return  totale;
    }
}





int main() {
    LinkedList *l1 = new LinkedList;
    Impiegato *i1 = new Impiegato("Mario Rossi",1000);
    Impiegato *i2 = new Manager("Gianluca Colatosti",2500,500);
    Impiegato *i3 = new Impiegato("Francesco Pio Russo",1500);
    Impiegato *i4 = new Manager("Francesco Vassallo",3000,1000);

    l1->insertAtBack(i1);
    l1->insertAtBack(i2);
    l1->insertAtBack(i3);
    l1->insertAtBack(i4);

    stampaLista(l1);

    int totale=0;
    totale = sommaSalari(l1);

    std::cout<<"Somma Di Tutti I Salari: "<<totale<<std::endl;

    delete l1;

    return 0;
}