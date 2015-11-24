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

const int maxn=100007;

int n,k,a[maxn],v[maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    a[0]=a[n+1]=oo;
    int i=1,j;
    while(i<=n){
        j=i;
        while(j<n && a[j+1]==a[i]) j++;
        if(i==1 || j==n || a[i-1]!=a[j+1]) v[a[i]]+=1; else v[a[i]]+=2;
        i=j+1;
    }
    int res=1;
    FOR(i,2,k) if(v[res]<v[i]) res=i;
    printf("%d\n",res);
    //getch();
    return 0;
}
