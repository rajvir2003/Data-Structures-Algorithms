#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int findPos(int post[], int element, int inStart, int inEnd){
    for(int i = inStart; i <= inEnd; i++){
        if(element == post[i]){
            return i;
        }
    }
    return -1;
}
Node* buildTree(int in[], int post[], int n, int &index, int inStart, int inEnd){
    if(index < 0 || inStart > inEnd){
        return NULL;
    }
    
    int element = post[index--];
    int pos = findPos(in, element, inStart, inEnd);
    Node* root = new Node(element);
    
    root->right = buildTree(in, post, n, index, pos+1, inEnd);
    root->left = buildTree(in, post, n, index, inStart, pos-1);
    return root;
}

void postOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main(){
    int inOrder[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int postOrder[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = 8;
    int index = n-1;
    Node* root = buildTree(inOrder, postOrder, n, index, 0, n-1);
    postOrderTraversal(root);
    return 0;
}