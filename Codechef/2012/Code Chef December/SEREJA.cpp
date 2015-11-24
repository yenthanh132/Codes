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

const int maxn=100005;

int n,a[maxn];
vector<int> s1,s2;
ll res;

ll pow(int v0, int n){
    if(n==1) return v0;
    ll t=pow(v0,n/2);
    t=(t*t)%oo;
    if(n&1) return (t*v0)%oo; else return t;
}

//#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    res=1;
    s1.pb(0); s2.pb(0);
    s1.pb(1); s2.pb(1);
    FOR(i,2,n){
        if(a[i]==a[i-1]){
            res=0;
            break;
        }
        while(sz(s1)>1 && a[s1.back()]>=a[i]) s1.pop_back();
        while(sz(s2)>1 && a[s2.back()]<=a[i]) s2.pop_back();
        s1.pb(i); s2.pb(i);
        int x=sz(s1)-2, y=sz(s2)-2, minv, maxv;
        minv=maxv=a[i];
        while(x>0 || y>0){
            if(x>0 && y>0 && s1[x]==s2[y]){
                minv=min(minv,a[s1[x]]);
                maxv=max(maxv,a[s1[x]]);
                x--; y--;
                res=(res*pow(maxv-minv, s1[x+1]-max(s1[x],s2[y])))%oo;   
            }else if(y==0 || s1[x]>s2[y]){
                minv=min(minv,a[s1[x]]);
                maxv=max(maxv,a[s1[x]]);
                x--;
                res=(res*pow(maxv-minv, s1[x+1]-max(s1[x],s2[y])))%oo;   
            }else{
                minv=min(minv,a[s2[y]]);
                maxv=max(maxv,a[s2[y]]);
                y--;
                res=(res*pow(maxv-minv, s2[y+1]-max(s1[x],s2[y])))%oo;   
            }  
        }
    }
    printf("%d\n",res);
    
    //getch();
    return 0;
}
                
        
        
    
    
