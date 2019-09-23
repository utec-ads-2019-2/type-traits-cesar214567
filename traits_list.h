#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"

template <typename Tr>
class TraitsList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Node<T>* tail;
        Operation cmp;
        int sizes=0;

        bool find(T data, Node<T> **&pointer) {
            while(*pointer!=nullptr){
                if (cmp((*pointer)->data,data)){
                    return true;
                }else{
                    pointer=&((*pointer)->next);
                }
            }
            return false;
        }
              
    public:
        TraitsList() : head(nullptr),tail(nullptr) {};
             
        bool insert(T data) {
            
            auto a=&head;
            if (!find(data,a)){
                if (*a==nullptr){
                    *a=new Node<T>(data);   
                }
            }else{
                // Si lo encuentra, entonces no se debería hacer nada
                if ((*a)->data==data){
                    return false;
                }else{
                    Node<T> *temp=(*a)->next;
                    a=&((*a)->next);
                    *a=new Node<T>(data);
                                    
                }
                    
            }  
            
        }
             
        bool remove(T data) {
            auto a=&head;
            if (find(data,a)){
                // Estás haciendo una doble validación
                if ((*a)->data==data){
                    auto temp=*a;
                    *a=temp->next;
                    temp->prev=*a;
                }else{
                    return false;
                }
            }
        }  

        bool find(T data) {
            auto a=&head;
            return find(data, a);
        }

        T operator [] (int index) {
            // No controlas casos del index, negativo o mayor al tamaño
            auto temp=this->head;
            for (int i=0;i<index;i++){
                temp=temp->next;
            }
            return temp->data;
        }
             
        int size() {
            return sizes;
        }

        void print() {
            auto temp=head;
            while ( temp!=nullptr){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }

        ~TraitsList() {
            head->killSelf();
        }         
};

#endif