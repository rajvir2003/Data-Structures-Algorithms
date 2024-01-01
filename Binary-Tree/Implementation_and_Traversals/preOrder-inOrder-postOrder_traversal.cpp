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
    if(data == -1){return NULL;}
    root = new node(data);

    cout << "Enter data for left of " << root->data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for right of " << root->data << endl;
    root->right = buildTree(root->right);

    return root;
}

void preOrder(node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(){
    node* root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 13 -1 -1 17 -1 -1
    root = buildTree(root);

    cout << "Pre-Order traversal: ";
    preOrder(root);
    cout << endl;

    cout << "In-Order traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Post-Order traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}