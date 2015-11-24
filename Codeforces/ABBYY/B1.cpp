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

const int maxn=106;

int a[maxn],q,n;
bool mark[maxn];

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    scanf("%d",&q);
    int x,y,t;
    REP(i,q){
        scanf("%d%d%d",&t,&x,&y);
        if(t==2){
            swap(a[x],a[y]);
            continue;
        }
        reset(mark,0);
        int val=y-x+1;
        FOR(j,1,n) if(a[j]>=x && a[j]<=y){
            if(a[j]>x && mark[a[j]-1]) val--;
            mark[a[j]]=1;
        }
        printf("%d\n",val);
    }
    
    getch();
    return 0;
}
