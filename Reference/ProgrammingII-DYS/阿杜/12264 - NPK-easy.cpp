#include<iostream>
#include<queue>
#include<list>
using namespace std;
list<int> line;
queue<int> country[3];
int main(){
    string s;
    int N,id,num;
    cin>>N;
    while(N--){
        cin>>s;
        if(s=="ENQUEUE"){
            cin>>id;
            num = id%3;
            if(line.empty()){
                line.push_back(num);
                country[num].push(id);
            }
            else if(country[num].empty()){
                line.push_back(num);
                country[num].push(id);
            }
            else{
                country[num].push(id);
            }
        }
        else if(s=="DEQUEUE"){
            num = line.front();
            cout<<country[num].front()<<endl;
            country[num].pop();
            if(country[num].empty()){
                line.pop_front();
            }
        }
    }
}
