#include<iostream>

using namespace std;

class Node{
    private:
        Node* next;
        int info;
    public:
        Node(int info){
            this->info = info;
            next = NULL;
        }
    friend class Queue;
};

class Queue{
    private:
        Node* front;
        Node* rear;
        int length;
        bool duplicated;
    public:
        Queue(){
            front = NULL;
            rear = NULL;
            length = 0;
            duplicated = false;
        }

        bool isEmpty(){
            if(front == NULL || rear == NULL){
                return true;
            }
            else{
                return false;
            }
        }

        void enQueue(int value){
            Node* newNode = new Node(value);
            if(isEmpty()){
                rear = newNode;
                front = rear;
            }
            else{
                rear->next = newNode; 
                rear = newNode; 
            }
            length ++;
        }

        int deQueue(){
            if(isEmpty()){
                return -1;
            }
            int value = front->info;
            Node* temp = front;
            front = front->next;
            delete temp;
            length--;

            return value;
        }

        int getLength(){
            if(isEmpty()){
                return -1;
            }
            else{
                return length;
            }
        }

        void display(){
            Node* current = front; 
            while(current != NULL){
                cout<<current->info<<" ";
                current = current->next;
            }
            cout<<endl;
        }
        void duplicateList(){
            if(isEmpty()){
                cout<<"Empty list. Nothing to duplicate."<<endl;
                return;
            }

            Node* current = front;
            while(current != NULL){

                Node* temp = current;
                int count = temp->info;
                while(count > 1){
                    Node* newNode = new Node(temp->info);
                    newNode->next = current->next;
                    current->next = newNode;
                    count--;
                    length++; 
                    current = current->next;
                }
                current = current->next;
            }
            

            duplicated = true; 
        }

        bool isduplicated(){
            return duplicated;
        }


    
};

int main() {
    Queue InputList;
    
    int choice, value;
    int length = InputList.getLength();

    do {
        cout<<"1. Enter Value."<<endl;
        cout<<"2. Start Duplicating."<<endl;
        cout<<"3. Exit."<<endl<<endl;
        cout<<"Choose an Option."<<endl;
        cin>>choice;
        if(choice > 3 || choice < 0){
            cout<<"Invalid Choice!"<<endl;
        }

        else if(choice == 1){
            cout<<"Enter Value(int): ";
            cin>> value;

            InputList.enQueue(value);

        }
        
        else if(choice == 2){
            InputList.duplicateList();
            InputList.display(); 
            cout << endl;
        }
    } while(choice != 3 || !InputList.isEmpty() || !InputList.isduplicated());

    return 0;
}