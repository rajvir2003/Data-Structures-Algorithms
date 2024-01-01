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

vector<int> topView(node* root){
    vector<int> ans;
    map<int, int> mp;

    queue<pair<node*, int>> q;
    q.push({root,0});

    while(!q.empty()){
        node* temp = q.front().first;
        int dist = q.front().second;
        q.pop();

        if(!mp[dist]){
            mp[dist] = temp->data;
        }
        if(temp->left) q.push({temp->left, dist-1});
        if(temp->right) q.push({temp->right, dist+1});
    }

    for(auto i : mp){
        ans.push_back(i.second);
    }
    
    return ans;
}

int main(){
    node* root = NULL;
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    root = buildTree(root);
    
    vector<int> res = topView(root);
    for(auto i : res){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}