#include <iostream>

#include "test/tester.h"

using namespace std;

int main(int argc, char const *argv[]) {
    Tester::execute();
    /*SelfList<int> list(SelfList<int>::Transpose);
    cout<<list.size()<<endl;
    list.insert(5);
    list.insert(3);
    list.insert(2);
    list.insert(10);
    list.insert(9);
    cout<<list.size()<<endl;
    if (list.find(2)){
        cout<<"encontrado"<<endl;
    }else{
        cout<<"no encontrado"<<endl;
    }
    list.print();
    if (list.find(10)){
        cout<<"encontrado"<<endl;
    }else{
        cout<<"no encontrado"<<endl;
    }
    list.print();
    */
   /*TraitsList<Integer> list;
   list.insert(6);
   list.insert(4);
   list.insert(5);
   list.insert(5);
   list.insert(2);
   if (list.find(2)){
       cout<<"hey"<<endl;
   }
    list.insert(1);
    list.print();
    list.remove(2);
    list.print();*/
   return EXIT_SUCCESS;
}

