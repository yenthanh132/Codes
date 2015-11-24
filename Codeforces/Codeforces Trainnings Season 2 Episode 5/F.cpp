#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

multiset<double> mys;
int arr[55];
int w,p,n;
double pp;

bool check(double v){
    mys.clear();
    for(int i=0; i<n; ++i) mys.insert(arr[i]);
    if(v>0) mys.insert(v);
    while(sz(mys)>1){
        double v1=*mys.begin(); mys.erase(mys.begin());
        double v2=*mys.begin(); mys.erase(mys.begin());
        double v3=(v1+v2)*(1.0 + pp/(100-pp));
        mys.insert(v3);
    }
    return *mys.begin() <= w;
}

int main(){
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&w,&p,&n);
        pp=p;
        int v;
        for(int i=0; i<n; ++i){
            scanf("%d",&v);
            arr[i]=v;
        }
        double left=0, right=w, mid;
        while(left+1e-9<right){
            mid=(left+right)/2;
            if(check(mid)) left=mid;
            else right=mid;
        }
        double res=left;
        if(!check(res)) puts("-1");
        else printf("%0.9lf\n",res);
    }
}

