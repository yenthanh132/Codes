#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn = 1007;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int a[maxn][maxn],b[maxn][maxn],m,n,go[4][maxn][maxn];
int x[maxn][maxn];

int can_extend(int k, int i, int j){
    int i2=i+dx[k]*go[k][i][j], j2=j+dy[k]*go[k][i][j];
    int i3=i2+dx[k], j3=j2+dy[k];

    if(x[i2][j2]==1 && ((i3<1 || i3>m || j3<1 || j3>n) || x[i3][j3]==1)) return 1;
    return 0;
}


void calculate(){
    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) b[i][j]=0;
    for(int i=1; i<=m; ++i){
        int s=0;
        for(int j=1; j<=n; ++j){
            if(x[i][j]==1) s=0;
            else ++s;
            b[i][j]+=s;
        }
        s=0;
        for(int j=n; j>=1; --j){
            if(x[i][j]==1) s=0;
            else ++s;
            b[i][j]+=max(0,s-1);
        }
    }
    for(int j=1; j<=n; ++j){
        int s=0;
        for(int i=1; i<=m; ++i){
            if(x[i][j]==1) s=0;
            else ++s;
            b[i][j]+=max(0,s-1);
        }
        s=0;
        for(int i=m; i>=1; --i){
            if(x[i][j]==1) s=0;
            else ++s;
            b[i][j]+=max(0,s-1);
        }
    }
}

ll val(int i, int j){
    ll res=0;
    x[i][j]=0;
    for(int i2=i; i2>=1 && x[i2][j]==0; --i2){
        res+=sqr(b[i2][j]+1-a[i2][j])-sqr(b[i2][j]-a[i2][j]);
    }
    for(int i2=i+1; i2<=m && x[i2][j]==0; ++i2){
        res+=sqr(b[i2][j]+1-a[i2][j])-sqr(b[i2][j]-a[i2][j]);
    }
    for(int j2=j-1; j2>=1 && x[i][j2]==0; --j2){
        res+=sqr(b[i][j2]+1-a[i][j2])-sqr(b[i][j2]-a[i][j2]);
    }
    for(int j2=j+1; j2<=n && x[i][j2]==0; ++j2){
        res+=sqr(b[i][j2]+1-a[i][j2])-sqr(b[i][j2]-a[i][j2]);
    }
    x[i][j]=1;
//    cout<<res<<endl;
    return res;
}

void put(int i, int j){
    for(int i2=i; i2>=1 && x[i2][j]==0; --i2){
        ++b[i2][j];
    }
    for(int i2=i+1; i2<=m && x[i2][j]==0; ++i2){
        ++b[i2][j];
    }
    for(int j2=j; j2>=1 && x[i][j2]==0; --j2){
        ++b[i][j2];
    }
    for(int j2=j+1; j2<=n && x[i][j2]==0; ++j2){
        ++b[i][j2];
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) scanf("%d",&a[i][j]), x[i][j]=1;
    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) if(a[i][j]>0){
        x[i][j]=0;
        for(int k=0; k<4; ++k) go[k][i][j]=1;
    }
    calculate();

    for(int rep=0; rep<10; ++rep){
        for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j){
            while(b[i][j]<a[i][j]){
                int len0 = (go[0][i][j]-1) + (go[2][i][j]-1);
                int len1 = (go[1][i][j]-1) + (go[3][i][j]-1);
                bool found=0;
                int ks;
                if(len0<len1) ks=0; else ks=1;
                for(int k=ks; k<4; k+=2) if(can_extend(k,i,j)){
                    int i2=i+dx[k]*go[k][i][j], j2=j+dy[k]*go[k][i][j];
                    if(val(i2,j2)>=0) continue;
                    x[i2][j2]=0;
                    put(i2,j2);
                    go[k][i][j]++;
                    found=1;
                }
                if(!found){
                    ks=!ks;
                    for(int k=ks; k<4; k+=2) if(can_extend(k,i,j)){
                        int i2=i+dx[k]*go[k][i][j], j2=j+dy[k]*go[k][i][j];
                        if(val(i2,j2)>=0) continue;
                        x[i2][j2]=0;
                        put(i2,j2);
                        go[k][i][j]++;
                        found=1;
                    }
                }
                if(!found) break;
            }
        }
    }

    for(int i=1; i<=m; ++i){
        for(int j=1; j<n; ++j) printf("%d ",x[i][j]);
        printf("%d\n",x[i][n]);
    }
}

