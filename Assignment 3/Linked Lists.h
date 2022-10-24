//
//  Linked Lists.h
//  Assignment 3
//
//  Created by Mark Emad  on 21/10/2022.
//
#include <iostream>
#include <vector>
using namespace std;

#ifndef Linked_Lists_h
#define Linked_Lists_h

class Linked_list{
public:
    //struct Node{
        int value;
        Linked_list* next;
        int num_occurences;
        void set_value(int v){
            value=v;
        }
        int get_value(){
            return value;
        }
void add_front_node(Linked_list** head, int new_value)// inserts node in the front of the LL
{

        
    Linked_list* new_node = new Linked_list; // allocate node

    new_node->value = new_value;  // put in the data

    new_node->next = (*head);  // Make next of new node as head

    (*head) = new_node;  // Move the head to point to
                        // the new node
    }
    
    void insert_node(Linked_list* prev_node, int new_value) //insert the node in a specific place
    {
        Linked_list* new_node = new Linked_list();       // creats new node
        new_node->value = new_value;      // saves the new value in "value"
        new_node->next = prev_node->next;// Make next of new node as
                                        // next of prev_node
        prev_node->next = new_node;    // move the next of prev_node
                                      // as new_node
    }
    void insert_node_end(Linked_list** head, int new_value){ //inserts node in the end of LL
        Linked_list* new_node= new Linked_list;// creats new node
        Linked_list *last = *head;
        new_node->value = new_value;  //assign new value to the node's value
        new_node->next = NULL;  //set next pointer of new node to null as it is the last node
            
        if (*head == NULL){    //if the list is empty, new node becomes first node
                *head = new_node;
                return;
        }
        while (last->next != NULL)    //traverse till the last node
            last = last->next;
            last->next = new_node;   //Change the next of last node
            return;
    }
    void delete_last_node(Linked_list* head){ //function that deletes the last node
        Linked_list* q= head;
        while(q->next->next != NULL)
            q = q->next;
        
        delete (q->next); //delete last node
        q->next = NULL;  // makes last node's next to NULL
       
        
    }
    void print_elements(Linked_list* prev_node){ //function that prints all elements in the linked list
        Linked_list* q;
        q=prev_node;
        while (q!=NULL){
            cout<<q->value<<endl;
            q=q->next;}
    }
    bool search(Linked_list* head, int x)
    {
        Linked_list* q = head;
        while (q != NULL) {
            if (q->value == x)
                return true;
            q = q->next;
        }
        return false;
    }
    void check_occurence(vector<int> values,Linked_list** head_ref ){
        int occurences=0;
        for (int i=0; i<values.size();i++){
            for (int j=1;j<values.size()-1;j++){
                if (values[i]==values[j]){
                    Linked_list* new_node = new Linked_list;
                    if (new_node->value==values[i]){
                    new_node->value = values[i];
                    new_node->num_occurences = occurences;
                    Linked_list *last = *head_ref;
                    while (last->next != NULL)
                    last = last->next;
                    last->next = new_node;
                    new_node->next = NULL;
                    if(search(*head_ref, values[i])==true)
                    occurences++;}
                }
            }
            
        }
    }
    int calc_sum(Linked_list** head_ref){//function that calculates the sum of values in the LL
        int sum=0;
        Linked_list *last = *head_ref;
        while (last->next != NULL){
            last = last->next;
            }
        return sum;
    }
};



#endif /* Linked_Lists_h */
