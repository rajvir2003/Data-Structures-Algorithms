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

int height(node* root, bool &balance){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left, balance);
    int right = height(root->right, balance);

    if(abs(left-right) > 1){
        balance = false;
    }

    return max(left,right)+1;
}

int main(){
    node* root = NULL;
    // 1 3 4 5 -1 -1 -1 6 -1 -1 7 -1 -1
    root = buildTree(root);
    bool balance = true;
    int h = height(root, balance);

    if(balance){
        cout << "Tree is balanced" << endl;
    }
    else{
        cout << "Tree is not balanced" << endl;
    }

    return 0;
}