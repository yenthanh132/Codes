#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char s[1000007];
int n,c[4];

int val(char c){
    if(c=='A') return 0;
    else if(c=='G') return 1;
    else if(c=='T') return 2;
    else if(c=='C') return 3;
}

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    scanf("%s",&s);
    reset(c,0);
    for(int i=0; i<n; ++i)
        c[val(s[i])]++;
    int maxv=0,cnt=0;
    for(int i=0; i<4; ++i)
        if(maxv < c[i]){
            maxv=c[i];
            cnt=1;
        }else if(maxv==c[i]){
            ++cnt;
        }
    cout<<mypow(cnt,n)<<endl;
}

