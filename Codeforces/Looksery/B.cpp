#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=106;
int n,a[maxn];
string s[maxn];
int deg[maxn],mark[maxn];

bool check(){
    for(int i=1; i<=n; ++i) if(deg[i]==a[i]) return 0;
    return 1;
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>s[i];
    for(int i=1; i<=n; ++i) cin>>a[i];
    for(int i=1; i<=n; ++i){
        for(int j=0; j<n; ++j) if(s[i][j]=='1') ++deg[j+1];
        mark[i]=1;
    }
    while(!check()){
        for(int i=1; i<=n; ++i)
            if(deg[i]==a[i] && mark[i]){
                mark[i]=0;
                for(int j=0; j<n; ++j) if(s[i][j]=='1') --deg[j+1];
            }
    }
    int c=0;
    for(int i=1; i<=n; ++i)
        if(a[i]==deg[i]){
            cout<<-1<<endl;
        }else c+=mark[i];
    cout<<c<<endl;
    for(int i=1; i<=n; ++i) if(mark[i]) cout<<i<<' ';
}

