#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200007;
struct num{
    int val,pos,x;
} a[maxn];
int n;

bool cmp(const num &a, const num &b){
    return a.val < b.val;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i].x);
        a[i].val = a[i].x + i;
        a[i].pos = i;
    }

    sort(a+1,a+n+1,cmp);
    for(int i=1; i<n; ++i) if(a[i].val == a[i+1].val){
        cout<<":("<<endl;
        return 0;
    }else if(a[i].x+(a[i].pos-i)<0){
        cout<<":("<<endl;
        return 0;
    }
    for(int i=1; i<=n; ++i) printf("%d ",a[i].x + (a[i].pos - i));
}

