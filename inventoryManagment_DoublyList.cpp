#include<iostream>
#include<cstring>
#include<string>

using namespace std;

class Node{
    private:
        int info;
        string name;
        int quantity;
        int price;
        Node* next;
        Node* previous;

    public:
        Node(int uniqueID, string name, int quantity, int price){
            this->info = uniqueID;
            this->name = name;
            this->quantity = quantity;
            this->price = price;
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


    void addProduct(int uniqueID, string name, int quantity, int price){
        Node* newNode = new Node(uniqueID, name, quantity, price);

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

    void removeProduct(int uniqueID){
        if(head == NULL){
            return;
        }
        if(head->info == uniqueID){
            Node *current = head;
            head = head->next;
            delete current;
            return;
        }
        else{

            Node* temp = head;
            while (temp != NULL){

                if(temp->info == uniqueID){

                    if(temp->previous != NULL){

                        temp->previous->next = temp->next;
                    }
                    if(temp->next != NULL){
                        
                        temp->next->previous = temp->previous;
                    }
                    delete temp;
                }
                temp = temp->next;
            }
        }
    }

    void displayProducts(){

        Node *temp = head;
        while(temp != NULL){

            cout<<"Product ID: " << temp->info<<endl;
            cout<<"Product Name: "<<temp->name<<endl;
            cout<<"Quantity : "<<temp->quantity<<endl;
            cout<<"Price : "<<temp->price<<endl<<endl<<endl;
            
            temp = temp->next;
        }
    }

    void updateProduct(int uniqueID,  int newPrice){
        Node *temp = head;

        while(temp != NULL){
            if(temp->info == uniqueID){

                temp->info = newPrice;
            }

            temp = temp->next;
        }
    }

    void findProduct(int uniqueID){
        Node *temp = head;
        bool flag = false;
        while(temp != NULL){

            if(temp->info == uniqueID){

                flag = true;
                break;
            }
            temp = temp->next;
        }
        if(flag){
            cout<<"Product was Found!"<<endl;
        }
        else {
            cout<<"Product was not Found!"<<endl;
        }
    }

    ~DoubleList(){
        Node* current = head;
        while(current != NULL){

            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main(){

    DoubleList productInventory;

    int option;

    string name;
    int uniqueID;
    int quantity;
    int price;
    

    while (true){
        cout<<"Welcome to FAST Inventory System"<<endl<<endl;
        cout<<"1) Add Product.\n2) Remove Product.\n3) Display.\n4) Update Price.\n5) Find Product.\n6) Quit.\n";
        cout<<"Choose an Option: ";
        cin>>option;

        if(option == 1)
        {
            cout<<"Enter Product Name: ";
            cin>>name;
            cout<<"Enter Product ID : ";
            cin>>uniqueID;
            cout<<"Enter Quantity : ";
            cin>>quantity;
            cout<<"Enter Price : ";
            cin>>price;
            productInventory.addProduct(uniqueID, name, quantity, price);
        }
        else if(option == 2)
        {
            cout<<"Remove ID of The Product You Want to Remove: ";
            cin>>uniqueID;
            productInventory.removeProduct(uniqueID);
        }
        else if(option == 3)
        {
            productInventory.displayProducts();
        }
        else if(option == 4)
        {
            int newPrice;
            cout<<"Enter Unique ID of the Product You want to Update: ";
            cin>>uniqueID;
            cout<<"Enter New Price: ";
            cin>>newPrice;
            productInventory.updateProduct(uniqueID,newPrice);
        }
        else if(option == 5)
        {
            cout<<"Enter Product ID: ";
            cin>>uniqueID;
            productInventory.findProduct(uniqueID);
        }
        else if(option == 6)
        {
            break;
        }
    }
    return 0;
}