#include<stack>
#include<iostream>
using namespace std;
#include<map>

int main(){
    map<char,char> k = {{'<','>'},{'{','}'},{'(',')'},{'[',']'}};
    int N;
    string str;
    cin>>N;
    getline(cin,str);
    for(int i=1;i<=N;i++){
        bool valid = true;
        stack<char> S;
        getline(cin,str);
        for(auto c:str){
            if(c=='{'||c=='['||c=='('||c=='<'){
                S.push(c);
               }
            else if(c=='}'||c==']'||c==')'||c=='>'){
                if(S.empty()){
                    valid = false;
                    break;
                }
                else if(k[S.top()]!=c){
                    valid = false;
                    break;
                }
                else{
                    S.pop();
                }
            }
        }
        if(!S.empty())
            valid = false;
        if(valid)
            cout<<"Case "<<i<<": Yes"<<endl;
        else
            cout<<"Case "<<i<<": No"<<endl;
    }
}
