//
// Created by Carmine Andreozzi on 26/03/2026.
/*  Exercise
    A blockchain-like data structure is a data structure
    consisting of a list of blocks, each of which
    contains lists of transactions. A transaction is a
    record consisting of a FROM ID, a TO ID, and an
    integer value QT.
    1. Design and implement a
    LinkedList data structure using templates and use it to
    create a blockchain
    2. Given an ID A, print to the screen/save to a file all
    transactions in which A appears and its final balance

 */
#include <iostream>
#include <string>
#include <exception>



class Identifiable {
public:
    virtual std::string getID() = 0;
    virtual void show() = 0;
    virtual ~Identifiable() = default;
};

template <class T2>
class transaction : public Identifiable{
private:
    std::string id_From ;
    std::string id_To ;

    T2 qt = 0;
public:
    transaction(std::string id_From_ = "NULL",std::string id_To_ = "NULL",T2 qt_= 0) : id_From(std::move(id_From_)), id_To(std::move(id_To_)),qt(qt_) {};
    ~transaction(){std::cout<<"Destroy Transaction"<<std::endl;};

    void setID_From(std::string set_id) {id_From = std::move(set_id);};
    void setID_To(std::string set_id) {id_To = std::move(set_id);};
    std::string getID_From(){return  id_From;};
    std::string getID_To(){return  id_To;};

    void show(){std::cout<<"ID: "<<id_From<<", Final ID: "<<id_To<<", Quantity; "<<qt<<std::endl;}

    void setQT(T2 balance_){qt = balance_;};
};

template<class T3>
class node {
private:
    node *next;
    node *prev;
    T3 *data; // T2 should be the class
public:
    node(T3 *data_) : next(nullptr), prev(nullptr), data(data_){};
    ~node(){std::cout<<"Destroy Node"<<std::endl;}

    node *getnext(){return next;};
    node *getprev(){return prev;};

    void setNext(node *next_){next=next_;};
    void setPrev(node *prev_){prev=prev_;};

    T3 *getdata() {return data;};
};


template <class T1>
class person {
private:
    std::string id ;
    T1 balance = 0;
public:
    person(std::string id_ = "NULL",T1 balance_= 0) : id(std::move(id_)) , balance(balance_) {};
    ~person(){std::cout<<"Destroy Person"<<std::endl;};

    void setID(std::string set_id) {id = std::move(set_id);};

    std::string getID(){return  id;};
    void show(){std::cout<<"ID: "<<id<<", Balance: "<<balance<<std::endl;};
    void setBalance(T1 balance_){balance = balance_;};

    node<T1> *createTransaction(T1 money , std::string id_) {
        if (money > balance) {
            throw std::runtime_error("Not Enough Money");
        }else {
        }
    };
};


template <class T4>
class DoubleLinkedList {
private:
    node<T4> * current;
    node<T4> * front;
    node<T4> * tail;
public:
    DoubleLinkedList() : current(nullptr),front(nullptr),tail(nullptr){};
    ~DoubleLinkedList(){
        while (front != nullptr) {
            node<T4> *tmp = front;
            front = front->getnext();
            std::cout<<"Destroying: ";
            tmp->getdata()->show();
            std::cout<<"\n";
            delete tmp->getdata();
            delete tmp;
        }
    };

    bool isEmpty(){return front == nullptr;};

    void goFront() {
        if (isEmpty()) {
            throw std::runtime_error("Empty List");
        }else {
            current=front;
        }
    };
    void goTail() {
        if (isEmpty()) {
            throw std::runtime_error("Empty List");
        }else {
            current=tail;
        }
    }

    DoubleLinkedList *insertAtFront(T4 *ex) {
        node<T4> *newNode = new node<T4>(ex);
        if (isEmpty()) {
            front=tail=newNode;
        }else  {
            front->setPrev(newNode);
            newNode->setNext(front);
            front=newNode;
        }
        return this;
    }

    DoubleLinkedList *insertAtBack(T4 *ex) {
        node<T4> *newNode = new node<T4>(ex);
        if (isEmpty()) {
            front=tail=newNode;
        }else {
            tail->setNext(newNode);
            newNode->setPrev(tail);
            tail = newNode;
        }
        return this;
    }
    node<T4> *getCurr() {return current;}

    T4 *removeFromFront() {
        try {
            if (isEmpty()) {
                throw std::runtime_error("Empty List");
            }
            node<T4> *tmp = front;
            T4 *a = tmp->getdata();
            if (front == tail) {
                front=tail=nullptr;
            }else {
                front = front->getnext();
                front->setPrev(nullptr);
            }
            std::cout<<"Remove From Front: ";
            a->show();
            std::cout<<std::endl;
            delete tmp;
            return  a;
        }catch (const std::exception(&e)) {
            std::cerr<<"Catch This Error: "<<e.what();
        }
    };

    T4 *removeFromTail() {
        try {
            if (isEmpty()) {
                throw std::runtime_error("Empty List");
            }
            node<T4> *tmp = tail;
            T4 *a = tmp->getdata();
            if (front == tail) {
                front=tail=nullptr;
            }else {
                tail = tail->getprev();
                tail->setNext(nullptr);
            }
            std::cout<<"Remove From Tail: ";
            a->show();
            std::cout<<std::endl;
            delete tmp;
            return  a;
        }catch (const std::exception(&e)) {
            std::cerr<<"Catch This Error: "<<e.what();
        }
    };

    T4 searchID(std::string id_) {
        if (isEmpty()) {
            throw std::runtime_error("Empty List");
        }
        goFront();
        while (current != nullptr) {
            T4 *tmp = current->getdata();
        }
    };

};

;



int main() {

    person<float> *p1 = new person<float>("I23D",200.52);
    DoubleLinkedList<person<float>> * d1 = new DoubleLinkedList<person<float>>;
    d1->insertAtFront(p1);
    d1->removeFromFront();

    delete d1;
    delete p1;
    return 0;
}