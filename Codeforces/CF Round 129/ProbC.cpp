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

const int maxn = 200007;

ll s1[26][maxn], s2[26][maxn];
vector<int> a[26];
int n;
string str1,str2;

ll cal(int id, int pos){
    if(a[id].empty()) return 0;
    int m=sz(a[id]);
    int l=0, r=m-1, mid,res=-1;
    while(l<=r){
        mid=(l+r)/2;
        if(a[id][mid]<=pos+1){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    ll cl=res+1, cr=m-cl;
    ll ans=0;
    if(res>=0) ans+=s1[id][res]*(n-pos);
    if(res<m-1)ans+=s2[id][res+1]*(pos+1);
    return ans;
}
        
#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    cin>>str1;
    cin>>str2;
    int v;
    REP(i,n){
        v=(str1[i]-'A');
        a[v].pb(i+1);
    }
    REP(i,26) if(!a[i].empty()){
        s1[i][0]=a[i][0];
        FOR(j,1,sz(a[i])-1) s1[i][j]=s1[i][j-1]+a[i][j];
        s2[i][sz(a[i])-1]=n-a[i][sz(a[i])-1]+1;
        FORD(j,sz(a[i])-2,0) s2[i][j]=s2[i][j+1]+(n-a[i][j]+1);
    }
    double tuso=0, mauso,x;
    x=n; mauso=x*(x+1)*(2*x+1)/6;
    REP(i,n){
        v=(str2[i]-'A');
        tuso+=cal(v,i);
    }
    printf("%0.12f",1.0*tuso/mauso);
    //getch();
    return 0;
}
    
