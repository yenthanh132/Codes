#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char s[111111];
int n,T,p;

bool check(int p){
    int l=1, r=n;
    while(l<r){
        if(l==p) ++l; if(r==p) --r;
        if(l>=r) break;
        if(s[l++]!=s[r--]) return 0;
    }
    return 1;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        p=0;
        for(int i=1; i<=n/2; ++i){
            if(s[i]!=s[n-i+1]){
                p=i;
                break;
            }
        }
        if(!p) puts("YES");
        else{
            if(check(p) || check(n-p+1)) puts("YES");
            else puts("NO");
        }
    }
}
