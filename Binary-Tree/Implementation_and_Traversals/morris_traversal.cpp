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

node* find_predecessor(node* curr){
    // first move to left node
    node* pred = curr->left;
    // then move to right node till pred->right != NULL && pred->right != curr
    while(pred->right != NULL && pred->right != curr){
        pred = pred->right;
    }
    return pred;
}

void morrisTraversal(node* root){
    node* curr = root;
    while(curr != NULL){
        // if there is no node on the left then print the curr and move curr to curr->right
        if(curr->left == NULL){
            cout << curr->data << " ";
            curr = curr->right;
        }
        // if there is a node present on left
        else{
            // find the predecessor
            node* pred = find_predecessor(curr);

            // if there is no thread/link, then create a link from predecessor to curr
            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }
            // if there is already a link(means predecessor->right is pointing to curr),
            // then remove the thread/link and point predecessor to NULL
            else{
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main(){
    node* root = NULL;
    // 1 2 4 -1 -1 5 -1 6 -1 -1 3 -1 -1
    root = buildTree(root);

    morrisTraversal(root);

    return 0;
}