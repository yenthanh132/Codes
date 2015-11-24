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
const ll base=73471;

pii pre,mid,suf,pos[maxn];
int n,p[maxn],k,res,Left[maxn];
char s[maxn];
ll hashpw[maxn],val[maxn],valrev[maxn];

ll get(int i, int j){
    return val[j]-val[i-1]*hashpw[j-i+1];
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    gets(s+1);
    n=strlen(s+1);
    hashpw[0]=1;
    FOR(i,1,n) hashpw[i]=hashpw[i-1]*base;
    FOR(i,1,n) val[i]=val[i-1]*base+s[i];
    FORD(i,n,1) valrev[i]=valrev[i+1]*base+s[i];
    
    int v=0; p[0]=0;
    FOR(i,1,n){
        if(v+p[v]>=i) p[i]=min(p[2*v-i],2*v-i-(v-p[v]));
        else p[i]=1;
        while(i-p[i]>=1 && i+p[i]<=n && s[i-p[i]]==s[i+p[i]]) p[i]++;
        if(v+p[v]<i+p[i]) v=i;
    }
    
    Left[0]=0;
    int it=1;
    FORD(i,n,1){
        while(it<i && get(it,it+n-i)!=valrev[i]) it++;
        if(it+n-i<i){
            Left[it+n-i]=n-i+1;
            pos[it+n-i]=pii(it,n-i+1);
        }else break;
    }
    FOR(i,1,n) if(!Left[i]){
        Left[i]=Left[i-1];
        pos[i]=pos[i-1];
    }
    res=0;
    int len;
    FOR(i,1,n){
        len=Left[i-p[i]];
        if(n-(i+p[i]-1)<len) len=n-(i+p[i]-1);
        if(res<p[i]*2-1 + len*2){
            res=p[i]*2-1 + len*2;
            if(len){
                k=3;
                pre=pos[i-p[i]]; pre.se=len;
                mid=pii(i-p[i]+1,p[i]*2-1);
                suf=pii(n-len+1,len);
            }else{
                k=1;
                mid=pii(i-p[i]+1,p[i]*2-1);
            }
        }
    }
        
    printf("%d\n",k);
    if(k==3) printf("%d %d\n",pre.fi,pre.se);
    printf("%d %d\n",mid.fi,mid.se);
    if(k==3) printf("%d %d\n",suf.fi,suf.se);
    
    //getch();
    return 0;
}
