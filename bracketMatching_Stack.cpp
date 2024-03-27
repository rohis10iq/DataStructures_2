#include <iostream>

using namespace std;

class Stack{
    private:
        char* arr;
        int capacity;
        int top;
    
        

    public:

        Stack(int size){
            capacity = size;
            arr = new char[capacity];
            top = -1;
        }

        ~Stack(){
            delete[] arr;
        }

        void push(char element){
            if(top == capacity - 1){
                cout<<"Stack Overflow!"<<endl;
                return;
            }

            arr[++top] = element;
        }

        char pop(){
            if(top == -1){
                cout<<"Stack Underflow!"<<endl;
                return '\0';
            }

            return arr[top--];
        }

        bool isEmpty(){
            return top == -1;
        }
};

bool isValid(string s){
    Stack stack(s.length());

    int i = 0;
    while(i < s.length()){

        char bracket = s[i];

        if(bracket == '(' || bracket == '{' || bracket == '['){

            stack.push(bracket);
        } 
        else{

            if(stack.isEmpty()){
                
                return false;
            }

            char openBracket = stack.pop();

            if((openBracket == '(' && bracket != ')') ||
                (openBracket == '{' && bracket != '}') ||
                (openBracket == '[' && bracket != ']')){

                return false;
            }
        }

        i++;
    }


    return stack.isEmpty();
}

int main(){
    string s;

    cout<<"Enter a string with parentheses: ";
    cin>>s;

    if(isValid(s)){
        cout<<"The Parentheses Are Valid!"<<endl;
    } 
    else{
        cout<<"The Parentheses Are Not Valid!"<<endl;
    }

    return 0;
}
