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

int n[3], p[3], c[3];
string s;
ll r;

int val(char ch){
    if(ch=='B') return 0;
    if(ch=='S') return 1;
    return 2;   
}

bool check(ll num){
    ll v=r;
    REP(i,3) 
        v-=max((c[i]*num-n[i])*p[i],0ll);
    return v>=0;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>s;
    REP(i,3) cin>>n[i];
    REP(i,3) cin>>p[i];
    cin>>r;
    reset(c,0);
    REP(i,sz(s)) ++c[val(s[i])];
    ll res=0, left=1, right=2000000000007ll, mid;
    while(left<=right){
        mid=(left+right)/2;
        if(check(mid)){
            res=mid;
            left=mid+1;
        }else right=mid-1;   
    }
    
    cout<<res<<endl;
}
    

