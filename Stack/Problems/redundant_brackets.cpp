#include<bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &exp){
    stack<char> st;
    
    for(int i = 0; i < exp.length(); i++){
        char ch = exp[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                bool redundant = true;
                while(st.top() != '('){
                    if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                        redundant = false;
                    }
                    st.pop();
                }
                st.pop();

                if(redundant){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    string exp = "((a+(b/c)))";

    if(findRedundantBrackets(exp)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}