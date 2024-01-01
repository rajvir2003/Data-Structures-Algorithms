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

vector<vector<int>> zigzagTraversal(node* root){
    vector<vector<int>> ans;
    queue<node*> q;
    q.push(root);
    bool flag = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);
        for(int i = 0; i < size; i++){
            node* temp = q.front();
            q.pop();

            int index = (flag)? i : size-i-1;
            level[index] = temp->data;

            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
        flag = !flag;
        ans.push_back(level);
    }
    return ans;
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    vector<vector<int>> ans = zigzagTraversal(root);
    for(auto i : ans){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}