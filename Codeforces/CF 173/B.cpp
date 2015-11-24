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

const int maxn=1000007;

int n,a[maxn],g[maxn];
char ans[maxn];
ll sum;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    sum=0;
    FOR(i,1,n) scanf("%d%d",&a[i],&g[i]), sum+=a[i], ans[i]='A';
    int it=n;
    while(sum>500 && it>=1){
        sum-=1000;
        ans[it]='G';
        it--;
    }
    if(sum>500) puts("-1");
    else{
        ans[n+1]='\0';
        puts(ans+1);
    }
    //getch();
    return 0;
}
