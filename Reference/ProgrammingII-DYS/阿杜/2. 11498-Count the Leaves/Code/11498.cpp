#include <stdio.h>
#include <set>
using namespace std;

int main(){

    set<int> parents;
    set<int> all;

    int N;
    int parent, child, root;

    while(scanf("%d", &N)){

        if(N==0)
            break;
        parents.clear();
        all.clear();
        for(int i=0;i<N;i++){
            scanf("%d%d", &parent,&child);

            all.insert(child);
            all.insert(parent);
            parents.insert(parent);
        }
        scanf("%d", &root);

        printf("%d\n", all.size() - parents.size());
    }

    return 0;
}


