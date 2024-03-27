#include<iostream>

using namespace std;

class Node{
    private:
        char info;
        Node* next;
    public:
        Node(char info){
            this->info = info;
            next = NULL;
        }
    friend class LinkedList;
};

class LinkedList{
    private:
        Node* head;
        int length;
    public:
        LinkedList(){
            head = NULL;
            length = 0;
        }
    
    bool isEmpty(){
        if(head = NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void insert(char info){
        
        Node* newNode = new Node(info);

        if(isEmpty()){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            
            temp->next = newNode;
        }
        length++;
    }

    void rotateString(){
        Node* temp = head;
        //char dash = '-';
        Node* dash = new Node('-');
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = dash;

        temp = head;
        Node* curr;
        while(temp->next != NULL){
            temp = temp->next;
        }

        do{
            curr = head;
            head = head->next;
            temp->next = curr;
            temp = temp->next;
            curr->next = NULL;
        }while(head->info != 'a' || 'e' || 'i' || 'o' || 'u' || 'y' || 'A' || 'E' || 'I' || 'O' || 'U' || 'Y');
        
    }

    bool containsVowels(){
        Node* temp = head;
            while(temp->next != NULL){
                if(temp->info = 'a' || 'e' || 'i' || 'o' || 'u' || 'y' || 'A' || 'E' || 'I' || 'O' || 'U' || 'Y'){
                    return true;
                }
                temp = temp->next;
            }
        return false;
        
    }

    void pigLatin(){
        if(head->info != 'a' || 'e' || 'i' || 'o' || 'u' || 'y' || 'A' || 'E' || 'I' || 'O' || 'U' || 'Y'){
            Node* temp = head;
            rotateString();
            if(containsVowels()){
                    
                while(temp->next != NULL){
                    temp = temp->next;
                }   
                temp->next = new Node('ay');

            } 
            else{
                temp->next = new Node('way');
            }
              
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new Node('way');
        }
    }

    void display(){
        Node* temp = head;
        cout<<"Original String: "<<endl;
        while(temp != NULL){
            cout<<temp->info;
            temp = temp->next;
        }
        temp = head;
        pigLatin();
        cout<<"String in Pig Latin Form: "<<endl;

        while(temp != NULL){
            cout<<temp->info;
            temp = temp->next;
        }
    }

};

int main(){
    LinkedList LatinString;
    char info;
    cout<<"Enter a String of Characters to Convert into Pig Latin Form."<<endl;
    /*

    */

    LatinString.display();

}