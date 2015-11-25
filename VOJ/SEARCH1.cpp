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

int m,n,p,a[maxn],c[maxn],list[maxn],last,b[maxn],res,cnt;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&p);
    int v;
    FOR(i,1,n){
        scanf("%d",&v);
        c[v]++;
    }
    FOR(i,1,m){
        scanf("%d",&v);
        b[v]=1;
    }
    FOR(i,1,p){
        scanf("%d",&a[i]);
        if(b[a[i]]) a[i]=-1;
    }
    int i,j;
    i=1; res=0;
    reset(b,0);
    while(i<=p && a[i]==-1) i++;
    while(i<=p){
        j=i;
        while(j<p && a[j+1]!=-1) j++;
        cnt=last=0;
        if(j-i+1>=n){
            FOR(k,i,j){
                list[last++]=a[k];
                if(b[a[k]]<c[a[k]]) cnt++;
                b[a[k]]++;
            }
            if(cnt==n) res=max(res,j-i+1);
            REP(i,last) b[list[i]]--;
        }
        i=j+1;
        while(i<=p && a[i]==-1) i++;
    }
    
    printf("%d\n",res);
    
    //getch();
    return 0;
}
