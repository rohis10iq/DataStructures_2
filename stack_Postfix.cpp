#include <iostream>
#include <string>
using namespace std;


class Stack{
private:
    int maxSize;
    int top;
    int* stackArray;

public:
    Stack(int size){
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    ~Stack(){

        delete[] stackArray;
    }

    void push(int value){
        if (top < maxSize - 1) {
            stackArray[++top] = value;
        }
        else{
            cout<<"Stack Overflow!"<<endl;
        }
    }

    int pop(){
        if(top >= 0){

            return stackArray[top--];

        }
        else{
            cout<<"Stack Underflow!"<<endl;

            return -1;
        }
    }

    int peek(){
        if(top >= 0){

            return stackArray[top];

        }
        else{
            cout<<"Stack is Empty!"<<endl;
            return -1; 
        }
    }

    bool isEmpty(){

        return (top == -1);
    }
};


int evaluatePostfix(string expression){

    Stack stack(expression.length());

    for(int i = 0; i < expression.length(); ++i){

        char c = expression[i];

        if(c >= '0' && c <= '9'){

            stack.push(c - '0'); 

        } 
        else if(c == '+' || c == '-' || c == '*' || c == '/'){

            int operand2 = stack.pop();
            int operand1 = stack.pop();

            switch (c){
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                default:
                    cout << "Invalid operator!" << endl;
                    return -1; 
            }
        }
    }

    if(!stack.isEmpty()){

        return stack.pop();
    }
    else{
        cout<<"Invalid Expression!"<<endl;
        return -1; 
    }
}

int main(){

    string postfixExpression;
    cout<<"Enter a Postfix Expression: (e.g., 234*+)";
    getline(cin, postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    
    if(result != -1){

        cout<<"Result of Postfix Expression "<<postfixExpression<<" is: "<<result<<endl;
    }

    return 0;
}
