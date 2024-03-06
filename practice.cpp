#include<iostream>

using namespace std;

class Node{
    private:
        int info;
        Node* next;
    public:
        Node(int inf0){
            this->info = info;
            next = NULL;
        }

    friend class CircularList;
};

class CircularList{
    private:
        Node* head;
        int length;
    public:
        CircularList(){
            head = NULL;
            length = 0;
        }

    void insert(int value, int position){
        if(head == NULL){
            return;
        }

        Node* newNode = new Node(value);

        if(position == 1){
            head = newNode;
            head->next = head;
        }
        else{
            int count = 1;

            while(head != nullptr);
        }

    }
};