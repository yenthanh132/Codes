#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
//    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    ll mul10=10;
    int d=1;
    ll res=0;
    while(mul10<=n){
        res+=1ll*(mul10-mul10/10)*d;
        mul10*=10;
        d++;
    }
    res+=1ll*(n-mul10/10+1)*d;
    cout<<res<<endl;
}

