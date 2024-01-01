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

void solve(node* root, vector<int> &v){
    if(root == NULL){
        return;
    }
    solve(root->left, v);
    v.push_back(root->data);
    solve(root->right, v);
}

bool two_sum(node* root, int target){
    vector<int> v;
    solve(root, v);

    int i = 0;
    int j = v.size()-1;
    while(i < j){
        int sum = v[i] + v[j];
        if(sum < target){
            i++;
        }
        else if(sum > target){
            j--;
        }
        else{
            return true;
        }
    }
    return false;
}

int main(){
    node* root = NULL;
    // 10 5 2 3 12 11 15 -1
    takeInput(root);

    cout << "InOrder: " << endl;
    inOrder(root);
    cout << endl;

    cout << "LevelOrder: " << endl;
    levelOrder(root);

    int target = 14;
    if(two_sum(root, target)){
        cout << "Present" << endl;
    }
    else{
        cout << "Not Present" << endl;
    }

    return 0;
}