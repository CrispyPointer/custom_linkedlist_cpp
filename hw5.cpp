#include "Node.h"
#include "List.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

int main(){ 
    List list1;
    List list2;
    Iterator pos;
    list2.push_back(2);
    list2.push_back(3);
    list2.push_back(5);
    list2.push_back(7);
    list2.push_back(11);
    cout << "Please input a set of nonnegative numbers for a List"<<endl;
    cout << "(Enter -1 when you are finished): ";
    int n, index, value;
    while(true){
        cin >> n;
        if(n==-1) break;
        list1.push_back(n);
    }
    
    cout << "\nYour list is \n";
    cout<<"(";
    for(pos = list1.begin(); pos != list1.end(); pos ++)    cout << *pos << " ";
    cout<<")";

    while(true){
        cout<<"\nSelect an index for insertion (enter -1 when finished): ";
        cin >> index;
        if(index == -1) break;
        cout<<"Select a value for insertion: ";
        cin >> value;
        pos = list1.begin();
        while(index != 0){
            pos ++;
            index -=1;
        }
        list1.insert(pos,value);
    }

    cout << "\nThe augmented List is"<<endl;
    cout<<"(";
    for(pos = list1.begin(); pos != list1.end(); pos ++)    cout << *pos << " ";
    cout<<")";

    cout << "\nWhen we sort the previous List we obtain"<<endl;
    list1.sort();
    cout<<"(";
    for(pos = list1.begin(); pos != list1.end(); pos ++)    cout << *pos << " ";
    cout<<")";

    cout << "\nAnd this sorted List in reverse order is"<<endl;
    list1.reverse();
    cout<<"(";
    for(pos = list1.begin(); pos != list1.end(); pos ++)    cout << *pos << " ";
    cout<<")";

    cout<<"\nIf we merge this List with the List (2,3,5,7,11) we obtain"<<endl;
    List merge;
    merge.merge(list1,list2);
    cout<<"(";
    for(pos = merge.begin(); pos != merge.end(); pos ++)    cout << *pos << " ";
    cout<<")";
    return 0;
}

