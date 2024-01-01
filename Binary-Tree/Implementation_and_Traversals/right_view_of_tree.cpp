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

void RightView(node* root, int level, map<int,int> &mp){
    if(root == NULL){
        return;
    }
    mp[level] = root->data;
    RightView(root->left, level+1, mp);
    RightView(root->right, level+1, mp);
}

int main(){
    node* root = NULL;
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    root = buildTree(root);

    map<int,int> mp;
    RightView(root, 0, mp);
    for(auto i : mp){
        cout << i.second << " ";
    }

    return 0;
}