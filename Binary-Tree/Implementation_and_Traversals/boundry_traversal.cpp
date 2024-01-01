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

void leftTraversal(node* root, vector<int> &ans){
        if(root->left == NULL && root->right == NULL){
            return;
        }
        ans.push_back(root->data);
        if(root->left != NULL){
            leftTraversal(root->left, ans);
        }
        if(root->left == NULL && root->right != NULL){
            leftTraversal(root->right, ans);
        }
    }
    void childTraversal(node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        childTraversal(root->left, ans);
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        childTraversal(root->right, ans);
    }
    void rightTraversal(node* root, stack<int> &s){
        if(root->left == NULL && root->right == NULL){
            return;
        }
        s.push(root->data);
        if(root->right != NULL){
            rightTraversal(root->right, s);
        }
        if(root->right == NULL && root->left != NULL){
            rightTraversal(root->left, s);
        }
    }
    vector<int> boundary(node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        
        if(root->left != NULL){
            leftTraversal(root->left, ans);
        }
        childTraversal(root, ans);
        if(root->right != NULL){
            stack<int> s;
            rightTraversal(root->right, s);
        
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
        }
        
        return ans;
        
    }

int main(){
    node* root = NULL;
    root = buildTree(root);

    vector<int> res = boundary(root);
    for(auto i: res){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}