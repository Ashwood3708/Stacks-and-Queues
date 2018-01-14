/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Queues.h"
#include<string>

using namespace std;



bool Queues::EmptyQ() {
    bool k = false;
    if (firstQ == NULL) { //loop checks if array has a first value
        k = true;
    }

    return k;
}

void Queues::InserAtEndQ(ElementType x) {
    nodeQ *temp = new nodeQ;
    temp->data = x;
    temp->next = NULL;
    nodeQ *travel = firstQ;
    
    if(EmptyQ() == true){
        firstQ = temp;
    }else{
        while(travel->next != NULL){
            travel = travel->next;
        }
        travel->next = temp;
    }
    NQ++;
    
}

string Queues::DeleteFrontQ() {
    string r = firstQ->data;
    firstQ= firstQ->next;
   return r; 
}

void Queues::DisplayQ() {
    nodeQ *travel = firstQ;
    
    while(travel != NULL){
        cout<<travel->data<<endl;
        travel = travel->next;
    }
}

Queues::Queues(){
 NQ = 0;
 firstQ = NULL;
}


