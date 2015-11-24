
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
int cnt[26];
int n,T;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        reset(cnt,0);
        int res = 0;
        for(int i=1; i<=n; ++i) res += (cnt[s[i]-'a']++==0);
        printf("%d\n",res);
    }
}
