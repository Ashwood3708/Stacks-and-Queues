/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Abdul
 * 4th program assignment: Stacks and Queues
 * Created on October 6, 2017, 8:41 PM
 * description: this program is to transfer names from a stack to queue and a queue to a stack in 3 month intervals
 */

#include <iostream>
#include <cstdlib>   // for srand and rand
#include <fstream>   //for file reader
#include "Stacks.h"
#include "Queues.h"


using namespace std;

/*
 * 
 */
int main() {

    Stacks S;
    Queues Q;
    int num = 0,num2; //number of current workers
    string names[100];
    int r = rand() % 5;
    string x;
    
    cout<<"do you want to: (1)read in a file, (2)*use preset file* , or (3)enter names individually?"<<endl;
    cout<<"Enter 1, 2, or 3 "<<endl;
    string numCheck = "";
    cin>>numCheck;
    
    if(numCheck=="2"){
    //for file read in
    ifstream inFile;
    inFile.open("C:\\Users\\Abdul\\Documents\\coding\\CLionProjects\\StacksAndQueues1\\names.txt");
    //only use inFile.open("names.txt"); when file is in project folder
    if (!inFile) {
    cerr << "Unable to open file names.txt";
    exit(1);   // call system to stop
}

    //reads in values to both list
    while(inFile >> x){
        if (num < 5) {
            S.InsertInFrontS(x);
            names[num] = x;
            num++;
            num2 = num;
        } else {
              names[num2] = x;
            Q.InserAtEndQ(x);
            num2++;
        }

    }
    
    inFile.close();  //close file
    
    
    }else if(numCheck=="1"){
    //for file read in
        cout<<"enter complete path to text file"<<endl;
        cin>>numCheck;
    ifstream inFile;
    inFile.open(numCheck+".txt");
    //only use inFile.open("names.txt"); when file is in project folder
    if (!inFile) {
    cerr << "Unable to open file names.txt";
    exit(1);   // call system to stop
}

    //reads in values to both list
     while(inFile >> x){
        if (num < 5) {
            S.InsertInFrontS(x);
            names[num] = x;
            num++;
            num2 = num;
        } else {
             names[num2] = x;
            Q.InserAtEndQ(x);
            num2++;
        }

    }
    
    inFile.close();  //close file
    
    }else if(numCheck=="3"){
        cout<<"how many names will u enter?"<<endl;
        cin>>numCheck;
        int amount = atoi(numCheck.c_str());
        
        while(amount>0){    //enter names
            if (num < 5) {
                cout<<"enter the ("<<1+num<<") entry"<<endl;
                cin>>x;
                 S.InsertInFrontS(x);
                 names[num] = x;
                 num++;
            num2=num;
        } else {
                 cout<<"enter the ("<<1+num2<<") entry"<<endl;
                cin>>x;
                names[num2] = x;
            Q.InserAtEndQ(x);
            num2++;
        }
            amount--;
        }
    
    
    }else {
        cout<<"ending program";
        return 0;
    }
    
    

    cout << " Initial Waiting List " << endl;
    cout << endl;
    for(int k = 0; k<num2; k++){
        cout<<names[k]<<endl;
    }
//    S.DisplayS();
//    Q.DisplayQ();

    cout << " **Initial workers list " << endl;
    S.DisplayS();

    cout << "How many three-month periods do you want to see?" << endl;
    int repeats;
    cin>>repeats;

    string holder;
    while (repeats > 0) {
        r = rand() % 6;
        cout << "### End of Three Months: Number of jobs needed - " << r << endl;



        if (num == r) {   //if the same do nothing
            holder = "";
        } else if (num > r) {  //while there are more workers than needed subtract workers
            while(num !=r){
                holder = S.DeleteFrontS();
                Q.InserAtEndQ(holder);
                num--;
            }
        } else if (num < r) {//while there are less than needed add workers
            while(num !=r){  
                holder = Q.DeleteFrontQ();
                S.InsertInFrontS(holder);
                num++;
            }   
        }




        cout << "***Workers list***" << endl;
        S.DisplayS();
        cout << "***Waiting list***" << endl;
        Q.DisplayQ();

        repeats--;
    }



}

