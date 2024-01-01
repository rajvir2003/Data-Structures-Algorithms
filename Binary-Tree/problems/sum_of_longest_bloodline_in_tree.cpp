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

void sumOfLongRootToLeafPath(node* root, int height, int &maxHeight, int sum, int &maxSum){
    if(root == NULL){
        if(height > maxHeight){
            maxHeight = height;
            maxSum = sum;
        }
        else if(height == maxHeight){
            maxHeight = max(maxHeight, height);
        }
        return;
    }

    sum += root->data;

    sumOfLongRootToLeafPath(root->left, height+1, maxHeight, sum, maxSum);
    sumOfLongRootToLeafPath(root->right, height+1, maxHeight, sum, maxSum);
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    int sum = 0;
    int maxSum = INT_MIN;
    int height = 0;
    int maxHeight = 0;
    sumOfLongRootToLeafPath(root, height, maxHeight, sum, maxSum);
    cout << "Answer: " << maxSum << endl;

    return 0;
}