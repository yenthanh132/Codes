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
char s[maxn];
int a[maxn],f[maxn][maxn][8];
int n;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%s",s+1); n=strlen(s+1);
    for(int i=1; i<=n; ++i){
        a[i]=s[i]-'0';
        if(a[i]==0){
            cout<<"YES"<<endl<<0<<endl;
            return 0;
        }
    }

    reset(f,-1);
    for(int i=1; i<=n; ++i){
        if(a[i]>0) f[i][1][a[i]%8]=1;
        for(int j=1; j<i; ++j)
            for(int v=0; v<8; ++v)
                if(f[i-1][j][v]!=-1){
                    if(f[i][j][v]==-1) f[i][j][v]=0;
                    f[i][j+1][(v*10+a[i])%8]=1;
                }
    }
    int j=n;
    for(j=n; j>=1; --j)
        if(f[n][j][0]!=-1) break;
    if(j<1) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        int v=0;
        vector<int> lst;
        for(int i=n; i>=1; --i){
            if(f[i][j][v]==1){
                lst.pb(a[i]);
                for(int v2=0; v2<8; ++v2)
                    if((v2*10+a[i])%8==v && (j==1 || f[i-1][j-1][v2]!=-1)){
                        v=v2;
                        break;
                    }
                --j;
            }
        }
        for(int i=sz(lst)-1; i>=0; --i) cout<<lst[i];
        cout<<endl;
    }
}

