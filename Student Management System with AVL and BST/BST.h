# ifndef BST_BST_H
# define BST_BST_H
# include <iostream>
# include "Data.h"

using namespace std ;

struct Node{
    int Id;
    Node* left;
    Node* right;

    explicit Node(int ID) : Id(ID), left(nullptr), right(nullptr){}
};

class BST {
   Node* root ;

public:
    explicit BST(){
        root = nullptr ;
    }
    
    void insert(int Id){
        Node* node=  new Node(Id) ;
        node->right = node->left = nullptr ;

        if (!root){
            root = node ;
            root->right = root->left = nullptr ;
        }
        else{
            Node* temp = root ;
            Node* temp2 = nullptr ;

            while (temp){
                temp2 = temp ;
                if (temp->Id > Id){
                    temp = temp->left ;
                }
                else{
                    temp = temp->right ;
                }
            }
            if (temp2 == nullptr){
                temp2 = node ;
            }
            else if (temp2->Id > Id){
                temp2->left = node ;
            }
            else if (temp2->Id < Id){
                temp2->right = node ;
            }
        }
    }

    bool search(Node* Root, int ID) {
        if (!Root){
            return false;
        }
        else if (Root->Id == ID){
            return true ;
        }
        else{
            if (Root->Id > ID){
                return search(root->left, ID) ;
            }
            else{
                return search(Root->right, ID) ;
            }
        }
    }

    Node* remove(Node* Root, int Id){
        if (!Root){
            return Root;
        }
        if (Root->Id < Id){
            Root->right = remove(Root->right, Id) ;
        }
        else if (Root->Id > Id){
            Root->left = remove(Root->left, Id) ;
        }
        else{
            if (!Root->right && !Root->left){
                delete Root ;
                Root = nullptr ;
                return Root ;
            }
            else if (!Root->right || !Root->left){
                if (Root->right) {
                    Node* temp = Root;
                    Root = Root->right;
                    delete temp ;
                    return Root ;
                }
                else{
                    Node* temp = Root;
                    Root = Root->left;
                    delete temp ;
                    return Root ;
                }
            }
            else{
                Node* temp = findMinimum(Root->right) ;
                Root->Id = temp->Id ;
                Root->right = remove(Root->right, temp->Id) ;
            }
        }
        return Root ;
    }

    Node* findMinimum(Node* Root){
        if (!Root){
            return nullptr ;
        }
        else{
            return findMinimum(Root->left) ;
        }
    }

    void inOrder(Node* Root, Data data){
        if (!Root){
            return;
        }
        else{
            inOrder(Root->left, data) ;
            data.printStudent(Root->Id) ;
            inOrder(Root->right, data) ;
        }
    }

    Node* getRoot(){
        return root ;
    }
};

# endif //BST_BST_H