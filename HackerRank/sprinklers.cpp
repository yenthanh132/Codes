#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 2000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=10007;

int T,n,m,s,p,a[maxn],cnt,ans[maxn];

int jumpTo(int pos, int len){
    int left=1, right=m, mid, res = -1;
    while(left<=right){
        mid = (left+right)/2;
        if(a[mid]<=pos+len){
            res = mid;
            left = mid+1;
        }else
            right = mid-1;
    }
    return res;
}



int cost(int len){
    int last=1;
    int res = len*p;
    cnt = 0;
    while(last<=n){
        int p = jumpTo(last,len);
        if(p == -1 || a[p]+len<last) return oo;
        ans[++cnt] = a[p];
        last = a[p]+len+1;
        res += s;
    }
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&s,&p);
        for(int i=1; i<=m; ++i) scanf("%d",&a[i]);
        int best = oo;
        int bestLen;
        for(int len=0; len<=n; ++len){
            int val = cost(len);
            if(val < best){
                best = val;
                bestLen = len;
            }
        }
        cost(bestLen);
        printf("%d %d\n", cnt, bestLen);
        for(int i=1; i<=cnt; ++i) printf("%d ",ans[i]); puts("");

    }
}

