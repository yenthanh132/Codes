#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<double,double> pii;
typedef long long ll;

const int maxn=10007;

int n,m;
pii a[maxn],b[maxn];

void moveOriginal(pii *a){
    for(int i=m; i>=1; --i){
        a[i].first -= a[1].first;
        a[i].second -= a[1].second;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; ++i) scanf("%lf%lf",&a[i].first,&a[i].second);
    sort(a+1,a+m+1);
    moveOriginal(a);
    double len1=hypot(a[1].first-a[2].first,a[1].second-a[2].second);
    for(int r=0; r<n; ++r){
        for(int i=1; i<=m; ++i) scanf("%lf%lf",&b[i].first,&b[i].second);
        sort(b+1,b+m+1);
        moveOriginal(b);
        double len2=hypot(b[1].first-b[2].first,b[1].second-b[2].second);
//        double scale = len1/len2;
//        for(int i=1; i<=m; ++i){
//            b[i].first*=scale;
//            b[i].second*=scale;
//        }
        bool ok=1;
        for(int i=1; i<=m; ++i)
            if(abs(a[i].first / len1 - b[i].first / len2)>1e-12 || abs(a[i].second / len1 - b[i].second / len2)>1e-12){
                ok=0;
                break;
            }
        if(ok) puts("YES"); else puts("NO");
    }
}
