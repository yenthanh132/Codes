#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;

int m,n;
char a[maxn][maxn];
int b[maxn][maxn];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
    for(int i=1; i<=m; ++i) scanf("%s",a[i]+1);
    for(int i=m; i>=1; --i) for(int j=n; j>=1; --j)
        if(a[i][j]==a[m][n]){
            b[i][j]++;
            b[i-1][j]--;
            b[i][j-1]--;
            b[i-1][j-1]++;
        }
    int res=0;
    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) if(b[i][j]!=0) ++res;
    cout<<res<<endl;
}

