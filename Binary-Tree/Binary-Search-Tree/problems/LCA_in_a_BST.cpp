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
        node* left = insertIntoBST(root->left, data);
    }
    else{
        node* right = insertIntoBST(root->right, data);
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

node* LCA(node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data > n1 && root->data > n2){
        return LCA(root->left, n1, n2);
    }
    else if(root->data < n1 && root->data < n2){
        return LCA(root->right, n1, n2);
    }
    else{
        return root;
    }
}

int main(){
    node* root = NULL;
    // 10 5 20 3 7 9 -1
    takeInput(root);

    cout << "InOrder: " << endl;
    inOrder(root);
    cout << endl;

    cout << "LevelOrder: " << endl;
    levelOrder(root);

    int n1 = 3;
    int n2 = 9;

    node* ans = LCA(root, n1, n2);
    cout << "LCA -> " << ans->data << endl;

    return 0;
}