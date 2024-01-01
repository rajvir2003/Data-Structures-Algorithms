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

node* insertIntoBST(node* &root, int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }
    if(root->data > data){
        root->left = insertIntoBST(root->left, data);
    }
    else{
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void takeInput(node* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void solve(node* root, vector<int> &v){
    if(root == NULL){
        return;
    }
    solve(root->left, v);
    v.push_back(root->data);
    solve(root->right, v);
}

int kth_smallest_element(node* root, int k){
    vector<int> v;
    solve(root, v);
    return v[k-1];
}

int main(){
    node* root = NULL;
    // 100 50 110 25 70 60 120 115 -1
    takeInput(root);

    cout << "InOrder: " << endl;
    inOrder(root);
    cout << endl;

    cout << "LevelOrder: " << endl;
    levelOrder(root);

    int k = 3;
    cout << "kth smallest element: " << kth_smallest_element(root,k) << endl; 

    return 0;
}