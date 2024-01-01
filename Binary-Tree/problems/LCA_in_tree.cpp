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

node* LCA(node* root, int n1, int n2){
    if(root == NULL || root->data == n1 || root->data == n2){
        return root;
    }

    node* left = LCA(root->left, n1, n2);
    node* right = LCA(root->right, n1, n2);

    if(left != NULL && right != NULL){
        return root;
    }
    else if(left != NULL && right == NULL){
        return left;
    }
    else if(left == NULL && right != NULL){
        return right;
    }
    else{
        return NULL;
    }
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    int n1 = 7;
    int n2 = 9;
    node* ans = LCA(root, n1, n2);
    cout << "LCA: " << ans->data << endl;

    return 0;
}