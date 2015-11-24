#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100007;

ll bit[maxn], bit2[maxn];
int n,m,val[maxn];
set<int> sl,sr;

void update(ll *arr, int p, ll v){
    for(int i=p; i<=n; i+=i&(-i)) arr[i]+=v;
}

ll get(ll *arr, int p){
    ll res=0;
    for(int i=p; i; i-=i&(-i)) res+=arr[i];
    return res;
}

void update(int l, int r, ll v){
    //cout<<l<<' '<<r<<' '<<v<<endl;
    update(bit,l,-v*(l-1));
    update(bit2,l,v);

    update(bit,r+1,v*r);
    update(bit2,r+1,-v);
}

ll get(int l, int r){
    ll v1=get(bit2,r)*r + get(bit,r);
    ll v2=get(bit2,l-1)*(l-1) + get(bit, l-1);
    return v1-v2;
}




int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) sl.insert(i), sr.insert(i), val[i]=i;

    int k,l,r,x;
    REP(rr,m){
        scanf("%d%d%d",&k,&l,&r);
        if(k==2){
            printf("%I64d\n",get(l,r));
        }else{
            scanf("%d",&x);
            set<int>::iterator it, it2;
            while(1){
                it2 = sr.upper_bound(l-1);
                if(it2==sr.end()) break;
                it=sl.lower_bound(*it2+1);
                --it;
                int l2=*it, r2=*it2;
                if(l2>r) break;

                update(max(l2,l),min(r2,r),abs(x-val[l2]));
                sl.erase(it); sr.erase(it2);
                if(l2<l && l<=r2){
                    sl.insert(l2);
                    sr.insert(l-1);
                }
                if(l2<=r && r<r2){
                    sl.insert(r+1);
                    sr.insert(r2);
                    val[r+1]=val[l2];
                }
            }
            sl.insert(l); sr.insert(r);
            val[l]=x;
        }
    }
    return 0;
}
