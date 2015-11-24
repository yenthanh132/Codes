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
#include <conio.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=30;
int n,a[maxn],res;
set<int> list[2];

int bitcount(int v){
    int res=0;
    while(v){
        res+=v&1;
        v/=2;
    }
    return res;
}

bool check(int k){
    list[0].clear();
    if(k>1) list[0].insert(3); else list[0].insert(2);
    int v,c,flag=0;
    bool ok;
    FOR(i,2,n){
        
        list[1^flag].clear();
        set<int>::iterator it;
        for(it=list[flag].begin(); it!=list[flag].end(); it++){
            v=*it;
            c=bitcount(v);
            ok=0;
            FOR(x,0,i-1){
                if((v>>x)&1) 
                    FOR(y,0,i-1) if((v>>y)&1)
                        if(a[x]+a[y]==a[i]){
                            if(c<k){
                                list[1^flag].insert(v+(1<<i));
                            }
                            else{
                                FOR(z,0,i-1) if((v>>z)&1) list[1^flag].insert(v-(1<<z)+(1<<i));   
                            }
                            ok=1;
                            break;
                        }
                if(ok) break;
            }
            
        }
        if(list[1^flag].empty()) return 0;
        list[flag].clear();
        flag=1^flag;
    }
    return 1;
}        
        
                


int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    a[0]=0;
    res=n;
    FOR(i,2,n){
        bool ok=0;
        FOR(j,0,i-1) FOR(z,0,i-1) if(a[j]+a[z]==a[i]) ok=1;
        if(!ok){
            res=-1;
            break;
        }
    }
    if(res==-1) puts("-1");
    else{
        
        FOR(k,1,n-1) if(check(k)){
            res=k;
            break;
        }
        printf("%d\n",res);   
    }   
    getch();
    return 0;
}
