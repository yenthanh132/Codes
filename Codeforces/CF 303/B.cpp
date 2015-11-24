#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n,a[3333];
bool check[33333];

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];
    sort(a+1,a+n+1);
    int res = 0;
    check[a[1]]=1;
    for(int i=2; i<=n; ++i){
        while(check[a[i]]){
            a[i]++;
            ++res;
        }
        check[a[i]]=1;
    }
    cout<<res<<endl;
}

