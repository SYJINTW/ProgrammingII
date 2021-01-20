#include<iostream>
#include<set>
#include<vector>
using namespace std;
struct Seg{
    int left;
    int right;
    Seg(int a,int b):left(a),right(b){};
};
struct cmp{
    bool operator()(const Seg &lhs,const Seg &rhs)const{
        int llen = (lhs.right-lhs.left)/2;
        int rlen = (rhs.right-rhs.left)/2;
        if(llen!=rlen){
            return llen>rlen;
        }
        else{
            return lhs.left<rhs.left;
        }
    }
};
int main(){
    vector<int> id2pos;
    set<int> pos;
    set<Seg,cmp> seat;
    char command;
    int n,m,s,id,d;
    cin>>n>>m>>s;
    d = n + 1;
    id2pos.resize(m+1,-1);
    pos.insert(0);
    pos.insert(n+1);
    seat.insert(Seg(0,n+1));
    for(int i=0;i<2*m;i++){
        cin>>command;
        cin>>id;
        if(command=='i'){
            auto it = seat.begin();
            int left = it->left,right = it->right;
            int mid = (left+right)/2;
            if(left!=0){
                d = min(mid-left,d);
            }
            if(right!=n+1)
                d = min(right-mid,d);
            seat.erase(it);
            seat.insert(Seg(left,mid));
            seat.insert(Seg(mid,right));
            id2pos[id] = mid;
            pos.insert(mid);
        }
        else if(command=='o'){
            int mid = id2pos[id];
            auto it = pos.find(mid);
            auto it_left = it,it_right = it;
            int left = *(--it_left);
            int right = *(++it_right);
            seat.erase(Seg(left,mid));
            seat.erase(Seg(mid,right));
            seat.insert(Seg(left,right));
            id2pos[id] = -1;
            pos.erase(mid);
        }
    }
    if(d>=s){
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
    if(d == n+1)
        cout<<"INF"<<endl;
    else
        cout<<d<<endl;
}
