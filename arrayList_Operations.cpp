#include<iostream>
using namespace std;

class arrList{
    private:
        int* arr;
        int capacity;
        int size;
        int length;
        int* temp;
    
    public:
        arrList(int size){
            arr = new int[size];
            this->size = size;
            capacity = size;
            length = 0;
            temp = NULL;
        }
        ~arrList(){
            delete[] arr;
            arr = nullptr;
        }

    // makes the pointer point to the start of the list
    void start(){
        temp = arr;
    }

    // makes the pointer point to the tail of the list
    void tail(){
        //temp = arr + length -1;

        start();
        for(int i = 1; i < length; i++){
            temp++;
        }

        /*for(int i = 1; i < length; i++){
            next();
        }*/
    }

    
    void next(){
        temp++;
    }
    void back(){
        temp--;
    }
    
    bool isFull(){
        if(length == capacity){
            return true;
        }
        else{
            return false;
        }
    }

    bool isEmpty(){
        if(length == 0){
            return true;
        }
        else{
            return false;
        }
    }

    void printList(){
        for(int i = 0; i < length; i++){
            cout<<*temp;
            temp++;
        }
        cout<<endl;
    }

    int getlength(){
        return length;
    }

    void insert(int value, int position){
        if(isFull()){
            cout<<"The List is Full!"<<endl;
        }
        if(position < 1 || position > length + 1){
            cout<<"Invalid Position!"<<endl;
        }

        tail();

        for(int i = length; i >= position; i--){
            *(temp + 1) = *temp;
            back();
        }
        *(temp + 1) = value;
        length++;
    }

    void remove(int position){
        if(isEmpty()){
            cout<<"The List is Empty!"<<endl;
        }
        if(position < 1 || position > length){
            cout<<"Invalid Position!"<<endl;
        }
        temp = arr + position + 1;
        for(int i = position; i < length; i++){
            *temp = *(temp + 1);
            next();
        }
        length--;
    }

    bool find(int value){
        if(isEmpty()){
           //cout<<"The List is Empty!"<<endl;
            return false;
        }
        start();
        for(int i = 1; i < length; i++){
            if(*temp == value){
                return true;
            }
            temp++;
        }
        
        return false;
    }

    void update(int position, int value){
        if(isEmpty()){
            cout<<"The List is Empty!"<<endl;
        }
        if(position < 1 || position > length){
            cout<<"Invalid Position!"<<endl;
        }
        start();

        for(int i = 1; i < length; i++){
            if(i == position){
                *temp = value;
            }
            temp++;
        }
    }

    void clear() {
        if (isEmpty()) {
            cout << "The List is Empty!" << endl;
            return;
        }

        length = 0;
        }
        /*
        void clearAndDeallocate() {
            if (isEmpty()) {
                cout << "The List is Empty!" << endl;
                return;
            }

            delete[] arr;
            arr = nullptr;
            length = 0;
        }
    */

    int get(int position){
        if(isEmpty()){
            cout<<"The List is Empty"<<endl;
            return 0;
        }
        if(position < 1 || position > length){
            cout<<"Invalid Postion!"<<endl;
            return 0;
        }
        start();

        for(int i = 1; i <= length; i++){
            if(i == position){
                return *temp;
            }
            else{
                temp++;
            }
        }
    }

    void sort(){
        if(isEmpty()){
            cout<<"The List is Empty"<<endl;
            return;
        }

        for(int i = 1; i < length; i++){
            for(int j = 1; j < length - i; j++){
                int* current = temp + j;
                int* next = temp + j + 1;

                if(*current > *next){
                    
                    int temporary = *current;
                    *current = *next;
                    *next = temporary;
                }
            }
        }
    }

    void reverse(){
        if(isEmpty()){
            cout<<"The List is Empty"<<endl;
            return;
        }
        start();

        int* end = temp + length - 1;
        int temporary = 0;

        for(int i = 0; i< length / 2; i++){
            temporary = *temp;
            *temp = *end;
            *end = temporary;
            end--; 
            temp++;
        }
    }


};
int main(){
    arrList myList(10); 

    int choice, position, value;

    do{
        cout<<"Array List Operations!"<<endl;
        cout<<"Choose an Option to Continue"<<endl;

        cout<<"1. Insert."<<endl;
        cout<<"2. Remove(Position)."<<endl;
        cout<<"3. Search(Value)."<<endl;
        cout<<"4. Update."<<endl;
        cout<<"5. Get Element(Position)"<<endl;
        cout<<"6. Sort List."<<endl;
        cout<<"7. Reverse List."<<endl;
        cout<<"8. Print List."<<endl;
        cout<<"9. Clear List."<<endl;
        cout<<"0. Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter Value to Insert: ";
                cin>> value;
                cout<<"Enter Position to Insert At: ";
                cin>> position;

                myList.insert(value, position);

                break;

            case 2:
                
                cout<<"Enter Position to Remove From: ";
                cin>> position;

                myList.remove(position);

                break;

            case 3:
            
                cout<<"Enter Value to Seacrh: ";
                cin>> value;

                
                if(myList.find(value)){
                    cout<<"Value Found in the List."<<endl;
                }else{
                cout <<"Value not Found in the List."<<endl;
                }

                break;

            case 4:
                
                cout<<"Enter Position to Update: ";
                cin>> position;
                cout<<"Enter New Value to Update: ";
                cin>> value;

                myList.update(position, value);

                break;

            case 5:
                
                cout<<"Enter Position to Get: ";
                cin>> position;

                cout<<"Element at Position "<<position<<": "<<myList.get(position)<<endl;

                break;

            case 6:
                myList.sort();
                cout << "List sorted in ascending order." << endl;
                break;

            case 7:
                
                myList.reverse();

                break;

            case 8:
                
                myList.printList();

                break;

            case 9:

                myList.clear();

                break;

            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout<<"Invalid choice. Please enter a valid option."<<endl;
        }

    }while(choice != 0);

    return 0;
}