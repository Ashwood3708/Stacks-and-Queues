/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stacks.h
 * Author: Abdul
 *
 * Created on October 6, 2017, 8:45 PM
 */

#ifndef STACKS_H
#define STACKS_H

#include <iostream>

using namespace std;

typedef string ElementType;

struct nodeS{
     ElementType data;
    nodeS * next;
};

class Stacks {
public:
    Stacks(); // Create an empty list
    bool EmptyS(); // Return true if the list is empty, otherwise return false
    void InsertInFrontS(ElementType x); // Insert a value x at the front of the list
    string DeleteFrontS(); // delete value on top
    void DisplayS(); // Display the data values in the list


private:
    nodeS * firstS; // Pointer
    int NS;  //number of nodes
};




#endif /* STACKS_H */

