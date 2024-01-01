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

int sum(node* root, int &s, bool &flag){
        
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return (root->data);
        }
        
        int left = sum(root->left, s, flag);
        int right = sum(root->right, s, flag);
        s = left+right;

        if(s != root->data){
            flag = false;
        }
        return s+(root->data);
    }

int main(){
    node* root = NULL;
    root = buildTree(root);
    int s = 0;
    bool flag = true;
    int ans = sum(root, s, flag);
    cout << "Answer = " << ans << endl;
    // 62 16 -1 8 -1 8 -1 -1 15 4 4 -1 -1 -1 7 -1 -1
    return 0;
}