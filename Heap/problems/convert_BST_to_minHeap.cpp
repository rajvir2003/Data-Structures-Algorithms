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

node* buildTree(node* &root){
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
        } cout << endl;
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

void BST_to_minHeap(node* &root, int &index, vector<int> in){
    if(root == NULL){
        return;
    }
    root->data = in[index++];
    BST_to_minHeap(root->left, index, in);
    BST_to_minHeap(root->right, index, in);
}

int main(){
    node* root = NULL;
    // 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1
    root = buildTree(root);

    cout << "Binary Search Tree: " << endl;
    levelOrder(root);

    vector<int> in;
    storeInOrder(root, in);
    int index = 0;
    BST_to_minHeap(root, index, in);
    cout << "Min Heap: " << endl;
    levelOrder(root);

    return 0;
}