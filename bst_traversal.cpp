#ifndef __TRAVERSAL_CPP
#define __TRAVERSAL_CPP

#include <iostream>
#include <memory>
#include <vector>
#include "bst.hpp"

//This function calculates the maximum applicants that u can shortlist
//time complexity: O(h) - completely unbalanced tree and all the nodes are on the right side.
template <class T, class S, class C>        //all applications from the root to the rightmost leaf are shortlisted
int BST<T, S, C>::number_to_shortlist(shared_ptr<node<T, S, C>> p)
{   int total = 0;
    shared_ptr<node<T, S, C>> temp = p;

    if(p == NULL){   //check if tree is empty / no applicants to shortlist
        return 0;
    }
    while(temp != NULL){    //loop to traverse the rightmost path of the tree
        total++;                        //takes into account picking the left applicant when there is no right applicant
        if(temp->right != NULL){        //Case 1: check if current node has a right child - move to the right
            temp = temp->right;
        }
        else{           //Right most applicant is reached. 
            break;
        }
    }

    return total;
}



// This function returns shortlisted candidates on the right most path to leaf
//time complexity: O(n)
template <class T, class S, class C>
vector<T> BST<T, S, C>::right_most(shared_ptr<node<T, S, C>> p)
{
    vector<int> keys;
    shared_ptr<node<T, S, C>> temp = p;

    while(temp!= NULL){
        keys.push_back(temp->workExperience);
        temp = temp->right;
    }
    return keys;
}

//in_order recursive helper function
//time complexity: O(max+1) or O(number_to_shortlist + 1)
template <class T, class S, class C>
void BST<T, S, C>::in_orderHelper(shared_ptr<node<T, S, C>> p, vector<T> &keys, int &count, int max)
{   
    if(p == NULL || count >= max){
        return;
    }

    in_orderHelper(p->left, keys, count, max);
    if(count < max){
        keys.push_back(p->workExperience);
        count++;
    }
    in_orderHelper(p->right, keys, count, max);

}

// This function returns shortlisted candidates in-order
//time complexity: O(max+1) or O(number_to_shortlist + 1)
template <class T, class S, class C>
vector<T> BST<T, S, C>::in_order(shared_ptr<node<T, S, C>> p)
{   
    vector<T> keys;
    int count = 0;
    int max = number_to_shortlist(p);
    in_orderHelper(p, keys, count, max);
    
    return keys;
}

//time complexity: O(max+1) or O(number_to_shortlist + 1)
template <class T, class S, class C>
void BST<T, S, C>::pre_orderHelper(shared_ptr<node<T, S, C>> p, vector<T> &keys, int &count, int max)
{
    if(p == NULL || count >= max){
        return;
    }

    if(count < max){
        keys.push_back(p->workExperience);
        count++;
    }
    pre_orderHelper(p->left, keys, count, max);
    pre_orderHelper(p->right, keys, count, max);
}


// This function returns shortlisted candidates in pre order
//time complexity: O(max+1) or O(number_to_shortlist + 1)
template <class T, class S, class C>
vector<T> BST<T, S, C>::pre_order(shared_ptr<node<T, S, C>> p)
{
    vector<T> keys;
    int count =0;
    int max = number_to_shortlist(p);
    pre_orderHelper(p, keys, count, max);
    
    return keys;
}

//time complexity: O(max+1) or O(number_to_shortlist + 1)
template <class T, class S, class C>
void BST<T, S, C>::post_orderHelper(shared_ptr<node<T, S, C>> p, vector<T> &keys, int &count, int max)
{
    
    if(p == NULL || count >= max){
        return;
    }

    post_orderHelper(p->left, keys, count, max);
    post_orderHelper(p->right, keys, count, max);
    if(count < max){
        keys.push_back(p->workExperience);
        count++;
    }
    
}

// This function returns shortlisted candidates in post order
//time complexity: O(max+1) or O(number_to_shortlist + 1)
template <class T, class S, class C>
vector<T> BST<T, S, C>::post_order(shared_ptr<node<T, S, C>> p)
{   vector<T> keys;
    shared_ptr<node<T, S, C>> temp = p;
    int count = 0;
    int max = number_to_shortlist(p);
    post_orderHelper(p, keys, count, max);
    return keys;
}


//time complexity: O(max+1) or O(number_to_shortlist + 1)
template <class T, class S, class C>
vector<T> BST<T, S, C>::level_order(shared_ptr<node<T, S, C>> p)
{
    if (p == NULL) {
        return {NULL};
    }

    int count = 0;
    int max = number_to_shortlist(p);

    vector<T> keys;
    vector<shared_ptr<node<T, S, C>>> q;    //used a vector<node> list to mimic a queue
    q.push_back(p);                            //add root to the vector list

    while (!q.empty() && count < max) {         //keep track of count
        count++;
        shared_ptr<node<T, S, C>> temp = q.front();     //store the first element of the vector in temp node
        q.erase(q.begin());                             //use vector operations .erase() and .begin() to mimic queue behaviour 
        keys.push_back(temp->workExperience);

        if (temp->left != NULL) {
            q.push_back(temp->left);
        }
        if (temp->right != NULL) {
            q.push_back(temp->right);
        }
    }

    return keys;
}


#endif