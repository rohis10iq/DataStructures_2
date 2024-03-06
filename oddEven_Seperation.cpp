#include<iostream>
#include<cstring>
#include<string>

using namespace std;

class Node{
    private:
        int info;
        
        Node* next;
        Node* previous;

    public:
        Node(int info){
            this->info = info;
            next = NULL;
            previous = NULL;
        }
    friend class DoubleList;
};

class DoubleList{
    private:
        Node* head;
        int length;
    public:
        DoubleList(){
            head = NULL;
            length = 0;
        }


    void insert(int info)
    {
        Node* newNode = new Node(info);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = newNode;
            
        }
    }

    void Remove(int info)
    {
        if(head->info == info){
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        else{
            Node* current = head;
            while(current != NULL){
                if(current->info == info){

                    if(current->previous != NULL){
                        current->previous->next = current->next;
                    }   
                    if(current->next != NULL){
                        current->next->previous = current->previous;
                    }

                    delete current;
                }
                current = current->next;
            }
        }
    }

    DoubleList oddNumbers(){
        DoubleList List1;
        Node *current = head;
        while(current != NULL){

            if(current->info % 2 == 1){

                List1.insert(current->info);
            }

            current = current->next;
        }

        List1.display();
    }
    
    DoubleList evenNumbers(){
        DoubleList List2;
        Node *current = head;
        while(current != NULL){

            if(current->info % 2 == 0){

                List2.insert(current->info);
            }
            current = current->next;
        }
        List2.display();
        
    }

    void display(){

        Node *current = head;
        while(current != NULL){

            cout<<"ID : "<<current->info<<endl;
            current = current->next;
        }
    }

};

int main()
{
    DoubleList DList;
    DList.insert(1);
    DList.insert(2);
    DList.insert(3);
    DList.insert(4);
    DList.insert(5);
    DList.insert(6);
    DList.insert(7);
    DList.insert(8);
    DList.insert(9);
    
    DList.display();

    cout<<"First DOUBLE LINKED LIST"<<endl;
    DList.oddNumbers();

    cout<<"Second DOUBLE LINKED LIST"<<endl;
    DList.evenNumbers();
}