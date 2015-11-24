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

int r[111],c[111];

int main(){
    //freopen("input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int x,y;
    REP(i,n){
        scanf("%d%d",&x,&y);
        r[x]++; c[y]++;
    }
    int r1=0,r2=0;
    FOR(i,0,100){
        if(r[i]) r1++;
        if(c[i]) r2++;
    }
    cout<<min(r1,r2)<<endl;
    return 0;
}
