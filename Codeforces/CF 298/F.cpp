#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char dp[22][32][200001];

int n,m,vEnd;
int col[22],row[7];
char ans[7][22];

int count_block(int v){
    int res = 0;
    int i=0;
    while(i<m){
        while(i<m && (v>>i&1)==0) ++i;
        if(i>=m) break;
        int j=i;
        while(j+1<m && (v>>(j+1)&1)) ++j;
        ++res;
        i=j+1;
    }
    return res;
}

int encode(int a[]){
    int v=0;
    for(int i=0; i<m; ++i){
        if(a[i]>row[i] || a[i]<0) return -1;
        v=v*11+a[i];
    }
    return v;
}

void decode(int v, int a[]){
    for(int i=m-1; i>=0; --i)
        a[i]=v%11, v/=11;
}

int rev_transfer(int v, int mask1, int mask2){
    int a[5];
    decode(v,a);
    for(int i=0; i<m; ++i)
        if((mask1>>i&1)==0 && (mask2>>i&1)) a[i]--;
    return encode(a);
}

bool gen(int i, int mask, int v){
    if(i<1) return v==0 && mask==0;
    if(dp[i][mask][v]!=-1) return dp[i][mask][v];
    char &res = dp[i][mask][v];
    int a[5];
    decode(v,a);
    for(int j=0; j<m; ++j) if(a[j] > (i+1)/2) return (res=0);
    if(count_block(mask)!=col[i]) return (res=0);
    for(int mask2=0; mask2<(1<<m); ++mask2){
        int v2=rev_transfer(v,mask2,mask);
        if(v2==-1) continue;
        if(gen(i-1,mask2,v2)){
            for(int j=0; j<m; ++j) ans[j+1][i]=(mask>>j&1)?'*':'.';
            return (res=1);
        }
    }
    return (res=0);
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>m>>n;
    vEnd=0;
    for(int i=0; i<m; ++i){
        int x;
        cin>>x;
        row[i]=x;
        vEnd=vEnd*11+x;
    }
    for(int j=1; j<=n; ++j) cin>>col[j];

    reset(dp,-1);
    for(int mask=0; mask<(1<<m); ++mask) if(gen(n,mask,vEnd)) break;

    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j) printf("%c",ans[i][j]);
        printf("\n");
    }
    return 0;
}
