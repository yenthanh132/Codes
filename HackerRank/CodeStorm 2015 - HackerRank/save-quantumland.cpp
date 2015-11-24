#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n;
int a[111];

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>a[i];
        int res=0;
        int i=1;
        while(i<=n && a[i]==1) ++i;
        while(i<=n){
            int j=i;
            while(j+1<=n && a[j+1]==0) ++j;
            int len=j-i;
            if(len>0)
                res += (len-1)/2 + 1;
            i=j+1;
            while(i<=n && a[i]==1) ++i;
        }
        cout<<res<<endl;
    }
}

