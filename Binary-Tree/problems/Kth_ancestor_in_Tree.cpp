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

node* buildTree(node* root){
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

void Kth_Ancestor(node* root, int node, int k, vector<int> path, int &ans){
    if(root == NULL){
        return;
    }

    path.push_back(root->data);
    Kth_Ancestor(root->left, node, k, path, ans);
    Kth_Ancestor(root->right, node, k, path, ans);

    for(int i = 0; i < path.size(); i++){
        if(path[i] == node && k <= i){
            ans = path[i-k];
        }
    }
}

int main(){
    node* root = buildTree(root);
    int node = 10;
    int k = 2;
    int ans = -1;
    vector<int> path;
    Kth_Ancestor(root, node, k, path, ans);
    cout << "Kth ancestor -> " << ans << endl;

    return 0;
}