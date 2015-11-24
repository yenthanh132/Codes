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

const int maxn=10007;

int lab[maxn], best[maxn], s[maxn], owner[maxn];
int n,t,q;

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

void dsu(int r1, int r2){
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    REP(tt,t){
        scanf("%d",&n);
        FOR(i,1,n){
            scanf("%d",&s[i]);
            lab[i]=-1;
            owner[i]=i;
            best[i]=s[i];
        }

        scanf("%d",&q);
        int k,x,y;
        REP(i,q){
            scanf("%d",&k);
            if(k==0){
                scanf("%d%d",&x,&y);
                int r1=getroot(x), r2=getroot(y);
                if(owner[r1]==owner[r2]){
                    puts("Invalid query!");
                }else{
                    if(best[r1]>best[r2]){
                        owner[r2]=owner[r1];
                        best[r2]=best[r1];
                        dsu(r1,r2);
                    }else if(best[r2]>best[r1]){
                        owner[r1]=owner[r2];
                        best[r1]=best[r2];
                        dsu(r1,r2);
                    }
                }
            }else{
                scanf("%d",&x);
                int r=getroot(x);
                printf("%d\n",owner[r]);
            }
        }

    }
    return 0;
}
