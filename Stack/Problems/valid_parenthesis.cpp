#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string str){
    stack<char> s;

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        // incase of an opening bracket
        if(ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
        }
        // incase of a closing bracket
        else{
            if(!s.empty()){
                // if bracket pairs are matching then pop bracket from stack
                if((s.top() == '(' && ch == ')') 
                || (s.top() == '[' && ch == ']') 
                || (s.top() == '{' && ch == '}')){

                    s.pop();
                }
                // if bracket pairs are not matching then return false
                else{
                    return false;
                }
            }
            // if stack is empty and there is a closing bracket then return false
            else{
                return false;
            }
        }
    }
    
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string str = "{[([])]}";

    if(isValidParenthesis(str)){
        cout << "Parenthesis are Valid" << endl;
    }
    else{
        cout << "Parenthesis are Not Valid" << endl;
    }

    return 0;
}