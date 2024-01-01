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

int minVal(node* root){
    node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

int maxVal(node* root){
    node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
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

int findPred(node* root){
    node* temp = root->left;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

// deletion in BST
node* deleteFromBST(node* &root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        // case 1: node with 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // case 2: node with 1 child
        // 2.a) if there is a left child
        else if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        // 2.b) if there is a right child
        else if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        // case 3: node with 2 child
        else{
            int pred = findPred(root);
            root->data = pred;
            root->left = deleteFromBST(root->left, pred);
            return root;
        }
    }
    else if(root->data > key){
        root->left = deleteFromBST(root->left, key);
    }
    else{
        root->right = deleteFromBST(root->right, key);
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

int main(){
    node* root = NULL;
    // 100 50 110 25 70 60 120 115 -1
    takeInput(root);

    cout << "InOrder: " << endl;
    inOrder(root);
    cout << endl;

    cout << "LevelOrder: " << endl;
    levelOrder(root);

    // cout << "max value: " << maxVal(root) << endl;
    // cout << "min value: " << minVal(root) << endl;

    cout << endl << "After DELETION: " << endl;

    root = deleteFromBST(root, 50);

    cout << "InOrder: " << endl;
    inOrder(root);
    cout << endl;

    cout << "LevelOrder: " << endl;
    levelOrder(root);

    return 0;
}