#include<iostream>

using namespace std;

int multiplyRecursive(int a, int b){

    
    if(b==1){
        return a;
    }
    
    return a + multiplyRecursive(a, (b-1));   
}

int main(){
    int a, b;
    cout<<"Enter The Value Of a(multiplicand): ";
    cin>> a;
    cout<<"Enter The Value Of b(multiplier): ";
    cin>> b;
    int product = multiplyRecursive(a, b);

    cout<<"The Product of "<<a<<" and "<<b<<" is "<<product;

    return 0;
}