#include "linked_list.h"
#include<iostream>
using mtm::LinkedList;
using namespace std;

int main() {
    LinkedList<int> listi;
    cout << listi.size() << endl;
    listi.insert(20);
    cout << listi.size() << endl;
    for(int i=3;i<22;i++){
        listi.insert(i);
    }
    cout << listi.size() << endl;

    LinkedList<int> list2(listi);
    cout << list2.size() << endl;
        list2.insert(44);
    list2.insert(7);


    cout << list2.contains(8) << endl;
    cout << list2.contains(32) << endl;
    cout << list2.contains(20) << endl;

    list2.removeElement(20);
    list2.removeElement(20);
    cout << list2.size() << endl;
    cout << list2.contains(20) << endl;    

    cout << list2.size() << endl;
    cout << list2.contains(20) << endl;

    FOREACH(int, iter, list2){
    cout << iter << endl;
    }

    return 0;
}