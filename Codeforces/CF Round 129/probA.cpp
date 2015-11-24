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

ll string2ll(string s){
    ll v=0;
    REP(i,sz(s)) v=v*10+int(s[i])-48;
    return v;
}

ll cal(ll v){
    if(v<10) return v;
    stringstream ss;
    ss<<v;
    string s=ss.str();
    ll res=0,pw10[18];
    pw10[0]=1; FOR(i,1,17) pw10[i]=pw10[i-1]*10;
    FOR(i,1,sz(s)-1)
        if(i<=2) res+=9;
        else res+=9*pw10[i-2];
    int dau=int(s[0])-48, cuoi=int(s[sz(s)-1])-48;
    FOR(i,1,dau-1) res+=pw10[sz(s)-2];
    ll mid;
    if(sz(s)>2){
        mid=string2ll(s.substr(1,sz(s)-2));
    }else mid=0;
    if(dau<=cuoi) mid++;
    if(mid>0) res+=mid;
    return res;
}   

#include <conio.h>
int main(){
    ll l,r;
    cin>>l>>r;
    cout<<cal(r)-cal(l-1)<<endl;
    //getch();
    return 0;
}    
