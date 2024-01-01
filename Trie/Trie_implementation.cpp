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

    bool search(string word){
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->contains(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->terminal;
    }

    void remove(string word){
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->contains(word[i])){
                cout << "Word does not exist" << endl;
                return;
            }
            node = node->get(word[i]);
        }
        node->terminal = false;
    }

    bool startsWith(string prefix){
        Node* node = root;
        for(int i = 0; i < prefix.length(); i++){
            if(!node->contains(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main(){
    Trie t;

    vector<string> words = {
        "cod",
        "code",
        "coding",
        "codding",
        "coly"
    };
    
    for(int i = 0; i < words.size(); i++){
        t.insert(words[i]);
    }
    
    cout << t.search("code") << endl;
    t.remove("code");
    cout << t.search("code") << endl;

    cout << t.startsWith("co") << endl;

    return 0;
}