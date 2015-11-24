#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=30007;
const int base=73471;

int a[maxn];
int n;
ll h1[maxn],h2[maxn],pw[maxn];

int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    char buf[10];
    pw[0]=1; h1[0]=0;
    for(int i=1; i<=n; ++i){
        scanf("%s",buf);
        a[i]=buf[0]-'A'+1;
        pw[i]=pw[i-1]*base;
        h1[i]=h1[i-1]*base+a[i];
    }
    h2[n+1]=0;
    for(int i=n; i>=1; --i){
        h2[i]=h2[i+1]*base+a[i];
    }

    int l=1, r=n;
    int cnt=0;
    while(l<=r){
        int left=1, right=r-l+1, mid, x=0;
        while(left<=right){
            mid=(left+right)/2;
            if(h1[l+mid-1] - h1[l-1]*pw[mid] == h2[r-mid+1] - h2[r+1]*pw[mid]){
                x=mid;
                left=mid+1;
            }else right=mid-1;
        }
        if(x==r-l+1 || a[l+x]<=a[r-x]){
            if(cnt%80==0 && cnt>0) puts("");
            ++cnt;
            putchar(a[l]+'A'-1);
            ++l;
        }else{
            if(cnt%80==0 && cnt>0) puts("");
            ++cnt;
            putchar(a[r]+'A'-1);
            --r;
        }
    }

    return 0;
}

