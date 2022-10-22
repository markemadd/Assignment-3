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
    // 1, 8, 3, 8, 4 ,5, 8, 6
    for(int i=0; i<values.size(); i++){
//        cout<<"Current: "<<i+1<<endl;
//        cout<<"Size: "<<values.size()<<endl;
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
    
//    cout<<values.size();
    
    insertAfter(values, first_value, second_value);
    cout<<"Function ended"<<endl;
    
    for(int i=0; i<values.size(); i++)
        cout<<values[i]<<endl;

    return 0;
}

