#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char a[100007],b[100007];
int m,n;
int s[100007];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%s",a+1);
    m=strlen(a+1);
    reverse(a+1,a+m+1);
    scanf("%s",b+1);
    n=strlen(b+1);
    reverse(b+1,b+n+1);
    for(int i=1; i<=n; ++i) s[i]=s[i-1]+b[i]-'0';
    ll res = 0;
    ll p2=1;
    for(int i=1; i<=500000; ++i){
        int bit;
        if(i<=m) bit=a[i]-'0'; else bit=0;

        int r=i, l=i-314159;
        int len=r-l+1;
        if(r>n) r=n;
        if(l>n) break;
        if(l<1) l=1;
        int total = s[r]-s[l-1];
        if(bit) total=len-total;

        res = (res + p2 * total)%oo;

        p2=p2*2%oo;
    }
    cout<<res<<endl;
}

