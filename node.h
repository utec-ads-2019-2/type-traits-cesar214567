#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    int contador=0;
    Node(T data1) : data(data1) {
        next = nullptr;
        prev=nullptr;
        contador=0;
    }
    Node(T data,int contador1) : data(data),contador(contador1) {
        next = nullptr;
        prev=nullptr;
        contador=0; 
    }
      
    void killSelf();
};

template <typename T>
void Node<T>::killSelf() {
    if (this->next!=nullptr) {
        //cout<<data<<endl;   
        next->killSelf();
    }
    
    delete this;
}

#endif