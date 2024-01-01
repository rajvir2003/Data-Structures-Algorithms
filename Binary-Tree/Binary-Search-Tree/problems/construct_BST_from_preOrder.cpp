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

void inOrder(node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++){
            node* temp = q.front();
            q.pop();
            level.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        for(auto i: level){
            cout << i << " ";
        }
        cout << endl;
    }
}

node* build_BST(int mini, int maxi, int &index, vector<int> &pre){
    if(pre[index] < mini || pre[index] > maxi || index >= pre.size()){
        return NULL;
    }
    
    int data = pre[index++];
    node* root = new node(data);

    root->left = build_BST(mini, root->data, index, pre);
    root->right = build_BST(root->data, maxi, index, pre);
    return root;
}

int main(){
    vector<int> pre = {10, 4, 3, 7, 40, 55};
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int index = 0;
    node* root = build_BST(mini, maxi, index, pre);

    cout << "LevelOrder: " << endl;
    levelOrder(root);
    cout << "InOrder: ";
    inOrder(root);

    return 0;
}