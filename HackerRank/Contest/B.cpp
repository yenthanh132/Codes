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

const int maxn=507;

char a[maxn][maxn];
int s[maxn][maxn],m,n;

int ok(int i1, int j1, int i2, int j2){
    return (s[i2][j2]-s[i1-1][j2]-s[i2][j1-1]+s[i1-1][j1-1])==0;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&m,&n);
    FOR(i,1,m) scanf("%s",a[i]+1);
    FOR(i,1,m) FOR(j,1,n) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i][j]=='x');
    int res=-oo;
    int l,r;
    FOR(i1,1,m) FOR(i2,i1+1,m){
        l=oo;
        FOR(j,1,n) if(a[i1][j]=='.' && a[i2][j]=='.'){
            if(ok(i1,j,i2,j))
                if(l!=oo) res=max(res,2*(j-l)+(i2-i1)*2);
                else l=j;
        }else{
            l=oo;
        }
        
    }
    if(res==-oo) puts("impossible"); else printf("%d\n",res);
    //getch();
    return 0;
}

