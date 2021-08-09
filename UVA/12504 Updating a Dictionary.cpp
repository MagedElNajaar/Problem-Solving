#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

void read_MAP(map<string,string>&MP){
    char buffring[101];
    cin>>buffring;
    int idx = 1;
    
    while(buffring[idx] != '\0' && buffring[idx] != '}'){
        string key;
        while(buffring[idx] != ':'){
            key += buffring[idx++];
        }
        idx++;
        string value;
        while(buffring[idx] != ','  && buffring[idx] != '}'){
            value += buffring[idx++];
        }
        MP[key] = value;
        idx++;
    }
}

void Print_Diff(map<string,string>&OLD,map<string,string>&NEW){
    int cnt = 0, total = 0;
    for(auto NEW_KEY : NEW){
        if(OLD[NEW_KEY.first] == ""){
            if(!cnt) cout << "+";
            else cout << ",";
            cout << NEW_KEY.first;
            cnt++;
        }
    }
    if(cnt) cout << endl;
    total = cnt;
    cnt = 0;
    for(auto OLD_KEY : OLD){
        if(NEW[OLD_KEY.first] == ""){
            if(!cnt) cout << "-";
            else cout << ",";
            cout << OLD_KEY.first;
            cnt++;
        }
    }
    if(cnt) cout << endl;
    total += cnt;
    cnt = 0;
    for(auto NEW_KEY : NEW){
        if(OLD[NEW_KEY.first] != "" && NEW[NEW_KEY.first] != "" && OLD[NEW_KEY.first] != NEW[NEW_KEY.first]){
            if(!cnt) cout << "*";
            else cout << ",";
            cout << NEW_KEY.first;
            cnt++;
        }
    }
    if(cnt) cout << endl;
    total += cnt;
    if(!total) cout << "No changes\n";
    cout <<"\n";
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        map<string,string>OLD;
        map<string,string>NEW;
        read_MAP(OLD);
        read_MAP(NEW);
        Print_Diff(OLD,NEW);
    }
}
