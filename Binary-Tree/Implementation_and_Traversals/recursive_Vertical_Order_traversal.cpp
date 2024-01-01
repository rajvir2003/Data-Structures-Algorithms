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
    cout << "Enter data " << endl;
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

void VOT(node* root, int dist, map<int,vector<int>> &mp){
    if(root == NULL){
        return;
    }
    mp[dist].push_back(root->data);
    VOT(root->left, dist-1, mp);
    VOT(root->right, dist+1, mp);
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    map<int,vector<int>> mp;
    VOT(root, 0, mp);
    for(auto i : mp){
        for(auto j : i.second){
            cout << j << " ";
        }
    }
    cout << endl;
    
    return 0;
}