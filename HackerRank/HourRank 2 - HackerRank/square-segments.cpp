#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxv=1000000;
const int maxn=100007;
const int base=73471;

int isPrime[maxv+5], minFrac[maxv+5];
int n,a[maxn];

map<ll,ll> mm;

ll hashSet(set<int> &mys){
    ll val=0;
    for(set<int>::iterator it=mys.begin(); it!=mys.end(); ++it) val=val*base+*it;
    return val;
}

int main(){
//    freopen("input.txt","r",stdin);
    isPrime[2]=1;
    for(int i=3; i<=maxv; ++i) isPrime[i]=1;
    for(int i=2; i*i<=maxv; ++i) if(isPrime[i]){
        for(int j=i*i; j<=maxv; j+=i) if(isPrime[j]){
            isPrime[j]=0;
            minFrac[j]=i;
        }
    }
    for(int v=1; v<=maxv; ++v) if(isPrime[v]) minFrac[v]=v;


    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    set<int> mys;
    mm[hashSet(mys)]=1;
    ll res=0;
    for(int i=1; i<=n; ++i){
        int v=a[i];
        while(v>1){
            int x=minFrac[v];
            v/=x;
            if(mys.count(x)) mys.erase(x);
            else mys.insert(x);
        }
        ll val = hashSet(mys);
        res += mm[val];
        mm[val]++;
    }
    cout<<res<<endl;
}

