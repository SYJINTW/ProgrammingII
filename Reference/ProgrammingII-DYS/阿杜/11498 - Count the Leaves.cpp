#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> parent,all;
    int N;
    int pare,child,root;
    while(scanf("%d",&N)){
        if(N==0)
        break;
        parent.clear();
        all.clear();
        for(int i = 0;i < N;i++){
            scanf("%d %d",&pare,&child);
            parent.insert(pare);
            all.insert(pare);
            all.insert(child);
        }
        scanf("%d",&root);
        cout<<all.size()-parent.size()<<endl;
    }
}
