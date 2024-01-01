#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* links[26];
    bool terminal;

    Node(){
        for(int i = 0; i < 26; i++){
            links[i] = NULL;
        }
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
    public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->contains(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->terminal = true;
    }

    void storeSuggestions(Node* node, string prefix, vector<string> &temp){
        if(node->terminal){
            temp.push_back(prefix);
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
            if(node->contains(ch)){
                prefix.push_back(ch);
                storeSuggestions(node->get(ch), prefix, temp);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string query){
        Node* node = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i = 0; i < query.length(); i++){
            prefix.push_back(query[i]);

            if(node->contains(query[i])){
                vector<string> temp;
                storeSuggestions(node->get(query[i]), prefix, temp);
                output.push_back(temp);
            }
            else{break;}

            node = node->get(query[i]);
        }
        return output;
    }
};

int main(){
    Trie trie;

    vector<string> contactList = {
        "cod",
        "code",
        "codding",
        "coding",
        "coly"
    };

    string query = "coding";

    for(int i = 0; i < contactList.size(); i++){
        trie.insert(contactList[i]);
    }

    vector<vector<string>> result = trie.getSuggestions(query);

    for(auto i: result){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}