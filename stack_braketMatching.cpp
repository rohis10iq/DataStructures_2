#include <iostream>
#include <string>
using namespace std;

class Stack{
    private:
        int maxSize;
        int top;
        char* stackArray;

    public:
        Stack(int size){
            maxSize = size;
            stackArray = new char[maxSize];
            top = -1;
        }

        ~Stack(){
            delete[] stackArray;
        }

        void push(char value){
            if(top < maxSize - 1){
                stackArray[++top] = value;
            } 
            else{
                cout<<"Stack Overflow!"<<endl;
            }
        }

        char pop(){
            if (top >= 0){

                return stackArray[top--];
            }
            else{
                cout<<"Stack Underflow!"<<endl;

                return '\0';
            }
        }

        char peek(){

            if(top >= 0){

                return stackArray[top];
            }
            else{

                return '\0';
            }
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
            
        }
};

bool matchBrackets(string input){

    Stack stack(input.length());

    for (int i = 0; i < input.length(); i++){

        char bracket = input[i];
        if(bracket == '(' || bracket == '[' || bracket == '{'){

            stack.push(bracket);

        } 
        else if(bracket == ')' || bracket == ']' || bracket == '}'){

            if (stack.isEmpty()){
                return false;
            }

            char topBracket = stack.pop();
            if((bracket == ')' && topBracket != '(') || (bracket == ']' && topBracket != '[') || (bracket == '}' && topBracket != '{')){

                return false;
            }
        }
    }

    return stack.isEmpty(); 
}

int main(){

    string input;

    cout<<"Enter a bracket string: ";
    getline(cin, input);

    bool bracketsMatch = matchBrackets(input);

    if(bracketsMatch){

        cout<<"Brackets are matched."<<endl;
    }
    else{
        cout<<"Brackets are not matched."<<endl;
    }

    return 0;
}