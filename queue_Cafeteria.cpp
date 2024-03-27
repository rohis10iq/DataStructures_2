#include<iostream>
#include<string>

using namespace std;

class Queue{
private:
    int* arr;
    int front;
    int rear;
    int size;
public:
    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return (rear + 1) % size == front;
    }

    void enQueue(int value){
        if(isFull()){
            cout<<"Queue is full. Cannot add more orders."<<endl;
            return;
        }
        if(isEmpty()){
            front = 0;
        }
            
        rear = (rear + 1) % size;
        arr[rear] = value;
    }

    void deQueue(){
        if(isEmpty()){
            cout<<"Queue is empty. No orders to remove."<<endl;
            return;
        }
        if(front == rear){
            front = rear = -1;
        }    
        else{
            front = (front + 1) % size;
        }
            
    }

    int getFront(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
            return -1;
        }

        return arr[front];
    }

    void displayItems(){
        if(isEmpty()){
            cout<<"No orders in the queue."<<endl;
            return;
        }

        int i = front;
        cout<<"Current orders in the queue:"<<endl;

        while(i != rear){
            cout<<arr[i]<< " ";
            i = (i + 1) % size;
        }

        cout<<arr[rear]<<endl;
    }
};

class MenuItem{
private:
    string name;
    double price;
public:
    MenuItem(string name, double price){
        this->name = name;
        this->price = price;
    }

    string getName(){
        return name;
    }

    double getPrice(){
        return price;
    }
};

void displayMenu(MenuItem* menu, int size){
    cout<<"Menu:"<<endl;
    cout<<"Item\tPrice"<<endl;
    for(int i = 0; i < size; i++){
        cout<<menu[i].getName()<<"\t$"<<menu[i].getPrice()<<endl;
    }
}

int main(){

    const int size = 5;
    MenuItem menu[size] = {
        MenuItem("Burger", 5.99),
        MenuItem("Pizza", 8.49),
        MenuItem("Fries", 2.99),
        MenuItem("Salad", 4.99),
        MenuItem("Drink", 1.99),
    };

    Queue orderQueue(10);

    int choice;
    do{
        cout<<"\nCafeteria Ordering System"<<endl;
        cout<<"1. Display Menu"<<endl;
        cout<<"2. Place Order"<<endl;
        cout<<"3. Process Orders"<<endl;
        cout<<"4. Display Current Orders"<<endl;
        cout<<"5. Exit"<< endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice){
            case 1:
                displayMenu(menu, size);
                break;
            case 2:{
                int itemIndex;
                cout<<"Enter the item number to order: ";
                cin>>itemIndex;
                if(itemIndex >= 1 && itemIndex <= size) {
                    orderQueue.enQueue(itemIndex);
                    cout<<"Order placed successfully."<<endl;
                } 
                else{
                    cout<<"Invalid item number."<<endl;
                }
                break;
            }
            case 3:
                if(!orderQueue.isEmpty()){
                    cout<<"Processing order: "<<menu[orderQueue.getFront() - 1].getName()<<endl;
                    orderQueue.deQueue();
                } 
                else{
                    cout<<"No orders to process."<<endl;
                }
                break;
            case 4:
                orderQueue.displayItems();
                break;
            case 5:
                cout<<"Exiting program."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please enter a valid option."<<endl;
        }
    }while(choice != 5);

    return 0;
}
