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
    ll v;
    cin>>n;
    while(n--){
        cin>>v;
        ll t=v;
        int c5=0;
        while(t%5==0){
            t/=5;
            ++c5;
        }
        int c2=0;
        while(t%2==0){
            t/=2;
            ++c2;
        }
        c5-=c2;
        while(c5>0){
            v*=4;
            c5-=2;
        }
        cout<<v<<endl;
    }
}

