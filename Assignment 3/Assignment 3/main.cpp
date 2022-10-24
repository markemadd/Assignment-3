//
//  main.cpp
//  Assignment 3
//
//  Created by Mark Emad  on 18/10/2022.
//
#include "Linked Lists.h"
#include <vector>
#include <iostream>
#include<string>
using namespace std;

void insertAfter(vector<int> &values, int first_value, int second_value){
    for(int i=0; i<values.size(); i++){
        if(values[i]==first_value)
            values.insert(values.begin()+i+1, (int) second_value);
    }
    
}

int main() {
    vector<int> values;
    int n=0;
    int num;
    int first_value, second_value;
    cout<<"Enter number of elements in vector"<<endl;
    cin>>n;
    for (int i=0; i<n; i++){
        cout<<"Enter elements"<<endl;
        cin>>num;
        values.push_back(num);
    }
    
    cout<<"Enter first value"<<endl;
    cin>>first_value;
    cout<<"Enter second value"<<endl;
    cin>>second_value;
    

    
    insertAfter(values, first_value, second_value);
    cout<<"Function ended"<<endl;
    
    for(int i=0; i<values.size(); i++)
        cout<<values[i]<<endl;
    
    Linked_list LL;
    int x;
    Linked_list* p=NULL;
    LL.add_front_node(&p, x);
    LL.insert_node(* &p, x);
    LL.insert_node_end(&p, x);
    LL.delete_last_node(* &p);
    LL.print_elements(* &p);
    LL.check_occurence(values, &p);
    LL.calc_sum(&p);
    
    return 0;
}

