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
#define oo 10000000007ll

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

const int maxn=57;

int n,s,a[maxn];
ll idx[maxn];
int cnt=0;
ll minv,v;
vector<int> list;
        
ll cal(int num, ll i){
    return i*(2+(num-2)*(i-1))/2;
}

#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    bool first=1;
    while(n){
        if(first) first=0;
        else puts("");
        FOR(i,1,n) cin>>a[i]; cin>>s;
        FOR(i,1,n){
            idx[i]=1;
            while(cal(a[i],idx[i])<s) idx[i]++;
        }
        
        
        cnt=0;
        for(int x=1; ; ++x){
            minv=oo;
            FOR(i,1,n) minv=min(minv,cal(a[i],idx[i]));
            list.clear();
            FOR(i,1,n) if(minv==cal(a[i],idx[i])){
                idx[i]++;
                list.pb(a[i]);
            }
            if(sz(list)>1){
                printf("%I64d:%d",minv,list.front());
                FOR(i,1,sz(list)-1) printf(" %d",list[i]);
                puts("");
                cnt++;
                if(cnt==5) break;
            }
        }
        
        cin>>n;
    }
    //getch();
    return 0;
}
    
    
