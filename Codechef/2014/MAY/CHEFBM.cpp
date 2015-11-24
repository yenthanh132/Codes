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

struct point{
    int x,y;
}a[maxn];
int n,m,p;

bool cmp(const point &a, const point &b){
    return (a.x<b.x || (a.x==b.x && a.y<b.y));   
}
    
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d%d",&m,&n,&p);
    FOR(i,1,p) scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+p+1,cmp);
    int i=1,j,last=1;
    while(i<=p){
        while(last<a[i].x) printf("%d\n",n-1), ++last;
        
        j=i;
        while(j<p && a[j+1].x==a[i].x) ++j;
        int i1,j1=j;
        int minv=1,maxv=n,y0=-1,v;
        bool ok=1;
        while(j1>=i){
            i1=j1;
            while(i1>i && a[i1-1].y==a[j1].y) --i1;
            if(a[j1].y==n) maxv+=j1-i1+1;
            if(a[j1].y==1) minv+=j1-i1+1;
            if(a[j1].y<n){
                if(a[j1].y+1!=y0) v=a[j1].y+1;
                if(a[j1].y+(j1-i1+1)>v){
                    ok=0;
                    break;   
                }
            }
            y0=a[j1].y;
            v=a[j1].y+(j1-i1+1);
            j1=i1-1;
        }
        if(ok) printf("%d\n",maxv-minv); else printf("-1\n");
        ++last;
        i=j+1;
    }
    
    while(last<=m) printf("%d\n",n-1), ++last;
    
}
