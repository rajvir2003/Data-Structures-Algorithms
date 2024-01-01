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
        for(auto i: level){
            cout << i << " ";
        }
        cout << endl;
    }
}

void inOrder(node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

node* insertIntoBST(node* &root, int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(root->data > d){
        root->left = insertIntoBST(root->left, d);
    }
    else{
        root->right = insertIntoBST(root->right, d);
    }
    return root;
}

void takeInput(node* &root){
    int data;
    cout << "Enter Input: ";
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

vector<int> merge_2_sorted_arr(vector<int> BST1, vector<int> BST2){
    vector<int> merge;
    int i = 0;
    int j = 0;
    while(i < BST1.size() && j < BST2.size()){
        if(BST1[i] <= BST2[j]){
            merge.push_back(BST1[i++]);
        }
        else{
            merge.push_back(BST2[j++]);
        }
    }
    while(i < BST1.size()){
        merge.push_back(BST1[i++]);
    }
    while(j < BST2.size()){
        merge.push_back(BST2[j++]);
    }
    return merge;
}

void storeInOrder(node* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    storeInOrder(root->left, in);
    in.push_back(root->data);
    storeInOrder(root->right, in);
}

node* BST_from_inorder(int start, int end, vector<int> inorder){
    if(start > end){
        return NULL;
    }
    int index = (start + end)/2;
    int data = inorder[index];
    node* root = new node(data);

    root->left = BST_from_inorder(start, index-1, inorder);
    root->right = BST_from_inorder(index+1, end, inorder);
    return root;
}

node* mergeBST(node* root1, node* root2){
    vector<int> BST1;
    vector<int> BST2;
    storeInOrder(root1, BST1);
    storeInOrder(root2, BST2);
    vector<int> inorder = merge_2_sorted_arr(BST1, BST2);

    node* result = BST_from_inorder(0, inorder.size()-1, inorder);
    return result;
}

int main(){
    node* root1 = NULL;
    // 40 20 8 30 50 45 70 -1
    takeInput(root1);
    cout << "LevelOrder of BST-1: " << endl;
    levelOrder(root1);
    cout << "InOrder of BST-1: ";
    inOrder(root1);
    cout << endl << endl;
    node* root2 = NULL;
    // 35 17 10 25 65 90 54 -1 
    takeInput(root2);
    cout << "LevelOrder of BST-2: " << endl;
    levelOrder(root2);
    cout << "InOrder of BST-2: ";
    inOrder(root2);
    cout << endl << endl;

    node* result = mergeBST(root1, root2);
    cout << "LevelOrder of merged BST: " << endl;
    levelOrder(result);
    cout << "InOrder of merged BST: ";
    inOrder(result);
    
    return 0;
}