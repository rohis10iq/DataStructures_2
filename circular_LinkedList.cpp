#include<iostream>

using namespace std;

class Node{
    private:
        int info;
        Node* next;
        
    public: 
        Node(int info){
            this->info = info;
            next = NULL;
            
        }
    
};

class cLinkedList{
    private:
        Node* head;
        int length;
    public:
        cLinkedList(){
            head = NULL;
            length = 0;
        }
    
    void insert(int info){
        Node* newNode = new Node(info);

        if(head == NULL){
            head = newNode;
            head->next = head;
        }
    }
};