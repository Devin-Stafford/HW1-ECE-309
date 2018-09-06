//
//  HW2-LinkedList.cpp
//  HW309
//
//  Created by Devin Stafford on 9/5/18.
//  Copyright © 2018 Devin Stafford. All rights reserved.
//

#include <stdio.h>



class ListNode {
private:
    char const *string;
    ListNode *next;
public:
    ListNode(char const *s){string=s;next=NULL;}
    ListNode* getNext(){return next;}
    void setNext(ListNode *n){next = n;}
    char const* getString(){return string;}
};

class List {
private:
    ListNode *head;
    ListNode *tail;
public:
    List();
    ~List();
    void push_back(char const *string);
    char const* get(int n);
    int length();
    char const* remove_front();
};

List::List(){
    head = NULL;
    tail = NULL;
}

List::~List(){
    while (head != NULL) {
        remove_front();
    }
}

void List::push_back(char const *string){
    ListNode *node = new ListNode(string);
    if(head==NULL){
        head = node;
        tail = node;
    }else{
        tail->setNext(node);
        tail = node;
    }
    
}
char const* List::get(int n){
    ListNode *tmp = head;
    for (int i = 0; i<n; i++) {
        tmp = tmp->getNext();
    }
    return tmp->getString();
}

int List::length(){
    ListNode *tmp = head;
    int lengthCount = 1;
    if (head == NULL) {
        return 0;
    }
    while ((tmp != tail) && (head != NULL)) {
        lengthCount++;
        tmp = tmp->getNext();
    }
    return lengthCount;
}

char const* List::remove_front(){
    ListNode *tmp = head;
    char const* removedData = head->getString();
    tmp = head->getNext();
    head = tmp;
    return removedData;
}

int main(){
    
    return 0;
}
