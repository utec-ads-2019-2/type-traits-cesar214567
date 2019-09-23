#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"

template <typename T>
class SelfList {
    public: 
        enum Method {
            Move, Count, Transpose
        };

    protected:
        Node<T> *head;
        Node<T> *tail;
        Method method;
        int sizes=0;

    public:
        SelfList(Method method) : head(nullptr),tail(nullptr),method(method){};
            

        bool insert(T data) {
            Node<T> *temp=new Node<T>(data);
            if(this->head==nullptr){
                this->head=temp;
                this->tail=temp;
                this->sizes++;
            }else{
                this->tail->next=temp;
                temp->prev=this->tail;
                this->tail=temp;
                this->sizes++;
            }
            
            print();
            return true;
        }
             
        bool remove(T data) {
            Node<T> *temp=head;
            for (int i=0;i<sizes;i++){
                if (temp->data==data){
                    Node<T> *temporal2=temp->prev;
                    Node<T> *temporal3=temp->next;
                    temporal2->next=temporal3;
                    temporal3->prev=temporal2;
                    delete temp;
                    return true;
                }else{
                    temp=temp->next;
                }
                
            }
            return false;
        }  

        bool find(T data) {
            Node<T> *temp=head;
            // Podrías ahorrar código sacando 
            for (int i=0;i<sizes;i++){
                if (temp->data==data){
                    cout<<method<<endl;
                    // Podrías separarlo en métodos privados
                    if (method==Move){
                        if(sizes>1){
                            if (temp!=head){
                                temp->prev->next=temp->next; 
                                temp->next->prev=temp->prev;
                                temp->next=this->head;
                                this->head->prev=temp;
                                this->head=temp;
                                this->head->prev=nullptr;
                                return true; 
                        
                            }
                        }
                    }
                    if (method==Count){
                        temp->contador++;
                        if (temp==head){
                            head->contador++;
                            return true;
                        }
                        if (sizes==1){
                            temp->contador++;
                            return true;
                        }else{
                            if (temp==this->tail){
                                cout<<"hola"<<endl;
                                temp->prev->next=nullptr;
                                temp->prev=nullptr;
                                temp->contador++;
                                Node<T> *nodo_actual=temp;
                                while(temp->prev->contador<temp->contador){
                                    temp=temp->prev;
                                }
                                temp->prev->next=nodo_actual;
                                nodo_actual->prev=temp->prev;
                                nodo_actual->next=temp;
                                temp->prev=nodo_actual;
                                print();
                                return true;
                            }else{
                                cout<<"inicio"<<endl;
                                if (temp->prev->contador>=temp->contador){
                                    cout<<"hola5"<<endl;
                                    print();
                                    return true;
                                }else{
                                    Node<T> *nodo_actual=temp;
                                    while(temp!=head && temp->prev->contador<nodo_actual->contador){
                                            cout<<"data"<<temp->data<<endl;
                                            temp=temp->prev;
                                    }
                                    cout<<"temporal"<<temp->data<<endl;
                                    cout<<"hola"<<endl;
                                    cout<<"ultimo"<<endl;
                                    if (temp==head){
                                        cout<<"final"<<endl;
                                        nodo_actual->prev->next=nodo_actual->next; 
                                        nodo_actual->next->prev=nodo_actual->prev;
                                        nodo_actual->next=head; 
                                        head->prev= nodo_actual;
                                        head=nodo_actual;
                                    }else{
                                        nodo_actual->prev->next=nodo_actual->next; 
                                        nodo_actual->next->prev=nodo_actual->prev;
                                        temp->prev->next=nodo_actual;
                                        nodo_actual->prev=temp->prev;
                                        nodo_actual->next=temp;
                                        temp->prev=nodo_actual;
                                    
                                    }
                                    
                                }
                            }
                        }
                        
                        
                    }
                    if(method==Transpose){
                        if( temp!=head){
                            Node<T> *izquierda=temp->prev;
                            Node<T>*derecha=temp->next;
                            if(derecha!=nullptr){
                                derecha->prev=izquierda;
                            }
                            izquierda->next=derecha;
                            if (izquierda->prev!=nullptr){
                                izquierda->prev->next=temp;
                            }
                            temp->prev=izquierda->prev;
                            temp->next=izquierda;
                            izquierda->prev=temp;
                            
                            
                              
                        }
                        






                    }

                    //print();
                    return true;
                }else{
                    temp=temp->next;
                }

            }
            return false;
        }

        T operator [] (int index) {
            if( index>=sizes){
                return out_of_range("out of range");
            }else{
                Node<T> *temp=head;
                for (int i=0;i<index;i++){
                    temp=temp->next;
                }
                return temp->data;
            }
        }

             
        int size() {
            return sizes;
        }

        void print() {
            Node<T> *temp=head;
            for (int i=0;i<sizes;i++){
                cout<<temp->data<<" "<<endl;
                temp=temp->next;
            }
            cout<<endl;
        }

        ~SelfList() {
            head->killSelf();
        }  

        

};




#endif