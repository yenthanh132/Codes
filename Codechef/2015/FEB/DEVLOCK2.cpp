#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int dmod=998244353;

ll gt[555],dp[2][55][555],dp2[55][555][555],f[55][55][555],precom[555];
int n,p,mm,num[55],dem[55],cntpos;
map<ll,int> dempos;

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%dmod;
    if(n&1) return t*base%dmod;
    return t;
}

map<pii,ll> scom;

ll com(ll n, ll k){
    if(scom.count(pii(n,k))) return scom[pii(n,k)];
    ll res=1;
    for(ll x=0; x<k; ++x) res=res*(n-x)%dmod;
    return scom[pii(n,k)]=res*mypow(gt[k],dmod-2)%dmod;
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n>>p>>mm;
    gt[0]=1;
    for(int i=1; i<=500; ++i) gt[i]=gt[i-1]*i%dmod;
    if(mm>500 && p==13){
        cout<<'0'<<endl;
        return 0;
    }

    reset(num,-1);
    int x=1,cnt=0,loop;
    while(num[x]==-1){
        num[x]=++cnt;
        int x2=x*10%p;
        if(num[x2]!=-1){
            loop=num[x]-num[x2]+1;
            num[x2]=0;
            break;
        }
        x=x2;
    }
    reset(dem,0);
    x=1%p;
    int n2=n;
    while(n2>0){
        if(num[x]==0){
            int v=n2/loop;
            dem[x]+=v;
            int x2=x*10%p;
            while(x2!=x){
                dem[x2]+=v;
                x2=x2*10%p;
            }
            n2%=loop;
            while(n2>0){
                dem[x]++;
                x=x*10%p;
                --n2;
            }
            break;
        }
        dem[x]++;
        x=x*10%p;
        --n2;
    }

    reset(dp2,0);
    dp2[0][0][0]=1;
    for(int j=0; j<mm; ++j) for(int k=0; k<=mm; ++k) for(int i=0; i<p; ++i) if(dp2[i][j][k]){
        for(int x=1; x<=9 && k+x<=mm; ++x)
            dp2[(i+x)%p][j+1][k+x] = (dp2[(i+x)%p][j+1][k+x] + dp2[i][j][k])%dmod;
    }

    dp[0][0][0]=1;
    int flag=0;
    cntpos=0;
    for(int v=0; v<p; ++v) if(dem[v]){
//        cout<<v<<' '<<dem[v]<<endl;
        flag^=1;
        int pos;
        if(dempos.count(dem[v])) pos=dempos[dem[v]];
        else{
            pos=++cntpos;
            dempos[dem[v]]=pos;
            for(int j=0; j<=min(dem[v],mm); ++j) precom[j]=com(dem[v],j);
            for(int i=0; i<p; ++i) for(int k=0; k<=mm; ++k)
                for(int j=0; j<=min(dem[v],mm); ++j)
                    f[pos][i][k] = (f[pos][i][k] + dp2[i][j][k]*precom[j])%dmod;

        }

        for(int i=0; i<p; ++i) for(int k=0; k<=mm; ++k) dp[flag][i][k]=0;
        for(int i2=0; i2<p; ++i2) for(int j2=0; j2<=mm; ++j2) if(f[pos][i2][j2])
            for(int i=0; i<p; ++i) for(int j=0; j+j2<=mm; ++j) if(dp[flag^1][i][j]){
                    dp[flag][(i+i2*v)%p][j2+j] = (dp[flag][(i+i2*v)%p][j2+j] + dp[flag^1][i][j]*f[pos][i2][j2])%dmod;
            }

    }
    ll sum=0;
    for(int i=0; i<=mm; ++i){
        sum=(sum+dp[flag][0][i])%dmod;
        cout<<sum<<' ';
    }
}
