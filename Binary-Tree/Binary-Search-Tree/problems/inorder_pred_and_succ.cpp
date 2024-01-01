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

int findPred(node* root){
    node* temp = root->left;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

int findSucc(node* root){
    node* temp = root->right;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

pair<int,int> find_Pred_Succ(node* root, int key){
    int pred = -1;
    int succ = -1;
    node* temp = root;
    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }

    if(temp->left){
        pred = findPred(temp);
    }
    if(temp->right){
        succ = findSucc(temp);
    }

    pair<int,int> ans = {pred,succ};
    return ans;
}

int main(){
    node* root = NULL;
    // 50 25 29 70 65 75 -1
    takeInput(root);

    cout << "LevelOrder: " << endl;
    levelOrder(root);

    cout << "InOrder: " << endl;
    inOrder(root);
    cout << endl;

    int key = 29;
    pair<int,int> ans = find_Pred_Succ(root, key);
    cout << "Predecessor of " << key << " is " << ans.first << endl;
    cout << "Successor of " << key << " is " << ans.second << endl;
    
    return 0;
}