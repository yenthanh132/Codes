#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

map<int,int> f;

int get(int v){
    if(v&1) return (v+1)/2;
    return v/2+1;
}

int cal(int v){
    if(v==1) return 1;
    if(f.count(v)) return f[v];
    int res = get(v);
    for(int i=2; i*i<=v; ++i) if(v%i==0){
        res=min(res, min(get(v/i)*cal(i), get(i)*cal(v/i)));
    }
    f[v]=res;
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    int n; cin>>n;
    cout<<cal(n)<<endl;
}

