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

const int maxn=2007;

int n,dp[2][maxn],c,ccol[maxn],s[3],v;
ll t[3];
char a[maxn][maxn],col[maxn],ch;

void update(int &a, ll &b, int v){
    if(a<v) a=v, b=1;
    else if(a==v) b++;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d\n",&n);
    a[0][0]='@';
    FOR(i,1,n) gets(a[i]+1);
    FOR(i,1,n) col[i]='@';
    REP(i,3) s[i]=t[i]=0;
    reset(dp,0); reset(ccol,0);
    FOR(i,1,n){
        ch='@';
        c=0;
        FOR(j,1,n){
            if(a[i][j]!=ch) c++; else c=1;
            ch=a[i][j];
            if(col[j]!=a[i][j]) ccol[j]++; else ccol[j]=1;
            col[j]=a[i][j];
            v=min(dp[1-i&1][j-1]+1,min(c,ccol[j]));
            if(a[i-1][j-1]!=a[i][j]) v=1;
            dp[i&1][j]=v;
            if(v&1){
                if(a[i][j]=='1')update(s[1],t[1],v);
                else update(s[2],t[2],v);
                update(s[0],t[0],v-1);
            }else{
                update(s[0],t[0],v);
                if(a[i][j]=='1') update(s[1],t[1],v-1);
                else update(s[2],t[2],v-1);
            }
        }
    }
    REP(i,3) if(s[i]==0) t[i]=0;
    REP(i,3) printf("%d %lld\n",s[i],t[i]);
    //getch();
    return 0;
}
            
        
        
    
