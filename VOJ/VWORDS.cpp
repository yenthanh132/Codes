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

const int base=73471;
const int maxk=47;
const int maxn=5007;

char arr[maxk][maxn],s1[maxn],s2[maxn];
int m,n,k,len[maxn];
ll hashpw[maxn],val[maxk][maxn];
bool free1[maxk][maxn];
int d[maxk][maxn];
queue<pii> myq;

ll gethash(int i, int l, int r){
    return val[i][r]-val[i][l-1]*hashpw[r-l+1];
}

bool match(int i, int x, int j){
    ll v1=gethash(i,len[i]-x+1,min(len[i],len[i]-x+len[j]));
    ll v2=gethash(j,1,min(len[j],x));
    return v1==v2;
}

int solve(){
    int i,x,i2,y;
    d[0][len[0]]=1;
    myq.push(pii(0,len[0]));
    while(!myq.empty()){
        i=myq.front().fi; x=myq.front().se; myq.pop();
        FOR(j,1,k) if(match(i,x,j)){
            if(x<=len[j]){
                i2=j;
                y=len[j]-x;
            }else{
                i2=i;
                y=x-len[j];
            }
            if(y==0) return d[i][x];
            if(d[i2][y]) continue;
            d[i2][y]=d[i][x]+1;
            myq.push(pii(i2,y));
        }
    }
    return -1;
}
                
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&k);
    scanf("%d%s",&m,s1+1);
    scanf("%d%s",&n,s2+1);
    FOR(i,1,min(m,n)) if(s1[i]!=s2[i]){
        puts("NIE");
        return 0;
    }
    if(m==n){
        puts("0");
        return 0;
    }
    
    len[0]=abs(m-n);
    if(m<n)
        FOR(i,1,len[0]) arr[0][i]=s2[m+i];
    else
        FOR(i,1,len[0]) arr[0][i]=s1[n+i];
    
    FOR(i,1,k) scanf("%d%s",&len[i],arr[i]+1);
    int maxlen=0;
    FOR(i,0,k){
        val[i][0]=0;
        FOR(j,1,len[i]) val[i][j]=val[i][j-1]*base+arr[i][j];
        maxlen=max(maxlen,len[i]);
    }
    hashpw[0]=1;
    FOR(i,1,maxlen) hashpw[i]=hashpw[i-1]*base;
    int res=solve();
    if(res==-1) puts("NIE"); else printf("%d\n",res);
    
    //getch();
    return 0;
}   
    
        
    
    
