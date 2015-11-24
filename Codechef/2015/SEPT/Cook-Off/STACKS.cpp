#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

multiset<int> mys;

int main(){
//    freopen("input.txt","r",stdin);

    int T,n,v;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        mys.clear();
        for(int i=0; i<n; ++i){
            scanf("%d",&v);
            multiset<int>::iterator it = mys.lower_bound(v+1);
            if(it!=mys.end()) mys.erase(it);
            mys.insert(v);
        }
        printf("%d",sz(mys));
        for(multiset<int>::iterator it=mys.begin(); it!=mys.end(); ++it) printf(" %d",*it);
        puts("");
    }
}

