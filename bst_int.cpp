#include<iostream>
#include <memory>
#include <vector>
#include <cstdlib>
using namespace std;

#ifndef __BST_HPP
#define __BST_HPP

struct node
{
    int data;
    node* right;
    node* left;
    int height;
    node(int d); //default constructor
};

node::node(int d){
    this->data = d;
    left = NULL;
    right = NULL;
}

class BST
{
    
public:
    node* root;
    BST(); //default constructor
    void insertNode(node* p);
    void deleteNode(int k);
    node* deleteNodeHelper(node* root, int k);
    node* find_suc(node* p);    //funtion to find successor (next greatest node)
    void printTree(node* x);
    node* searchNode(int k);
    node* getRoot();
    int height(node* p);
    int number_to_shortlist(node* root);

    vector<int> right_most(node* root);
    vector<int> in_order(node* root);
    vector<int> pre_order(node* root);
    vector<int> post_order(node* root);
    vector<int> level_order(node* root);
};

BST::BST(){ //default constructor 
    root = NULL;
}

node* BST::getRoot(){   //returns root of the BST
    return root;
}

void BST::insertNode(node* p){      //insert a given node
    if(root == NULL){
        root = p;
        return;
    }
    node* temp = root;      //create a temporary ptr to traverse the list
    while(temp != NULL){
        if(p->data <= temp->data){ //check if p->data is less than current node data
            if(temp->left == NULL){
                temp->left = p;
                return;
            }
            else{
                temp=temp->left;
            }
        }
        else if(p->data > temp->data){
            if(temp->right == NULL){
                temp->right = p;
                return;
            }
            else{
                temp = temp->right;
            }
        }
    }
}



    node* BST::deleteNodeHelper(node* root, int k){ //delete node HELPER function using recursion
        /*
    USE RECURSION !
    Case 1: delete leaf node
    Case 2: delete node w/ one child
    Case 3: delete node w/ children
    */
    if(root == NULL){   //check if tree is empty
        return NULL;
    }

    if(k< root->data){      //if data is less than the root, move left
        root->left = deleteNodeHelper(root->left, k); 
    }
    else if(k > root->data){        //if data is greater than the root move right
        root->right = deleteNodeHelper(root->right, k);
    }
    else {                          //else if data is found at the root, find the closest successor. 
                                    //the successor node will be the smallest node in the right branch of the tree. 
        //Case 1: delete leaf node (root, if it has no children)
        if(root->left == NULL){         //check if there is no child on the left, delete the root and return the pointer to the right node. 
            node* temp = root->right;   //once the prev condition is fulfilled, node on left of root will be removed and delete function will run again but go to the next condition
            delete root;
            return temp;
        }
        //Case 2: delete node w/ one child      
        else if(root->right == NULL){       
            node* temp = root->left;
            delete root;
            return temp;
        }
        //Case 2: delete node w/ children
        node* temp = find_suc(root->right);     //store successor (min node in the right branch) in temp node. 
        
        root->data = temp->data;                //copy data from temp node to root. 

        root->right = deleteNodeHelper(root->right, temp->data);  //delete the in order successor from its original location. 
    }

    return root;
}

node* BST:: find_suc(node* p){  //find the closest successor node - smallest node in the right branch of the BST
    while(p->right != NULL){
        p = p->right;
    }
    return p;
}


void BST:: deleteNode(int k){   //delete node function
    deleteNodeHelper(root, k);      //calls deleteNodeHelper 
}


node* BST::searchNode(int k){
    if(root == NULL){
        return NULL;
    }
    node* temp = root;

    while(temp != NULL){
        if(k == temp->data){
            return temp;
        }
        else if(k < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    cout<<"\nnode not found\n";
    return NULL;
}




// int BST:: height(node* p){  //return height of a given node.
//     int left_height=0;
//     int right_height = 0;
//     int height = 0;
//     node* temp = p;
//     node* tr = p;
//     node* tl = p;
//     if(root == NULL){
//         return -1;
//     }
//     else if(temp->left == NULL || temp->right == NULL){
//             return height+=1;
//     }

//     while(tr != NULL && tl != NULL){
//         tr=tr->right;
//         right_height++;
//         tl = tl->left;
//         left_height++;
//     }
//     if(left_height>right_height){
//         return left_height;
//     }
//     return right_height;
    
// }

int BST:: height(node* p){
    if(p== NULL){
        // cout<<" here1 ";
        return -1;
    }
    // cout<<" here2 ";
    int left_height, right_height;
    left_height = height(p->left);  // call the height function again
    right_height = height(p->right);    

    if(left_height>right_height){
        return 1+left_height;
    }
    return 1+right_height;
}

void BST::printTree(node* x){   //printing using in-order traversal
    if(x!= NULL){
        printTree(x->left);
        cout<<x->data<<" ";
        printTree(x->right);
    }
}



int main(){
    BST bSearch1;
    node* r = bSearch1.root;
    node* a = new node(5);
    node* b = new node(2);
    node* c = new node(3);
    node* d = new node(45603);
    node* e = new node(1);
    node* f = new node(4);

    bSearch1.insertNode(f);
    bSearch1.insertNode(a);
    bSearch1.insertNode(b);
    bSearch1.insertNode(c);
    bSearch1.insertNode(d);
    bSearch1.insertNode(e);

    bSearch1.printTree(bSearch1.root);  

    bSearch1.deleteNode(1);
    bSearch1.deleteNode(45603);
    bSearch1.deleteNode(223);
    cout<<"\n";
    bSearch1.printTree(bSearch1.root);



    // cout<<"\n"<<bSearch1.height(c)<<" ";
    // cout<<"\n"<<bSearch1.searchNode(4)->data;
    //you can't pass node* r as an arg to the print function 
    //since the root var in BST is already a node* ptr


    return 0;
}



#endif