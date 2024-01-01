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

node* buildTree(node* &root){
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

int countNode(node* root){
    if(root == NULL){
        return 0;
    }
    int left = countNode(root->left);
    int right = countNode(root->right);
    return left+right+1;
}

bool isCBT(node* root, int index, int total){
    if(root == NULL){
        return true;
    }
    if(index > total){
        return false;
    }
    bool left = isCBT(root->left, (index*2)+1, total);
    bool right = isCBT(root->right, (index*2)+2, total);
    return (left && right);
}

bool isHeapOrder(node* root){
    // if leaf node then return true
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    // if right node doesn't exist
    if(root->right == NULL){
        return root->data > root->left->data;
    }
    // here both left and right nodes are present
    bool left = isHeapOrder(root->left);
    bool right = isHeapOrder(root->right);
    return left && right && root->data > root->left->data && root->data > root->right->data;
}

bool isHeap(node* root){
    int total = countNode(root);
    if(!isCBT(root,0,total)){
        return false;
    }
    return isCBT(root,0,total) && isHeapOrder(root);
}

int main(){
    node* root = NULL;
    // 50 40 20 -1 -1 10 -1 -1 30 -1 -1
    root = buildTree(root);
    if(isHeap(root)){
        cout << "This binary tree is a heap" << endl;
    }
    else{
        cout << "This binary tree is not a heap" << endl;
    }

    return 0;
}