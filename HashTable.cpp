#include "HashTable.h"

Hash::Hash(long size){
    do{
        M = rand() % size;
    } while(!isPrime(M));

    arr = new Node*[size+1000];
    for(int i=0;i<size+1000;++i)
        arr[i] = NULL;

    r1 = rand() % M;
    r2 = rand() % M;
    r3 = rand() % M;
    r4 = rand() % M;
} 

long Hash::HashFunct(int key){
    long sum = 0;

    sum += (r1 * (key % 256 ));
    key /= 256;
    sum += (r2 * (key % 256 ));
    key /= 256;
    sum += (r3 * (key % 256 ));
    key /= 256;
    sum += (r4 * (key % 256 ));

    return sum;
}

bool Hash::isPrime(int key){
    if(key <= 1){
        return false;
    }

    for(int i = 2 ; i < key ; i++){
        if(key % i == 0){
            return false;
        }
    }

    return true;
}

void Hash::Insert(int key){
    int pos = HashFunct(key) % M;

    if(arr[pos] == NULL){
        arr[pos] = new Node(key);
    }
    else{
        Node *target = arr[pos];

        while(target->getNext() != NULL)
            target = target->getNext();
        Node *newNode = new Node(key);
        target->setNext(newNode);
    }

}

void Hash::Search(int key){
    int pos = HashFunct(key) % M;
    Node *target = arr[pos];

    while(target != NULL){
        if(target -> getData() == key)
            return;
        target = target->getNext();
    }
}

Node::Node(int d){
    data = d;
    next = NULL;
}
