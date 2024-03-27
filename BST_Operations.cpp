#include<iostream>

using namespace std;

class Node{
    private:
        Node* left;
        Node* right;
        int info;
    public:
        Node(int info){
            left = NULL;
            right = NULL;
            this->info = info;
        }

    friend class BST;
};

class BST{
    private:
        Node* root;

    public:
        BST(){
            root = NULL;
        }

        Node* insertNode(Node* root, int value){

            if(root == NULL){
                return new Node(value);
            }
            else{
                if(root->info > value){
                    root->left = insertNode(root->left, value);
                }
                else if(root->info < value){
                    root->right = insertNode(root->right, value);
                }
                else{
                    cout<<"BST CAN NOT HAVE EQUAL VALUES AT NODES"<<endl;
                }
            }

            return root;
        }

        Node* inOrderSuccessor(Node* root){
            Node* current = root;
            while(current && current->left !=NULL){
                current = current->left;
            }
            return current;
        }

        void inorderTraversal(Node* root){
            if(root == NULL){
                return;
            }

            inorderTraversal(root->left);
            cout<<root->info<<" ";
            inorderTraversal(root->right);
        }   

        void preorderTraversal(Node* root){
            if(root == NULL){
                return;
            }

            cout<<root->info<<" ";
            inorderTraversal(root->left);
            inorderTraversal(root->right);
        }   
        void postorderTraversal(Node* root){
            if(root == NULL){
                return;
            }

            inorderTraversal(root->left);
            inorderTraversal(root->right);
            cout<<root->info<<" ";
        }

        int countNodes(Node* root){
            if(root == NULL){
                return 0;
            }
            
            int leftCount = countNodes(root->left);
            int rightCount = countNodes(root->right);

            return 1 + leftCount + rightCount;

        }

        Node* smallestNode(Node* root){
            if(root == NULL){
                return NULL;
            }
            if(root->left == NULL){
                return root;
            }

            return smallestNode(root->left);
        } 

        Node* searchNode(Node* root, int key){
            if(root == NULL){
                return NULL;
            }
            if(root->info == key){
                return root;
            }

            if(root->info > key){
                return searchNode(root->left, key);
            }
            else if(root->info < key){
                return searchNode(root->right, key);
            }
            
        }

        void findAndPrintSubtree(Node* root, int value){
            Node* foundNode = searchNode(root, value);
            if(foundNode != NULL){

                cout<<"Subtree Rooted At Node With Value "<<value<<":"<<endl;
                inorderTraversal(foundNode);
                cout<<endl;
            } 
            else{

                cout<<"Node With Value "<<value<<"Not Found In The BST."<<endl;
            }
        }

        Node* findSibling(Node* root, int value){
            if(root == NULL){
                return NULL;
            }

            if(root->right != NULL && root->left->info == value){
                return root->right;
            }
            else if(root->left != NULL && root->right->info == value){
                return root->left;
            }


            if(value < root->info){
                findSibling(root->right, value);
            }
            else if(value > root->info){
                findSibling(root->left, value);
            }
        }

        Node* findParent(Node* root, int value){
            if(root == NULL){
                return NULL;
            }
            if(root->right->info == value || root->left->info == value){
                return root;
            }

            if(value < root->info){
                findParent(root->left, value);
            }
            else if(value > root->info){
                findParent(root->right, value);
            }
        }

        Node* findChildren(Node* root, int value){
            if(root == NULL){
                return NULL;
            }
            if(root->info == value){
                return root;
            }
            if(value > root->info){
                findChildren(root->right, value);
            }
            else if( value < root->info){
                findChildren(root->left, value);
            }
        }

        void menuDrive(){
            int choice, value;
            Node* foundNode;
            Node* parent; 
            Node* sibling;
            Node* children;

            do{
                cout<<"----- BST Menu -----"<<endl<<endl;
                cout<<"1.  Insert Node"<<endl;
                cout<<"2.  Search Node"<<endl;
                cout<<"3.  Inorder Traversal"<<endl;
                cout<<"4.  Preorder Traversal"<<endl;
                cout<<"5.  Postorder Traversal"<<endl;
                cout<<"6.  Count Nodes"<<endl;
                cout<<"7.  Find Smallest Node"<<endl;
                cout<<"8.  Find and Print Subtree"<<endl;
                cout<<"9.  Find Sibling"<<endl;
                cout<<"10. Find Parent"<<endl;
                cout<<"11. Find Children"<<endl;
                cout<<"12. Exit"<<endl;
                
                cout<<"Enter your choice: ";
                cin>>choice;

                switch(choice){
                    case 1:
                        cout<<"Enter Value To Insert: ";
                        cin>>value;
                        root = insertNode(root, value);
                        break;
                    case 2:
                        cout<<"Enter Key To Search: ";
                        cin>>value;
                        foundNode = searchNode(root, value);
                        if(foundNode != NULL){
                            cout<<"Node With Key "<<value<<" found in BST"<<endl;
                        } else {
                            cout<<"Node With Key "<<value <<" Not Found in BST"<<endl;
                        }
                        break;
                    case 3:
                        cout<<"Inorder Traversal: ";
                        inorderTraversal(root);
                        cout<<endl;
                        break;
                    case 4:
                        cout<<"Preorder Traversal: ";
                        preorderTraversal(root);
                        cout<<endl;
                        break;
                    case 5:
                        cout<<"Postorder Traversal: ";
                        postorderTraversal(root);
                        cout<<endl;
                        break;
                    case 6:
                        cout<<"Number Of Nodes in BST: "<<countNodes(root)<<endl;
                        break;
                    case 7:
                        foundNode = smallestNode(root);
                        if(foundNode != NULL){
                            cout<<"Smallest Node in BST: "<<foundNode->info<<endl;
                        } else {
                            cout<<"BST is Empty"<<endl;
                        }
                        break;
                    case 8:
                        cout<<"Enter Value to Find and Print Subtree: ";
                        cin>>value;
                        findAndPrintSubtree(root, value);
                        break;
                    case 9:
                        cout<<"Enter Value: ";
                        cin>>value;

                        sibling = findSibling(root, value);
                        if(sibling != NULL){
                            cout<<"No Sibling of "<<value<<" in tree."<<endl;
                        }
                        else{
                            cout<<"Sibling of "<<value<<" is "<<sibling->info<<endl;
                        }
                        break;
                    case 10:
                        cout<<"Enter Value: ";
                        cin>>value;

                        parent = findParent(root, value);

                        if(parent != NULL){
                            cout<<"No Parent of "<<value<<" in tree."<<endl;
                        }
                        else{
                            cout<<"Parent of "<<value<<" is "<<parent->info<<endl;
                        }
                        break;
                    case 11:
                        cout<<"Enter Value: ";
                        cin>>value;

                        children = findChildren(root, value);

                        if(children == NULL){
                            cout<<"Either No Children Exist of "<<value<<" or "<<value<<" doesn't exist in tree."<<endl;
                        }
                        else if(children->right == NULL && children->left != NULL){
                            cout<<"The Left Child of "<<value<<" is "<<children->left->info<<" and the Right Child Doesn't Exist."<<endl;
                        }
                        else if(children->left == NULL && children->right != NULL){
                            cout<<"The Right Child of "<<value<<" is "<<children->right->info<<" and the Left Child Doesn't Exist."<<endl;
                        }
                        else if(children->left != NULL && children->right != NULL){
                            cout<<"The Left Child of "<<value<<" is "<<children->left->info<<" and the Right Child of "<<value<<" is "<<children->right->info<<endl;
                        }
                        break;
                    case 12:
                        cout<<"Exiting Program..."<<endl;
                        break;
                    default:
                        cout<<"Invalid Choice! Please Try Again."<<endl;
                }
            }
            while(choice != 8);
        }
};

int main() {
    BST BinarySearchTree;

    BinarySearchTree.menuDrive();

    return 0;
}