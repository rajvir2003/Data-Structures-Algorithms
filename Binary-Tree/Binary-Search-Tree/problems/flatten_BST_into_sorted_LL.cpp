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
    cout << "Input: ";
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void traverseLL(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->right;
    }
}

void solve(node* root, vector<node*> &v){
    if(root == NULL){
        return;
    }
    solve(root->left, v);
    v.push_back(root);
    solve(root->right, v);
}

node* BST_to_sorted_LL(node* root){
    vector<node*> v;
    solve(root, v);

    int n = v.size()-1;
    for(int i = 0; i < n; i++){
        v[i]->left = NULL;
        v[i]->right = v[i+1];
    }

    v[n]->left = NULL;
    v[n]->right = NULL;
    return v[0];
}

int main(){
    node* root = NULL;
    // 10 5 2 3 12 11 15 -1
    takeInput(root);

    cout << "LevelOrder: " << endl;
    levelOrder(root);

    node* head = BST_to_sorted_LL(root);
    traverseLL(head);

    return 0;
}