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

const int maxn=101;
int a[maxn],n;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    bool ok=1;
    FOR(i,1,n) if(a[i]>0) ok=0;
    if(ok){
        cout<<0<<endl;
        return 0;
    }
    if(n%2==0 || n<2 ){
        cout<<-1<<endl;
        return 0;
    }
    int res=0,v;
    FORD(i,(n-1)/2,1){
        v=max(a[i*2],a[i*2+1]);
        res+=v;
        a[i*2]=0;
        a[i*2+1]=0;
        a[i]=max(a[i]-v,0);
    }
    if(a[1]>0) res+=a[1];
    
    cout<<res<<endl;
    //getch();
    return 0;
}
