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

const int maxn=157;
const int base=51123987;
const int NIL=-1;

int n,next[maxn][3],f[maxn][maxn/3][maxn/3][maxn/3],res;
string s,a;

void optimize(){
    f[0][0][0][0]=1;
    FOR(i,0,sz(a))
        FOR(x,0,(n+2)/3) FOR(y,0,(n+2)/3) FOR(z,0,(n+2)/3){
            if(next[i][0]!=NIL) f[next[i][0]][x+1][y][z]=(f[next[i][0]][x+1][y][z]+f[i][x][y][z])%base;
            if(next[i][1]!=NIL) f[next[i][1]][x][y+1][z]=(f[next[i][1]][x][y+1][z]+f[i][x][y][z])%base;
            if(next[i][2]!=NIL) f[next[i][2]][x][y][z+1]=(f[next[i][2]][x][y][z+1]+f[i][x][y][z])%base;
        }
    res=0;
    FOR(i,1,sz(a)) FOR(x,n/3,(n+2)/3) FOR(y,n/3,(n+2)/3) FOR(z,n/3,(n+2)/3)
        if(x+y+z==n && abs(x-y)<=1 && abs(x-z)<=1 && abs(y-z)<=1)
            res=(res+f[i][x][y][z])%base;
}


#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    cin>>s;
    a=a+s[0]; s.erase(0,1);
    while(!s.empty()){
        if(s[0]!=a[sz(a)-1]) a=a+s[0];
        s.erase(0,1);
    }
    int save[3];
    REP(i,3) save[i]=NIL;
    REPD(i,sz(a)){
        save[a[i]-'a']=i+1;
        REP(j,3) next[i+1][j]=save[j];
    }
    REP(j,3) next[0][j]=save[j];
    optimize();
    cout<<res;
    
    //getch();   
    return 0;
}
    
