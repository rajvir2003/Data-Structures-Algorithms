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
    cout << "Enter data: " << endl;;
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
        for(auto i : level){
            cout << i << " ";
        } cout << endl;
    }
}

class INFO{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

INFO solve(node* root, int &ans){
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }
    INFO left = solve(root->left, ans);
    INFO right = solve(root->right, ans);

    INFO currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }
    if(currNode.isBST){
        ans = max(ans, currNode.size);
    }
    return currNode;
}

int largestBST(node* root){
    int ans = 0;
    INFO temp = solve(root, ans);
    return ans;
}

int main(){
    node* root = NULL;
    // 5 2 1 -1 -1 3 -1 -1 4 -1 -1
    root = buildTree(root);
    cout << "LevelOrder : " << endl;
    levelOrder(root);

    int size = largestBST(root);
    cout << "Largest BST size -> " << size << endl;

    return 0;
}