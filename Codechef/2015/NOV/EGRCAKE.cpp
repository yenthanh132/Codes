#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int gcd(int a, int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        int g=gcd(a,b);
        if(g==1) cout<<"Yes\n";
        else cout<<"No "<<a/g<<"\n";
    }
}

