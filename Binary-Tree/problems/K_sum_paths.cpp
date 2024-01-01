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

void k_Sum_paths(node* root, int k, int &count, vector<int> path){
    if(root == NULL){
        return;
    }
    path.push_back(root->data);

    k_Sum_paths(root->left, k, count, path);
    k_Sum_paths(root->right, k, count, path);

    int sum = 0;
    for(int i = path.size()-1; i >= 0; i--){
        sum += path[i];
        if(sum == k) count++;
    }
}

int main(){
    // 1 3 2 -1 -1 1 1 -1 -1 -1 0 4 1 -1 -1 2 -1 -1 5 -1 6 -1 -1
    node* root = buildTree(root);
    vector<int> path;
    int k = 5;
    int count = 0;
    k_Sum_paths(root, k, count, path);
    cout << "There are " << count << " paths" << endl;

    return 0;
}