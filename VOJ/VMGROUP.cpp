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

const int maxn = 51;

int T,n,l,a[maxn],d[21],f[21];
bool ok,mark[maxn],mark2[21];

void duyet(int i, int &m){
    if(ok) return;
    if(i==m){
        int bit;
        REP(i,1<<(m-1)){
            reset(mark,1);
            FOR(j,1,m-1){
                FOR(k,1,n) if(((a[k]>>(d[j]-1))&1)==((i>>(j-1))&1)) mark[k]=0;
            }
            reset(f,-1);
            FOR(k,1,n) if(mark[k])
                REP(j,l) if(mark2[j+1]){
                    bit=(a[k]>>j)&1;
                    if(f[j]==-1) f[j]=bit;
                    else if(f[j]!=bit) f[j]=2;
                }
            REP(j,l) if(mark2[j+1] && f[j]!=2){
                ok=1;
                return;
            }
        }
        return;
    }
    FOR(j,d[i-1]+1,l){
        mark2[j]=0;
        d[i]=j;
        duyet(i+1,m);
        mark2[j]=1;
    }
}
    
bool check(int n){
    reset(mark2,1);
    ok=0;
    duyet(1,n);
    return ok;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>T;
    d[0]=0;
    REP(index,T){
        cin>>n>>l;
        FOR(i,1,n) cin>>a[i];
        int res;
        for(res=1; res<=l; res++) if(check(res)) break;
        cout<<res<<endl;
    }
    //getch();
    return 0;
}
