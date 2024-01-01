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
    cout << "Enter Input: ";
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void BST_to_DLL(node* root, node* &head){
    if(root == NULL){
        return;
    }

    BST_to_DLL(root->right, head);

    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;

    BST_to_DLL(root->left, head);
}

void traverseLL(node* head){
    node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->right;
    }
}

int main(){
    node* root = NULL;
    // 40 20 8 30 50 45 70 -1
    takeInput(root);
    cout << "LevelOrder of BST: " << endl;
    levelOrder(root);
    cout << "InOrder of BST: ";
    inOrder(root);
    cout << endl << endl;

    node* head = NULL;
    BST_to_DLL(root, head);

    cout << "Linked list -> ";
    traverseLL(head);

    return 0;
}