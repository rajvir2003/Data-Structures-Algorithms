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

void inOrder(node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// insertion in BST
node* insertIntoBST(node* &root, int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(root->data > d){
        root->left = insertIntoBST(root->left, d);
    }
    else{
        root->right = insertIntoBST(root->right, d);
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

bool isValid(node* root, int min, int max){
    if(root == NULL){
        return true;
    }
    if(root->data > min && root->data < max){
        bool left = isValid(root->left, min, root->data);
        bool right = isValid(root->right, root->data, max);
        return left && right;
    }
    else{
        return false;
    }
}

int main(){
    node* root = NULL;
    // 10 5 2 7 1 3 20 15 22 21 -1
    takeInput(root);

    cout << "InOrder: " << endl;
    inOrder(root);
    cout << endl;

    cout << "LevelOrder: " << endl;
    levelOrder(root);

    if(isValid(root, INT_MIN, INT_MAX)){
        cout << "BST is Valid" << endl;
    }
    else{
        cout << "BST is not Valid" << endl;
    }

    return 0;
}