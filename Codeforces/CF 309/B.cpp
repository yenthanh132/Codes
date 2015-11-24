#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll f[55];

int main(){
//    freopen("input.txt","r",stdin);
    f[0]=1;
    f[1]=1;
    for(int i=2; i<=50; ++i) f[i]=f[i-1]+f[i-2];
    ll n,k;
    cin>>n>>k;
    int v=1;
    while(n>0){
        if(k<=f[n-1]){
            cout<<v<<' ';
            n--;
            v++;
        }else{
            cout<<v+1<<' '<<v<<' ';
            k-=f[n-1];
            n-=2;
            v+=2;
        }
    }

}

