#include <iostream>
#include <string>

using namespace std;


class Node{
    private:
        string label;
        Node* next;
        Node* prev;
    public:
        Node(string label){
        this->label = label;
        next = NULL;
        prev = NULL;
    }

    friend class JosephusSimulator;
};

class JosephusSimulator{
    private:
        Node* head; 

    public:
        JosephusSimulator(){
            head = NULL;
        }

        
        void addPerson(string name){
            Node* newNode = new Node(name);

            
            if(!head){
                head = newNode;
                head->next = head;
                head->prev = head;
            } 
            else{
                
                newNode->next = head;
                newNode->prev = head->prev;
                head->prev->next = newNode;
                head->prev = newNode;
            }

            cout<<"Person "<<name<<" Added To The Circle."<<endl;
            displayCircle();
        }

        
        void startElimination(){
            if(!head){
                cout<<"No Persons In The Circle. Add Persons First."<<endl;
                return;
            }

            string startPerson;
            int jumpValue, direction;

            cout<<"Enter The Starting Person's Name: ";
            cin>>startPerson;

            Node* current = head;
            while(current->label != startPerson && current->next != head){

                current = current->next;
            }

            if(current->label != startPerson){

                cout<<"Person Not Found In The Circle."<<endl;
                return;
            }

            cout<<"Enter The Jump Value: ";
            cin>>jumpValue;

            cout<<"Choose The Direction (1. Clockwise / 2. Anticlockwise): ";
            cin>>direction;

            eliminatePersons(current, jumpValue, direction);
        }

        
        void eliminatePersons(Node* startNode, int jumpValue, int direction){

            Node* current = startNode;

            cout<<"Elimination sequence:"<<endl;
            while(head->next != head){
                for(int i = 1; i < jumpValue; ++i){
                    if(direction == 1){

                        current = current->next;
                    } 
                    else{

                        current = current->prev;
                    }
                }

                Node* eliminated = current;
                current = (direction == 1) ? current->next : current->prev;

                eliminatePerson(eliminated);
            }

            cout<<"The Survivor Is "<<head->label<<"."<<endl;
            delete head;
            head = nullptr;
        }

        
        void eliminatePerson(Node* eliminated){

            cout<<"Eliminate Person "<<eliminated->label<<endl;

            if(eliminated == head){

                head = eliminated->next;
            }

            eliminated->prev->next = eliminated->next;
            eliminated->next->prev = eliminated->prev;

            delete eliminated;
            displayCircle();
        }

        
        void displayCircle(){
            if(!head){

                cout<<"No Persons In The Circle."<<endl;
                return;
            }

            cout << "Current Persons In The Circle: ";
            Node* current = head;
            do{

                cout<<current->label<<", ";
                current = current->next;
            } 
            while(current != head);

            cout<<endl;
        }
};

int main() {
    JosephusSimulator simulator;

    int choice;
    do{

        cout<<"--- Josephus Problem Simulator ---"<<endl;
        cout<<"1. Add Person"<<endl;
        cout<<"2. Start Elimination Process"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>choice;

        switch(choice){

            case 1:{

                string name;
                cout<<"Enter The Name For The Person: ";
                cin>>name;
                simulator.addPerson(name);
                break;
            }
            case 2:

                simulator.startElimination();
                break;

            case 3:

                cout<<"Exiting The Program..."<<endl;
                break;

            default:

                cout<<"Invalid choice. Please Enter a Valid Option."<<endl;
        }

    } 
    while(choice != 3);

    return 0;
}
