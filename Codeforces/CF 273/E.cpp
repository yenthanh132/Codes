
#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const ll maxv=100000000000000ll;
int d[20],cnt;

bool check(ll v){
    if(v<100) return 1;
    cnt=0;
    while(v){
        d[++cnt]=v%10;
        v/=10;
    }
    for(int i=2; i<cnt; ++i)
        if(!( (d[i-1]>d[i] && d[i]<d[i+1]) || (d[i-1]<d[i] && d[i]>d[i+1]) )) return 0;
    return 1;
}

const int base=73471;
ll p10[20];
map<ll,ll> save;
ll n,k;

ll dem(int i, int num, int up, int val){
    if(i==0) return (val==0);

    ll hashv=i*base+num;
    hashv=hashv*base+up;
    hashv=hashv*base+val;
    if(save.count(hashv)) return save[hashv];

    ll res = 0;

    if(up){
        for(int x=num+1; x<=9; ++x) res+=dem(i-1,x,0,((val-p10[i-1]*x)%n+n)%n);
    }else{
        for(int x=num-1; x>=0; --x) res+=dem(i-1,x,1,((val-p10[i]*x)%n+n)%n);
    }
    save[hashv]=res;
    return res;
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>k;
    if((n*k)/k!=n || n*k>round(1e14)){
        puts("-1");
        return 0;
    }
    if(n>=round(1e7)){
        ll val=n;

        while(val<=maxv){
            if(check(val)) --k;
            if(k==0){
                cout<<val<<endl;
                return 0;
            }
            val+=n;
        }
        puts("-1");
        return 0;
    }

    // r<=10^7
    p10[0]=1;
    for(int i=1; i<=15; ++i) p10[i]=p10[i-1]*10;
    ll total=0;
    int len;
    for(len=1; len<=14; ++len){
        if(len==1){
            for(int x=1; x<=9; ++x) if(x%n==0) ++total;
        }else if(len==2){
            for(int x=10; x<=99; ++x) if(x%n==0) ++total;
        }else{
            for(int x=1; x<=9; ++x)
                total += dem(len-1,x,0,0)
                + dem(len-1,x,1,0);
        }
        if(total>=k) break;
    }

    if(total<k){
        puts("-1");
        return 0;
    }

   cout<<len<<' '<<total<<endl;
}
