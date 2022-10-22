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
    struct Node{
        int value;
        Node* next;
        int num_occurences;
        void set_value(int v){
            value=v;
        }
        int get_value(){
            return value;
        }
    };
void add_front_node(struct Node** head, int new_value)// inserts node in the front of the LL
{

        
    struct Node* new_node = new Node; // allocate node

    new_node->value = new_value;  // put in the data

    new_node->next = (*head);  // Make next of new node as head

    (*head) = new_node;  // Move the head to point to
                        // the new node
    }
    
    void insert_node(struct Node* prev_node, int new_value) //insert the node in a specific place
    {
        Node* new_node = new Node();       // creats new node
        new_node->value = new_value;      // saves the new value in "value"
        new_node->next = prev_node->next;// Make next of new node as
                                        // next of prev_node
        prev_node->next = new_node;    // move the next of prev_node
                                      // as new_node
    }
    void insert_node_end(struct Node** head, int new_value){ //inserts node in the end of LL
        struct Node* new_node= new Node;// creats new node
        struct Node *last = *head;
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
    void delete_last_node(struct Node* head){ //function that deletes the last node
        Node* q= head;
        while(q->next->next != NULL)
            q = q->next;
        
        delete (q->next); //delete last node
        q->next = NULL;  // makes last node's next to NULL
       
        
    }
    void print_elements(Node* prev_node){ //function that prints all elements in the linked list
        Node* q;
        q=prev_node;
        while (q!=NULL){
            cout<<q->value<<endl;
            q=q->next;}
    }
    void check_occurence(vector<int> values,struct Node** head_ref ){
        int occurences=0;
        for (int i=0; i<values.size();i++){
            for (int j=1;j<values.size()-1;j++){
                if (values[i]==values[j]){
                    struct Node* new_node = new Node;
                    new_node->value = values[i];
                    new_node->num_occurences = occurences;
                    struct Node *last = *head_ref;
                    while (last->next != NULL)
                    last = last->next;
                    last->next = new_node;
                    new_node->next = NULL;
                    occurences++;}
            }
            
        }
    }
    int calc_sum( struct Node** head_ref){//function that calculates the sum of values in the LL
        int sum=0;
        struct Node *last = *head_ref;
        while (last->next != NULL){
            last = last->next;
            }
        return sum;
    }
};



#endif /* Linked_Lists_h */
