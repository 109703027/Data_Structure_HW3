#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node(int);
        int getData() const {return data;}
        Node* getNext() const {return next;}
        void setNext(Node* n) {next = n;}

    private:
        int data;
        Node *next;
};

class Hash{
    public:
        Hash(long);
        void Insert(int key);
        void Search(int key);

    private:
        long HashFunct(int);
        bool isPrime(int);

        long M;
        Node **arr;
        long r1,r2,r3,r4;
};

#endif
