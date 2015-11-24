#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int f[50][50];

int main(){
    //freopen("input.txt","r",stdin);
    for(int j=0; j<=30; ++j) f[0][j]=1;
    for(int i=1; i<=30; ++i) for(int j=1; j<=30; ++j){
        f[i][j]=f[i][j-1];
        if(i>=j) f[i][j]+=f[i-j][j];
    }
    cout<<f[30][30]<<endl;
}

