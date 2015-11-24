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

const int maxn=1007;

int a[maxn],n,b[maxn];

int test(double alpha){
    double tank=alpha;
    int c=0;
    a[0]=0;
    while(c<n+1){
        b[++c]=b[c-1]+int(floor(tank/10));
        if(c==n+1) break;
        tank=tank-floor(tank/10)*10.0+alpha;
        if(b[c]<a[c]) return -1;
        else if(b[c]>a[c]) return 1;
    }   
    return 0;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    double left,right,mid,bot,up;
    left=10; right=oo;
    test(14);
    while(fabs(right-left)>1e-9){
        mid=(left+right)/2;
        if(test(mid)>=0){
            bot=mid;
            right=mid;
        }else left=mid;
    }
    left=10; right=oo;
    while(fabs(right-left)>1e-9){
        mid=(left+right)/2;
        if(test(mid)<=0){
            up=mid;
            left=mid;
        }else right=mid;
    }
    
    test(bot);
    int v1=b[n+1];
    test(up);
    int v2=b[n+1];
    if(v1==v2){
        cout<<"unique"<<endl<<v1<<endl;
    }else cout<<"not unique"<<endl;
    
    //getch();
    return 0;
}
