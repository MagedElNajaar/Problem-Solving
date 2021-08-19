#include <iostream>
#include <map>
using namespace std;
int main() {
  string s;
  cin>>s;
  map<string,int>mp;
  for(int i=0;i<s.size();i++){
    if(s[i]=='D'){
      if(s.substr(i,5)=="Danil"){
        mp["Danil"]++;
      }
    }
    else if(s[i]=='O'){
      if(s.substr(i,4)=="Olya"){
        mp["Olya"]++;
      }
    }
    else if(s[i]=='S'){
      if(s.substr(i,5)=="Slava"){
        mp["Slava"]++;
      }
    }
    else if(s[i]=='A'){
      if(s.substr(i,3)=="Ann"){
        mp["Ann"]++;
      }
    }
    else if(s[i]=='N'){
      if(s.substr(i,6)=="Nikita"){
        mp["Nikita"]++;
      }
    }
  }
  if(mp.size()==1){
    if(mp["Nikita"]==1 || mp["Ann"]==1
    || mp["Danil"]==1  || mp["Slava"]==1
    || mp["Olya"]==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
  }
  else{
    cout<<"NO"<<endl;
  }
}
