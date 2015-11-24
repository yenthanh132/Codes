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

const int maxn=1007;

int a[maxn][maxn],m,n,b[maxn][maxn];
char buf[maxn];
bool mark[5];

void solve(int x1, int x2, bool rotated = 0){
    reset(mark,1);
    int y1, y2;
    mark[x1]=0; mark[x2]=0;
    y1=-1;
    FOR(i,1,4) if(mark[i])
        if(y1==-1) y1=i; else y2=i;
    int u,v;
    FOR(i,1,m){
        if(i&1) u=x1, v=x2;
        else u=y1, v=y2;

        bool ok=1;

        FOR(j,1,n){
            b[i][j]=(j&1)?u:v;
            if(a[i][j] && a[i][j]!=b[i][j]){
                ok=0;
                break;
            }
        }
        if(ok) continue;

        ok=1;
        FOR(j,1,n){
            b[i][j]=(j&1)?v:u;
            if(a[i][j] && a[i][j]!=b[i][j]){
                ok=0;
                break;
            }
        }
        if(!ok) return;
    }
    if(rotated){
        FOR(j,1,n){
            FOR(i,1,m) printf("%d",b[i][j]);
            puts("");
        }
    }else{
        FOR(i,1,m){
            FOR(j,1,n) printf("%d",b[i][j]);
            puts("");
        }
    }
    exit(0);
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
    FOR(i,1,m){
        scanf("%s",buf+1);
        FOR(j,1,n) a[i][j]=buf[j]-'0';
    }
    FOR(i,1,3) FOR(j,i+1,4) solve(i,j);
    FOR(i,1,m) FOR(j,1,n) b[j][i]=a[i][j];
    swap(m,n);
    FOR(i,1,m) FOR(j,1,n) a[i][j]=b[i][j];
    FOR(i,1,3) FOR(j,i+1,4) solve(i,j,1);
    puts("0");
    return 0;
}

