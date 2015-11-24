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

const int maxn=1000007;

int T,n,arr[maxn],a,b,c,d,val[maxn];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    scanf("%d",&T);
    REP(tt,T){
        
       
        scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
        
        reset(val,0);
        int cnt=0,s=d;
        
        val[s]=1;
        arr[cnt=1]=s;
        n--;
        while(n){
            s=(1ll*s*s*a + s*b + c)%1000000;
            if(val[s]) break;   
            
            ++val[s];
            --n;
            arr[++cnt]=s;
        }
        if(n>0){
            int p=1; while(arr[p]!=s) ++p;  
            int vdiv = n/(cnt-p+1);
            int vmod = n%(cnt-p+1);
            FOR(i,p,cnt)
                val[arr[i]]+=vdiv + (i-p+1<=vmod?1:0);
            
        }
            
        int res=0;
        int flag=1;
        FORD(v,1000000,0)
            if(val[v]&1){
                if(flag) res+=v; else res-=v;
                flag^=1;   
            }            
        
        printf("%d\n",abs(res));
    }
}
