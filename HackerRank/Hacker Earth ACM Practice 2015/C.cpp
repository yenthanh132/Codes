#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;

int a[maxn],n;

int calc(int v){
    int res=0,sum=0,l=1;
    for(int i=1; i<=n; ++i){
        sum+=a[i];
        while(sum>v) sum-=a[l++];
        if(sum==v){
            l=i+1;
            sum=0;
            ++res;
        }
    }
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);

    int res=0;
    set<int> mys;
    for(int i=1; i<=n; ++i){
        int sum=0;
        for(int j=i; j<=n; ++j){
            sum+=a[j];
            int r=calc(sum);
            if(r>res){
                res=r;
                mys.clear();
                mys.insert(sum);
            }else if(r==res)
                mys.insert(sum);
        }
    }

    printf("%d\n",res);
    for(set<int>::iterator it=mys.begin(); it!=mys.end(); ++it) printf("%d ",*it);
}

