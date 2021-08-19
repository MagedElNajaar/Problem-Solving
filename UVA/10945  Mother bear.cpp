#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
  string s;
  while(getline(cin,s) && s!="DONE"){
    string s2="";
    for(int i=0;i<s.size();i++){
      if(isalpha(s[i])){
        if(isupper(s[i])){
          s[i]+=32;
        }
          s2+=s[i];
      }
    }
    string s3 = s2;
    reverse(s3.begin(),s3.end());
    if(s2 == s3){
      cout<<"You won’t be eaten!\n";
    }
    else{
      cout<<"Uh oh..\n";
    }
    s2 = s3 = "";
  }
}
