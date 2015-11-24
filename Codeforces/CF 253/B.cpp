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

int a[maxn],b[maxn],n,d;
ll x;

int getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}


vector<int> list;
int res[maxn],pos[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d%I64d",&n,&d,&x);
    initAB();
    if(1ll*d*d<=n){
        REP(i,n) if(b[i]==1) list.pb(i);
        REP(i,n){
            REP(j,sz(list)){
                int p=i+list[j];
                if(p<n) res[p]=max(res[p],a[i]);
            }
        }
        REP(i,n) printf("%d\n",res[i]);
    }else{
        REP(i,n) pos[a[i]]=i;
        REP(i,n){
            bool found=0;
            FORD(v,n,1){
                if(pos[v]<=i && b[i-pos[v]]==1){
                    printf("%d\n",v);
                    found=1;
                    break;
                }
            }
            if(!found) puts("0");
        }
    }
}

