#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Node{
    private:
        Node* next;
        string URL;
    public:
        Node(string URL){
            this->URL = URL;
            next = NULL;
        }

    friend class Stack;
};

class Stack{
    private:
        Node* top;
    public:
        Stack(){
            top = NULL;
        }

    bool isEmpty(){
        if(top == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    
    void push(string URL){
        
        Node* newNode = new Node(URL);

        if(isEmpty()){
            top = newNode;
        }
        else{
            Node* temp = top;
            top = newNode;
            top->next = temp;
        }
    };
    string pop(){
        if(isEmpty()){
            return "NULL";
        }

        Node* temp = top;
        string value = top->URL;
        top = top->next;

        delete temp;

    };

    string peak(){
        if(isEmpty()){
            return "NULL";
        }

        return top->URL;
    };
};

int main(){

    Stack forwardStack;
    Stack backStack;
    int choice;
    string URL;

    cout<<"BROWSER NAVIGATION!"<<endl<<endl;

    do{
        cout<<"Choose an Option!"<<endl<<endl;
        cout<<"1. Visit New Website."<<endl;
        cout<<"2. Backward."<<endl;
        cout<<"3. Forward."<<endl;
        cout<<"4. Exit."<<endl;
        
        cout<<"Enter (1 - 4): "<<endl;

        cin>>choice;

        if(choice == 1){
            cout<<endl<<endl<<"Enter Website URL (example.com): "<<endl;
            cin>> URL;
            backStack.push(URL);

            cout<<"You Are Currently On "<< URL <<endl;
            
        }
        else if(choice == 3){
            if(forwardStack.isEmpty()){
                cout<<"You Cannot Navigate Forward!"<<endl;
                cout<<"(Forward_Stack_Empty)"<<endl;
            }
            else{

                string forward = forwardStack.pop();
                cout<<"You Came Forward to "<< forward <<"."<<endl;
                backStack.push(forward);
    
            }
        }
        else if(choice == 2){
            if(backStack.isEmpty()){
                cout<<"You Cannot Navigate Backward!"<<endl;
                cout<<"(Backward_Stack_Empty)"<<endl;
            }
            else{
                string backward = backStack.pop();
                cout<<"You Came Backwards to "<< backward <<"."<<endl;
                forwardStack.push(backward);
   
            }
            
        }

        else if(choice > 4 || choice < 0){
            cout<<"Invalid Choice!"<<endl;
            
        }


    }while(choice != 4);

    return 0;
}
