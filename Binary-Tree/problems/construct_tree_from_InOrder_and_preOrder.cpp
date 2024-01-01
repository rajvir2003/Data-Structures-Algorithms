#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

node* buildTree(int *inOrder, int* preOrder, int n, int &index, int InOrderStart, int InOrderEnd, unordered_map<int,int> mp){
    if(index >= n || InOrderStart > InOrderEnd){
        return NULL;
    }

    int element = preOrder[index++];
    int position = mp[element];
    node* root = new node(element);

    root->left = buildTree(inOrder, preOrder, n, index, InOrderStart, position-1, mp);
    root->right = buildTree(inOrder, preOrder, n, index, position+1, InOrderEnd, mp);
    return root;
}

void postOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main(){
    int inOrder[] = {3,1,4,0,5,2};
    int preOrder[] = {0,1,3,4,2,5};
    int n = 6;
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++){
        mp[inOrder[i]] = i;
    }

    int index = 0;
    node* root = buildTree(inOrder, preOrder, n, index, 0, n-1, mp);
    postOrderTraversal(root);

    return 0;
}