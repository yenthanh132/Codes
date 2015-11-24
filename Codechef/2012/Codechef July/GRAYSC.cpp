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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100005;
const double lim = 0.00001;

unsigned long long a[maxn];
int mark[65],n;

void printbit(unsigned long long v){
    REPD(i,64) cout<<(1&(v>>i));
    cout<<endl;
}

int xorbit(unsigned long long v1, unsigned long long v2){
    int res=-1;
    REP(i,64) if(((v1>>i)&1)!=((v2>>i)&1))
        if(res==-1) res=i;
        else return -1;
    return res;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%llu",&a[i]);
    
    REP(i,64) mark[i]=oo;
    if(xorbit(a[1],a[n])!=-1){
        mark[xorbit(a[1],a[n])]=1;
    }
    int v;
    FOR(i,2,n){
        v=xorbit(a[i],a[i-1]);
        if(mark[v]==oo) mark[v]=i;
        else if(i-mark[v]>=2){
            printf("Yes\n");
            //getch();
            return 0;
        }
    }
    printf("No\n");
    //getch();
    return 0;
}
