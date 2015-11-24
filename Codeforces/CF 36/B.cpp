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

int n,k,m;
char s[5][5];

char get(int x, int y, int k){
    if(k==1) return s[x][y];
    int len=1;
    REP(i,k-1) len*=n;
    int X,Y;
    X=(x-1)/len+1; Y=(y-1)/len+1;
    if(s[X][Y]=='*') return '*';
    return get((x-1)%len+1,(y-1)%len+1,k-1);
}

#include <conio.h>
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%s",s[i]+1);
    m=1;
    REP(i,k) m*=n;
    
    FOR(x,1,m){
        FOR(y,1,m) putchar(get(x,y,k));
        puts("");
    }
    return 0;
}
