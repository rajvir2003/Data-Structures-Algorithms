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

int diameter(node* root, int &max_dist){
    if(root == NULL){
        return 0;
    }

    int left = diameter(root->left, max_dist);
    int right = diameter(root->right, max_dist);

    max_dist = max(max_dist, left+right+1);
    return max(left,right)+1;
}

int main(){
    node* root = NULL;
    // 1 3 4 5 -1 -1 -1 6 -1 -1 7 -1 -1
    root = buildTree(root);

    int max_dist = 0;
    int d = diameter(root, max_dist);
    cout << "Diameter of tree is " << max_dist << endl;

    return 0;
}