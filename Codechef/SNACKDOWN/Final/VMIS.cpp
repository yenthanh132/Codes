#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef pair<double,int> pdi;
typedef long long ll;

int a[33][33];
int n,T;
double res;

double C[33][33],frac[33];

void toArr(ll v, int a[]){
    for(int i=0; i<n; ++i){
        a[i]=v%3;
        v/=3;
    }
}

ll toV(int a[]){
    ll v=0;
    for(int i=n-1; i>=0; --i) v=v*3+a[i];
    return v;
}

set<ll> mys;
map<ll,double> val;


int main(){
//    freopen("input.txt","r",stdin);
    C[0][0]=1;
    frac[0]=1;
    for(int i=1; i<=27; ++i){
        frac[i]=frac[i-1]*i;
        C[i][0]=1;
        for(int j=1; j<=i; ++j) C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    cin>>T;
    while(T--){
        cin>>n;
        reset(a,0);
        for(int i=0; i<n; ++i) a[i][i]=1;
        for(int i=0; i<n-1; ++i){
            int u,v;
            cin>>u>>v;
            --u; --v;
            a[u][v]=a[v][u]=1;
        }

        res = 0;

        mys.clear(); val.clear();
        val[0]=1;
        mys.insert(0);
        int num[33];
        while(!mys.empty()){
            ll x=*mys.begin(); mys.erase(mys.begin());
            ll value = val[x];
            toArr(x,num);
            bool found=0;
            for(int i=0; i<n; ++i) if(!num[i]){
                found=1;
                bool ok=1;
                for(int j=0; j<n; ++j) if(num[j]==2 && a[i][j]){ ok=0; break; }
                if(ok){
                    num[i]=2;
                }else
                    num[i]=1;

                ll y=toV(num);
                val[y] += value;
                mys.insert(y);
                num[i]=0;
            }
            if(!found){
                int cnt=0;
                for(int i=0; i<n; ++i) if(num[i]==2) ++cnt;
                res += cnt*value;
            }
        }

        res/=frac[n];
        printf("%0.9f\n",res);
    }
}
