#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1000007;

int a[maxn],cnt[maxn],res,n;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    res=0;
    for(int i=1; i<=n; ++i){
        if(cnt[a[i]]){
            cnt[a[i]]--;
            cnt[a[i]-1]++;
        }else{
            cnt[a[i]-1]++;
            ++res;
        }
    }
    printf("%d\n",res);
}

