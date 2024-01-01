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
node* mapping(node* root, int target, map<node*,node*> &nodeToParent){
    queue<node*> q;
    nodeToParent[root] = NULL;
    q.push(root);
    node* targetNode = NULL;

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp->data == target){
            targetNode = temp;
        }
        if(temp->left){
            nodeToParent[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right){
            nodeToParent[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return targetNode;
}

int min_time_to_burn(node* root, int target){
    map<node*,node*> nodeToParent;
    node* targetNode = mapping(root, target, nodeToParent);

    map<node*,bool> visited;
    queue<node*> q;
    q.push(targetNode);
    visited[targetNode] = true;
    int time = 0;

    while(!q.empty()){
        int size = q.size();
        bool flag = 0;
        for(int i = 0; i < size; i++){
            node* temp = q.front();
            q.pop();

            if(temp->left && !visited[temp->left]){
                visited[temp->left] = true;
                q.push(temp->left);
                flag = 1;
            }
            if(temp->right && !visited[temp->right]){
                visited[temp->right] = true;
                q.push(temp->right);
                flag = 1;
            }
            if(nodeToParent[temp] != NULL && !visited[nodeToParent[temp]]){
                visited[nodeToParent[temp]] = true;
                q.push(nodeToParent[temp]);
                flag = 1;
            }
        }
        if(flag) time++;
    }
    return time;
}

int main(){
    node* root = buildTree(root);
    // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
    int target = 8;
    int time = min_time_to_burn(root, target);
    cout << "Minimum time taken to burn binary tree: " << time << endl;

    return 0;
}