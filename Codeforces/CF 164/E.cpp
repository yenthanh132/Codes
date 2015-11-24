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

const int maxn=50007;

struct node{int len,p; double pp;}a[maxn];
int n;

bool cmp(const node &a, const node &b){
    return a.len*a.p*(100-b.p)>(100-a.p)*b.len*b.p;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].len,&a[i].p), a[i].pp=a[i].p/100.0;
    sort(a+1,a+n+1,cmp);
    double res=0,sum=0;
    FOR(i,1,n){
        res+=a[i].len;
        res+=sum*(1-a[i].pp);
        sum=sum*(1-a[i].pp) + sum*a[i].pp + a[i].len*a[i].pp;
    }
    printf("%0.12lf\n",res);
    //getch();
    return 0;
}        
