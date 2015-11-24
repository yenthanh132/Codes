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

const int maxn=1000007;

char s[maxn];
int n,cnt,a[maxn];

bool check(int p, bool need_touch){
    int x=0,maxv=0;
    bool touched=0;
    FOR(i,1,cnt){
        maxv=max(maxv,x);
        x+=a[i];
        if(x<=p){
            x=p+1;   
            touched=1;
        }                   
    }
    return (x>maxv) && (!need_touch || touched);    
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cnt=0;
    gets(s+1);
    n=strlen(s+1);
    int x=1;
    while(x<=n){
        int y=x;
        while(y<n && s[y+1]==s[x]) ++y;
        a[++cnt]=y-x+1;
        if(s[x]=='L') a[cnt]*=-1;
        x=y+1;
    }
    if(a[cnt]<0) FOR(i,1,cnt) a[i]*=-1;
    
    if(check(-n-1,0)){
        puts("1");
        return 0;   
    }
    int res=0;
    int l=-n, r=-1, mid, pos=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid,1)){
            pos=mid;
            r=mid-1;               
        }else l=mid+1;
    }
    res-=pos;
    cout<<res<<endl;
}
