#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

int n,k,a[maxn],pos[maxn];
int R[maxn];
int BIT[maxn];
ll res;

void update(int i, int v){
    for(;i; i-=i&(-i)) BIT[i]=min(BIT[i],v);
}

int get(int i){
    int res=oo;
    for(;i<=100000; i+=i&(-i)) res=min(BIT[i],res);
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);

    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    for(int i=0; i<=100000; ++i) pos[i]=n+1, BIT[i]=n+1;
    for(int i=n; i>=1; --i){
        R[i] = n+1;
        if(k==0){
            int v=a[i];
            for(int j=1; j*j<=v; ++j) if(v%j==0) R[i] = min(R[i], min(pos[j], pos[v/j]));
        }else{
            int v=a[i]-k;
            if(v>=1){
                for(int j=1; j*j<=v; ++j) if(v%j==0){
                    if(v/j>k) R[i] = min(R[i], pos[v/j]);
                    if(j>k) R[i] = min(R[i], pos[j]);
                }
            }else if(v==0){
                R[i] = min(R[i], get(a[i]+1));
            }
        }
        update(a[i], i);
        pos[a[i]]=i;
    }

//    for(int i=1; i<=n; ++i) cout<<R[i]<<' '; cout<<endl;
    res=0;
    int minR = n+1;
    for(int i=n; i>=1; --i){
        minR = min(minR, R[i]);
        res += minR - i;
    }
    cout<<res<<endl;
}

