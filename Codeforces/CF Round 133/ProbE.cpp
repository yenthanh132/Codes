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

const int maxn = 100007;

int s[maxn],a[maxn],k,b,n;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&k,&b,&n);
    s[0]=0;
    int v;
    FOR(i,1,n){
        scanf("%d",&a[i]);
        s[i]=(s[i-1]+a[i])%(k-1);
    }
    map<int,int> d;
    d[0]=1;
    ll res=0;
    if(b==0){
        int i=1,j;
        while(i<=n && a[i]!=0) i++;
        while(i<=n){
            j=i;
            while(j<n && a[j+1]==0) j++;
            res=res+ll(j-i+1)*(j-i+2)/2;
            i=j+1; while(i<=n && a[i]!=0) i++;
        }
    }else{
        int c0=0;
        FOR(i,1,n){
            if(a[i]>0) c0=0; else c0++;
            v=s[i]-b;
            if(v<0) v+=k-1;
            res+=d[v];
            if(b==k-1) res-=c0;
            d[s[i]]++;
        }
    }
    printf("%I64d\n",res);
    //getch();
    return 0;
}
