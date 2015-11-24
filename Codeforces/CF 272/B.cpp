#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

vector<int> ans;

int gcd(int a, int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

bool check(int x){
    if(gcd(x,x+2)!=1) return 0;
    if(gcd(x,x+3)!=1) return 0;
    if(gcd(x,x+4)!=1) return 0;
    if(gcd(x+2,x+4)!=1) return 0;
    return 1;
}

int main(){
    //freopen("input.txt","r",stdin);
    int n,k;
    cin>>n>>k;
    ans.pb(1); ans.pb(2); ans.pb(3); ans.pb(5);
    for(int i=2, x=6; i<=n; ++i){
        while(!check(x)) ++x;
        ans.pb(x);
        ans.pb(x+2);
        ans.pb(x+3);
        ans.pb(x+4);
        x+=5;
    }
    printf("%d\n",ans.back()*k);
    for(int i=1,x=0; i<=n; ++i){
        for(int j=0; j<4; ++j) printf("%d ",ans[x++]*k);
        puts("");
    }
}

