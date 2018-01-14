/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Stacks.h"
#include<string>

using namespace std;

bool Stacks::EmptyS() {
    bool k = false;
    if (firstS == NULL) { //loop checks if array has a first value
        k = true;
    }

    return k;
}

void Stacks::InsertInFrontS(ElementType x) {
    
    nodeS *temp = new nodeS;
    temp->data = x;
    
    if(EmptyS()==true){
        temp->next = NULL;
        firstS = temp;
    }else{
    temp->next = firstS;
        firstS = temp;
    }
    NS++;
   
    
}

string Stacks::DeleteFrontS() {
    string r = firstS->data;
    firstS= firstS->next;
    
   return r; 
}

void Stacks::DisplayS() {
    nodeS *travel = firstS;
    
    while(travel != NULL){
        cout<<travel->data<<endl;
        travel = travel->next;
    }
    
}

Stacks::Stacks() {
    NS = 0;
    firstS = NULL;
    
}

