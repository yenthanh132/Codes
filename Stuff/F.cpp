#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef pair<int, pii> iii;
typedef long long ll;

const int maxn=507;

int m,n,mod;
map<iii,ll> save;
string s[maxn];

ll get(int i, int c0, int c1){
    if(save.count(iii(i,pii(c0,c1)))) return save[iii(i,pii(c0,c1))];
    if(c1<0 || c0<0) return 0;
    if(i==0) return (c0==0 && c1==0);
    ll res = (get(i-1,c0-1,c1)*(c0*c1%mod) + get(i-1,c0-2,c1+2)*(((c0-1)*(c0)/2)%mod) + get(i-1,c0,c1-2)*(((c1-1)*(c1)/2)%mod) )% mod;
    save[iii(i,pii(c0,c1))]=res;
    return res;
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>m>>mod;
    int c0=0, c1=0;
    for(int i=0; i<m; ++i) cin>>s[i];
    for(int j=0; j<n; ++j){
        int x=0;
        for(int i=0; i<m; ++i) if(s[i][j]=='1') ++x;
        if(x==0) ++c0; else if(x==1) ++c1;
    }
    cout<<get(n-m,c0,c1)<<endl;
}

