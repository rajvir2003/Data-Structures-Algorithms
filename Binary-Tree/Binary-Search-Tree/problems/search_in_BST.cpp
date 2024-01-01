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

node* search(node* root, int target){
    node* temp = root;
    while(temp != NULL){
        if(temp->data == target){
            return temp;
        }
        if(temp->data < target){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return temp;
}

int main(){
    node* root = NULL;
    // 10 5 2 7 1 3 20 15 22 21 -1
    takeInput(root);

    cout << "LevelOrder: " << endl;
    levelOrder(root);
    cout << "InOrder: " << endl;
    inOrder(root); cout << endl << endl;

    int target = 22;
    node* ans = search(root, target);

    if(ans == NULL){
        cout << target << " is not present" << endl;
    }
    else{
        cout << ans->data << " is present" << endl;
    }

    return 0;
}