#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int g,n,a[1111],k,pos[1111];
ll dis[1111];
int f[1111];

int gcd(int a, int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

bool ok(ll v){
    if(v<=1000) return f[v];
    return (v%g==0);
}

ll nextnum(ll v){
    while(!ok(v)) ++v;
    return v;
}

bool cmp(const int &i, const int &j){
    if(a[i]!=a[j]) return a[i]<a[j];
    return i<j;
}

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>a[i];
        cin>>k; g=0;
        reset(f,0); f[0]=1;
        for(int i=0,v; i<k; ++i){
            cin>>v;
            for(int j=0; j+v<=1000; ++j) if(f[j]) f[j+v]=1;
            g=gcd(g,v);
        }
        for(int i=1; i<=n; ++i) pos[i]=i;
        sort(pos+1,pos+n+1,cmp);

        for(int i=1; i<=n; ++i) dis[i]=0;
        for(int it=1; it<=n; ++it){
            int i=pos[it];
            dis[i]=nextnum(dis[i]);
            if(i>1 && a[i-1]>a[i]) dis[i-1]=max(dis[i-1],dis[i]*2+1);
            if(i<n && a[i+1]>a[i]) dis[i+1]=max(dis[i+1],dis[i]*2+1);
        }

        double res=0;
        for(int i=1; i<=n; ++i) res+=1.0*dis[i]/n;
        printf("%0.9f\n",res);
    }
}

