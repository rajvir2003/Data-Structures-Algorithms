#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    int data;
    cout << "Enter data: " << endl;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    root = new node(data);

    cout << "Enter data for left of " << root->data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for right of " << root->data << endl;
    root->right = buildTree(root->right);
    return root;
}

node* findPredecessor(node* curr){
    node* pred = curr->left;
    while(pred->right != NULL){
        pred = pred->right;
    }
    return pred;
}

void flatten(node* root){
    node* curr = root;
    while(curr != NULL){
        if(curr->left){
            node* pred = findPredecessor(curr);
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void traverseLL(node* root){
    node* curr = root;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main(){
    node* root = NULL;
    // 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
    root = buildTree(root);
    flatten(root);

    traverseLL(root);

    return 0;
}