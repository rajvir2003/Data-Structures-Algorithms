#include<bits/stdc++.h>
using namespace std;

void solve(string str, int index, string temp, vector<string>& ans){
  if (index >= str.length()) {
	  if(temp.length() > 0){
   		ans.push_back(temp);
	  }
    return;
  }

  // exclude
  solve(str, index + 1, temp, ans);

  // include
  temp.push_back(str[index]);
  solve(str, index + 1, temp, ans);
}

int main(){
    string str = "abc";
    vector<string> ans;
	string temp = "";
	int index = 0;
	solve(str, index, temp, ans);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
	
    return 0;
}