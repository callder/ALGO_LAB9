#include <iostream>
#include <math.h>
#include <fstream>
#include <chrono>

using namespace std;


template <class  T>

class Node{
private:
    int id;
public:

    Node<T> * next;
    Node<T> * prev;
    T * data;

    Node<T>(T *value) {
        id  = 0;
        next = nullptr;
        prev = nullptr;
        data = value;
    }

    void setId(int id){
        this->id = id;
    }

};


template <class  T>
class linkedList {
private:
    int size;
    Node<T> *head;
    Node<T> *tail;
    int idQty;


public:


    linkedList<T>() {
        idQty = 1;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    ~linkedList<T>() {
        this->clearList();
    }

    Node<T> *getHead() {
        return this->head;
    }
    Node<T> * getTail(){
        return this->tail;
    }


    int getSize() {
        return this->size;
    }

    void add_begin(T *value) {

        auto *newNode = new Node<T>(value);
        newNode->next = this->head;

        if (this->size == 0) {
            this->tail = newNode;
        } else {
            this->head->prev = newNode;
        }
        this->head = newNode;

        newNode->setId(this->idQty);
        this->idQty++;
        this->size++;
    }

    void add_behind(T* value) {
        auto *newNode = new Node<T>(value);
        newNode->prev = this->tail;


        if (size < 1) {
            this->head = newNode;
        } else {
            this->tail->next = newNode;
        }

        this->tail = newNode;

        newNode->setId(this->idQty);
        this->idQty++;
        this->size++;
    }

    void deleteLast() {
        this->tail = this->tail->prev;
        delete this->tail->next;
        this->tail->next = nullptr;
        this->size--;
    }

    void deleteFirst() {
        this->head = this->head->next;
        delete this->head->prev;
        this->head->prev = nullptr;
        this->size--;
    }


    void clearList() {
        while (size != 0) {
            if (this->size == 1) {
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
                this->size = 0;
            } else {
                this->deleteFirst();
            }
        }
    }

};

template <class T>
class dynamicArray{
private:
    int size;
    T * head;
    float grow = 1.5;
public:
    int length;

    dynamicArray<T>(){
        head = new T[5];
        size = 5;
        length = 0;
    }

    bool checkSize(){
        return size*0.8 < length;
    }

    void add(T value){
        if(checkSize()) growSize();
        head[length]= value;
        length++;
    }

    void growSize(){
        size= size*grow;
        auto *newHead = new T[size];

        for(int i = 0; i<length;i++){
            newHead[i] = head[i];
        }
        delete [] head;
        head = newHead;
    }
    void growSize(int Size){
        size= Size;
        auto *newHead = new T[size];

        for(int i = 0; i<length;i++){
            newHead[i] = head[i];
        }
        delete [] head;
        head = newHead;
    }


    T  operator [] (int index) {

        if(length<= index){
            cout<<"Index out of range!";
            return -1;
        }
        return head[index];

    }

    T * index(int index){

        return &head[index];
    }

};
