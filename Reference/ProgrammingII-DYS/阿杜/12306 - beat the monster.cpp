#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
struct State{
    int level,hp,mhp;
    int dist;
    State(int level,int hp,int mhp,int dist=0):level(level),hp(hp),mhp(mhp),dist(dist){}
};
int main(){
    bool vis[16][310][410];
    memset(vis,false,sizeof(vis));
    queue<State> state;
    int L,HP,MHP,MDMG,dmg[20],hl[20];
    cin>>L>>HP>>MHP>>MDMG;
    for(int i=1;i<=L;i++){
        cin>>dmg[i]>>hl[i];
    }
    state.push(State(1,HP,MHP));
    while(!state.empty()){
        State tmp = state.front();
        state.pop();
        if(!tmp.mhp) break;

        if(tmp.hp>MDMG||tmp.mhp<=dmg[tmp.level]){
            State t(tmp.level,tmp.hp-MDMG,max(0,tmp.mhp-dmg[tmp.level]),tmp.dist+1);
            if(!vis[t.level][t.hp][t.mhp]){
                //cout<<t.level<<t.hp<<t.mhp<<"at"<<t.dist<<endl;
                state.push(t);
                vis[t.level][t.hp][t.mhp] = true;
            }
        }
        if(tmp.hp>MDMG&&tmp.level<=L){
            State t(tmp.level+1,tmp.hp-MDMG,tmp.mhp,tmp.dist+1);
            if(!vis[t.level][t.hp][t.mhp]){
                //cout<<t.level<<t.hp<<t.mhp<<"lv"<<t.dist<<endl;
                state.push(t);
                vis[t.level][t.hp][t.mhp] = true;
            }
        }
        if(HP>MDMG&&hl[tmp.level]>MDMG){
            State t(tmp.level,min(HP,tmp.hp+hl[tmp.level])-MDMG,tmp.mhp,tmp.dist+1);
            if(!vis[t.level][t.hp][t.mhp]){
                state.push(t);
                //cout<<t.level<<t.hp<<t.mhp<<"hl"<<t.dist<<endl;
                vis[t.level][t.hp][t.mhp] = true;
            }
        }
    }
    if(state.empty()){
        cout<<-1<<endl;
    }
    else{
        cout<<state.front().dist<<endl;
    }
}
