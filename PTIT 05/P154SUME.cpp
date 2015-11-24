#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

string s[111];
string t[111];
int m,n;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>m>>n;
    for(int i=1; i<=m; ++i) cin>>s[i];
    for(int i=1; i<=m; ++i) t[i]="";
    int res=0;
    for(int j=0; j<n; ++j){
        bool ok=1;
        for(int i=1; i<m; ++i) if(t[i]+s[i][j]>t[i+1]+s[i+1][j]) ok=0;
        if(ok)
            for(int i=1; i<=m; ++i) t[i]+=s[i][j];
        else
            ++res;
    }
    cout<<res<<endl;
}

