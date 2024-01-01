#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* links[26];
    int childCount;
    bool terminal;

    Node(){
        for(int i = 0; i < 26; i++){
            links[i] = NULL;
        }
        childCount = 0;
        terminal = false;
    }

    bool contains(char ch){
        if(links[ch-'a'] == NULL){
            return false;
        }
        return true;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
};

class Trie{
    private:
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->contains(word[i])){
                node->put(word[i], new Node());
                node->childCount++;
            }
            node = node->get(word[i]);
        }
        node->terminal = true;
    }

    string longestCommonPrefix(string word){
        string res = "";
        Node* node = root;
        int i = 0;
        while(node->childCount == 1 && i < word.length()){
            res.push_back(word[i]);
            node = node->get(word[i]);
            i++;
        }
        return res;
    }

};

int main(){
    vector<string> arr = {
        "appleiphone",
        "applepie",
        "applejuice",
        "apple"
    };

    Trie trie;
    for(int i = 0; i < arr.size(); i++){
        trie.insert(arr[i]);
    }

    string lcp = trie.longestCommonPrefix(arr[0]);
    cout << "Longest common prefix -> " << lcp << endl;

    return 0;
}