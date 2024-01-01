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
        for(auto i : level){
            cout << i << " ";
        }
        cout << endl;
    }
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left)+1;
    int right = height(root->right)+1;
    return max(left,right);
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
    cout << "Input: ";
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void storeInOrder(node* root, vector<int> &v){
    if(root == NULL){
        return;
    }
    storeInOrder(root->left, v);
    v.push_back(root->data);
    storeInOrder(root->right, v);
}

node* balancedBST(node* root, int s, int e, vector<int> v){
    if(s > e){
        return NULL;
    }

    int index = (s+e)/2;
    int data = v[index];
    root = new node(data);

    root->left = balancedBST(root->left, s, index-1, v);
    root->right = balancedBST(root->right, index+1, e, v);
    return root;
}

int main(){
    node* root = NULL;
    // 10 8 6 5 4 3 2 1 -1
    takeInput(root);

    cout << "Normal BST: " << endl;
    levelOrder(root);
    cout << "Height: " << height(root) << endl;

    vector<int> v;
    storeInOrder(root, v); 
    node* newRoot = balancedBST(newRoot,0,v.size()-1, v);
    cout << "Balanced BST: " << endl;
    levelOrder(newRoot);
    cout << "Height: " << height(newRoot) << endl;

    return 0;
}