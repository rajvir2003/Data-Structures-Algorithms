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

bool isIdentical(node* r1, node* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if((r1==NULL && r2!=NULL) || (r1!=NULL && r2==NULL)){
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    if((left && right) && (r1->data == r2->data)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    // 1 3 7 -1 -1 11 -1 -1 5 13 -1 -1 17 -1 -1
    node* root1 = NULL;
    root1 = buildTree(root1);

    node* root2 = NULL;
    root2 = buildTree(root2);

    if(isIdentical(root1, root2)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}