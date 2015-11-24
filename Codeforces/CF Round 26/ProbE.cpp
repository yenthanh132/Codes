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

const int maxn = 107;

int n,w,a[maxn],minv,sum,u;
bool ok;

bool plus[maxn];
vector<int> res;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&w);
    sum=0; minv=oo;
    FOR(i,1,n){
        scanf("%d",a+i);
        if(minv>a[i]){
            u=i;
            minv=a[i];
        }
        sum+=a[i];
    }
    ok=1;
    if(w<1 || w>sum || (w<minv && w<=1)) ok=0;
    else if(n==1){
        if(w==a[1]) REP(i,a[1]*2) res.pb(1);
        else ok=0;
    }else if(w<minv){
        w--;
        res.pb(n);
        while(a[1]>w){
            res.pb(1); res.pb(1);
            a[1]--;
        }
        res.pb(n);
        a[n]--;
        //Giam xuong, a[1]=w-1;
        res.pb(1);
        while(n>1){
            while(a[n]==0 && n>=2) n--;
            if(n==1) break;
            res.pb(n); res.pb(n);
            a[n]--;
        }
        res.pb(1);
        a[1]--;
        while(a[1]){
            res.pb(1); res.pb(1);
            a[1]--;
        }
    }else{
        sum--;
        res.pb(u); 
        while(sum>w-1){
            while (n==u || a[n]==0) n--;
            res.pb(n); res.pb(n); a[n]--;
            sum--;
        }
        res.pb(u); a[u]--;
        //y=1, sum=w-1, thuc hien sum vong lap con lai => y=w;;
        while(a[u]){
            res.pb(u); res.pb(u);
            a[u]--;
        }
        while(n>0){
            while(a[n]==0 && n>=1) n--;
            if(n==0) break;
            res.pb(n); res.pb(n);
            a[n]--;
        }
    }
    if(!ok) printf("No\n");
    else{
        printf("Yes\n");
        //printf("%d\n",sz(res));
        REP(i,sz(res)) printf("%d ",res[i]);
    }
    //getch();
    return 0;
}   
        
            
            
