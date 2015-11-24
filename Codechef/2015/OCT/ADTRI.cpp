#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;



//	Hypotenuse numbers (squares are sums of 2 nonzero squares).
//  positive integers with at least one prime divisor of the form 4k + 1.

const int maxv=5000000;
bool isPrime[maxv+1];
int plist[500000],cnt;

bool check(int n){
    if(isPrime[n]) return n%4==1;
    for(int i=1; plist[i]*plist[i]<=n; ++i) if(n%plist[i]==0){
        if(plist[i]%4==1) return 1;
        while(n%plist[i]==0) n/=plist[i];
    }
    if(n>1) return n%4==1;
    return 0;
}


int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    isPrime[2]=1;
    for(int i=3; i<=maxv; i+=2) isPrime[i]=1;
    for(int i=3; i*i<=maxv; i+=2) if(isPrime[i])
        for(int j=i*i; j<=maxv; j+=2*i) isPrime[j]=0;
    plist[cnt=1]=2;
    for(int i=3; i<=maxv; i+=2) if(isPrime[i])
        plist[++cnt]=i;

    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        if(check(n)) puts("YES");
        else puts("NO");
    }

}
