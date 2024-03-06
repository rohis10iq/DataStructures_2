#include<iostream>
#include<cstring>
#include<string>


using namespace std;

class Node{
    private:
        int ID;
        string name;
        float CGPA;
        Node* next;

    public:
        Node(int ID, string name, float CGPA){
            this->ID = ID;
            this->name = name;
            this-> CGPA = CGPA;
            next = NULL;
        }
    friend class StudentList;
};

class StudentList{
    private:
        Node* head;
        int length;
    
    public:
        StudentList(){
            head = NULL;
            length = 0;
        }

    void insertData(int ID, string name, float CGPA){
        Node* newNode = new Node(ID, name, CGPA);
        if(head == NULL){      
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

    void removeStudent(int ID){
        bool found = false;
        if(head == NULL){
            cout<<"There are No Students in the List"<<endl;
            return;
        }

        Node* temp = head;
        Node* current = nullptr;

        while(temp != NULL){
            if(temp->ID == ID){
                if(current == nullptr){
                    
                    head = temp->next;
                } else {
                    
                    current->next = temp->next;
                }

                delete temp;
                found = true;
                break;
            }
            else{
                current = temp;
                temp = temp->next;
            }
        }

        length--;

        if(!found){
            cout<<"The Student with ID: "<<ID<<" was not found in the List"<<endl;
        }
        else{
            cout<<"The Student with ID: "<<ID<<" was deleted from the List"<<endl;
        }
    }


    void searchStudent(int ID){
        if(head == NULL){
            cout<<"The List is Empty"<<endl;
            return;
        }
        bool found = false;

        Node* temp = head;

        while(temp!= NULL){
            if(temp->ID == ID){
                cout<<"Student Found!"<<endl;
                cout<<"Student Name: "<<temp->name<<" ."<<endl;
                cout<<"Student ID: "<<temp->ID<<" ."<<endl;
                cout<<"Student CGPA: "<<temp->CGPA<<" ."<<endl;
                    
                found = true;   
            }
            else{

                temp = temp->next;
            }        
        }
        if(!found){
            cout<<"The Student with ID: "<<ID<<" was not found in the List"<<endl;
        }
    }

    void displayStudents(){
        if(head == NULL){
            cout<<"The List is Empty"<<endl;
            return;
        }

        Node* temp = head;
        int i = 1;

        while(temp != NULL){

            cout<<"Student "<<i<<"!"<<endl<<endl;
            cout<<"Student Name: "<<temp->name<<" ."<<endl;
            cout<<"Student ID: "<<temp->ID<<" ."<<endl;
            cout<<"Student CGPA: "<<temp->CGPA<<" ."<<endl<<endl;

            temp = temp->next;
            i++;
        }
    }

    void averageCGPA(){
        if(head == NULL){
            cout<<"The List is Empty"<<endl;
            return;
        }

        float sum = 0, average;

        Node* temp = head;
        while(temp != NULL){

            sum+=temp->CGPA;

            temp = temp->next;
        }

        average = sum/length;

        cout<<"The Average CGPA of "<< length<<" students is: \""<<average<<"\""<<endl;
    }  
    
};

void menuDrive(StudentList& Students){

    int choice;
    int ID;
    float CGPA;
    string name;

    cout<<"Select an Option:(1 to 6)"<<endl;
    cout<<"1) Add a Student."<<endl;
    cout<<"2) Remove a Student (through ID)."<<endl;
    cout<<"3) Search for a Student(through ID)."<<endl;
    cout<<"4) Calculate Average CGPA."<<endl;
    cout<<"5) Display Students\' Information"<<endl;
    cout<<"6) Exit."<<endl;

    cin>>choice;

    if(choice<1 || choice>6){
        cout<<"Invalid Option(Please Select from 1 to 6)"<<endl;
        menuDrive(Students);
    }
    else if(choice == 1){
        cout<<"Enter ID: "<<endl;
        cin>>ID;
        cout<<"Enter Name: "<<endl;
        cin.ignore();
        getline(cin, name);
        cout<<"Enter CGPA: "<<endl;
        cin>>CGPA;

        Students.insertData(ID, name, CGPA);
    }
    else if(choice == 2){
        cout<<"Enter ID: "<<endl;
        cin>>ID;

        Students.removeStudent(ID);
    }
    else if(choice == 3){
        cout<<"Enter ID: "<<endl;
        cin>>ID;

        Students.searchStudent(ID);
    }
    else if(choice == 4){

        Students.averageCGPA();

    }
    else if(choice == 5){

        Students.displayStudents();
    }
    else if(choice == 6){
        return;
    }

    menuDrive(Students);
    cout<<endl;
}

int main(){
    
    cout<<"Welcome Student Affairs"<<endl<<endl;
    StudentList Students;
    menuDrive(Students);

    return 0;
}