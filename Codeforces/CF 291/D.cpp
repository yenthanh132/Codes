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

int d[5][20][maxn],res[5],maxlen;
int n,m,k,arr[5][maxn],lg2[maxn];

int get(int j, int l, int r){
    int x=lg2[r-l+1];
    return max(d[j][x][l],d[j][x][r-(1<<x)+1]);
}

int main(){
//    freopen("input.txt","r",stdin);
    lg2[0]=0;
    int i=0;
    for(int j=1; j<=100000; ++j){
        while(1<<(i+1)<=j) ++i;
        lg2[j]=i;
    }
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; ++i) for(int j=0; j<m; ++j) scanf("%d",&arr[j][i]);
    for(int j=0; j<m; ++j){
        for(int i=1; i<=n; ++i) d[j][0][i]=arr[j][i];
        for(int l=1; l<20; ++l)
            for(int i=1; i<=n-(1<<l)+1; ++i) d[j][l][i] = max(d[j][l-1][i],d[j][l-1][i+(1<<(l-1))]);
    }
    maxlen=0;
    for(int i=1; i<=n; ++i){
        int l=i, r=n, mid,pos=i-1;
        while(l<=r){
            mid=(l+r)/2;
            int sum=0;
            for(int j=0; j<m; ++j){
                sum+=get(j,i,mid);
            }
            if(sum<=k){
                pos=mid;
                l=mid+1;
            }else
                r=mid-1;
        }
        int len=pos-i+1;
        if(len>maxlen){
            maxlen=len;
            for(int j=0; j<m; ++j) res[j]=get(j,i,pos);
        }
    }
    for(int j=0; j<m; ++j) cout<<res[j]<<' ';
}

