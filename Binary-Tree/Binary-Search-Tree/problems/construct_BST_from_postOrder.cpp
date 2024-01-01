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

node* build_BST(int mini, int maxi, int &index, vector<int> &post){
    if(post[index] < mini || post[index] > maxi || index < 0){
        return NULL;
    }
    int data = post[index--];
    node* root = new node(data);

    root->right = build_BST(root->data, maxi, index, post);
    root->left = build_BST(mini, root->data, index, post);
    return root;
}

int main(){
    vector<int> post = {1, 7, 5, 50, 40, 10};
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int index = post.size()-1;
    node* root = build_BST(mini, maxi, index, post);

    cout << "LevelOrder: " << endl;
    levelOrder(root);
    cout << "InOrder: ";
    inOrder(root);

    return 0;
}