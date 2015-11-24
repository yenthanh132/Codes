#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
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

const int maxn=107;
const double eps=1e-9;

int n,x1[maxn],y1[maxn],x2[maxn],y2[maxn];
double xmid[maxn],ymid[maxn],w[maxn];

bool check(int p){
     FORD(i,p,1){
        w[i]=(x2[i]-x1[i])*(x2[i]-x1[i])*(x2[i]-x1[i]);
        xmid[i]=(x2[i]+x1[i])/2.0;
        ymid[i]=(y2[i]+y1[i])/2.0;
        if(i==p) continue;
        double xx,yy,sumw=0;
        xx=yy=0;
        FOR(j,i+1,p){
            xx+=xmid[j]*w[j];
            yy+=ymid[j]*w[j];
            sumw+=w[j];
        }
        xx/=sumw;
        yy/=sumw;
        
        if(xx+eps<x1[i] || x2[i]+eps<xx || yy+eps<y1[i] || y2[i]+eps<yy) return 0;
    }
    return 1;
     
}

#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
        if(x1[i]>x2[i]) swap(x1[i],x2[i]);
        if(y1[i]>y2[i]) swap(y1[i],y2[i]);
    }
    
    int res=1;
    while(res<n && check(res+1)) res++;
    cout<<res<<endl;
    
    //getch();
}
