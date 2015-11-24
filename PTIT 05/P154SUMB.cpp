#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;
int a[maxn],n,b[maxn];
ll res;

void mergeSort(int l, int r){
    if(l==r) return;
    int mid=(l+r)/2;
    mergeSort(l,mid); mergeSort(mid+1,r);

    int x=l, y=mid+1;
    for(y=mid+1; y<=r; ++y){
        while(x<=mid && a[x]<=a[y]) ++x;
        res+=(mid-x+1);
    }

    x=l; y=mid+1;
    int z=l;
    while(x<=mid || y<=r)
        if(y>r || (x<=mid && a[x]<a[y])) b[z++]=a[x++];
        else b[z++]=a[y++];
    for(int i=l; i<=r; ++i) a[i]=b[i];

}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);

    res=0;
    mergeSort(1,n);
    cout<<res<<endl;
}

