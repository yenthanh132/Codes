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

char a[100][100];
int f[100][100];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,n;
    cin>>m>>n;
    FOR(i,1,m) scanf("%s",a[i]+1);
    f[1][1]=0;
    FOR(i,1,m) FOR(j,1,n) if(i!=1 || j!=1){
        if(a[i][j]=='*'){
            f[i][j]=1;
            continue;
        }
        f[i][j]=0;
        FOR(d,1,i-1){
            if(a[i-d][j]=='*') break;
            if(f[i-d][j]==0) f[i][j]=1;
        }
        FOR(d,1,j-1){
            if(a[i][j-d]=='*') break;
            if(f[i][j-d]==0) f[i][j]=1;
        }
    }
    FOR(i,1,m){
        FOR(j,1,n) if(f[i][j]==0) putchar('#'); else putchar(a[i][j]);
        puts("");
    }
    return 0;
}
