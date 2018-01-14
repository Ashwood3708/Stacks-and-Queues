/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queues.h
 * Author: Abdul
 *
 * Created on October 6, 2017, 8:49 PM
 */

#ifndef QUEUES_H
#define QUEUES_H

#include <iostream>
#include<string>
using namespace std;

typedef string ElementType;

struct nodeQ{
     ElementType data;
    nodeQ * next;
};

class Queues{
public:
    Queues(); // Create an empty list
    bool EmptyQ(); // Return true if the list is empty, otherwise return false
    void InserAtEndQ(ElementType x); // Insert a value x at the end of the list
    string DeleteFrontQ(); // delete value on top
    void DisplayQ(); // Display the data values in the list

private:
    nodeQ * firstQ; // Pointer
    int NQ;     //number of nodes
};


#endif /* QUEUES_H */

