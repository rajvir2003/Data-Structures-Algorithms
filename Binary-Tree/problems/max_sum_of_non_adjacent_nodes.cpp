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

pair<int,int> getMaxSum(node* root){
    if(root == NULL){
        return {0,0};
    }

    pair<int,int> left = getMaxSum(root->left);
    pair<int,int> right = getMaxSum(root->right);

    pair<int,int> ans;
    ans.first = root->data + left.second + right.second;
    ans.second = max(left.first,left.second) + max(right.first,right.second);
    return ans;
}

int main(){
    node* root = NULL;
    // 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1
    root = buildTree(root);

    pair<int,int> pr = getMaxSum(root);
    cout << "Answer: " << max(pr.first,pr.second);

    return 0;
}