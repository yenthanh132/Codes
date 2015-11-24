#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const ll hashbase=73471;

const int maxn=300007;
ll hashpw[maxn],val[maxn];
char s[maxn];
int n;

ll shash(int l, int r){
    return val[r]-val[l-1]*hashpw[r-l+1];
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%s",s+1);
    n=strlen(s+1);
    hashpw[0]=1; val[0]=0;
    for(int i=1; i<=n; ++i){
        hashpw[i]=hashpw[i-1]*hashbase;
        val[i]=val[i-1]*hashbase+s[i];
    }

    int res=0;
    for(int i=1; i<=n/2; ++i){
        if(shash(1,i)==shash(n-i+1,n) && i*2<n) ++res;
    }

    for(int i=1; i<=n-2; ++i){
        int len=n-i;
        if(len&1) continue;
        if(shash(i+1,i+len/2)==shash(i+len/2+1,n)) ++res;
    }

    for(int i=n; i>2; --i){
        int len=i-1;
        if(len&1) continue;
        if(shash(1,len/2)==shash(len/2+1,len)) ++res;
    }

    cout<<res<<endl;
}

