#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

string f[111111],l[111111];
int n,a[111111];

int main(){
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>f[i]>>l[i];
    for(int i=1; i<=n; ++i) cin>>a[i];

    string pre="";
    for(int j=1; j<=n; ++j){
        int i=a[j];
        string next="";
        if(f[i]>pre) next=f[i];
        if(l[i]>pre && (next=="" || l[i]<next)) next=l[i];
        if(next==""){
            puts("NO");
            return 0;
        }
        pre=next;
    }
    puts("YES");
    return 0;
}

