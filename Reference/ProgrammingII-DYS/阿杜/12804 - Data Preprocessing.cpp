#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    map<string,int> BA;
    map<string,int> Count;
    map<int,string> Index;
    string s,name,label;
    int n=0,k,total=0,unlabeled=0;
    while(cin>>s){
        if(s=="----------") break;
        cin>>k;
        BA.insert(std::pair<string,int>(s,k));
        Count.insert(std::pair<string,int>(s,0));
        Index.insert(std::pair<int,string>(n,s));
        n++;
    }
    while(cin>>name){
        total+=1;
        cin>>label;
        auto test = BA.find(label);
        if(test == BA.end()){
            cout<<name<<" unlabeled"<<endl;
            unlabeled++;
        }
        else{
            cout<<name<<" "<<test->second<<endl;
            Count[label]+=1;
        }
    }
    cout<<endl;
    cout<<"total # of data: "<<total<<endl;
    for(auto c:Index){
        cout<<c.second<<": "<<Count[c.second]<<endl;
    }
    cout<<"unlabeled: "<<unlabeled<<endl;
}
