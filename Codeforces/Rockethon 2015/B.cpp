#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n,a[55];
ll m,p2[55];

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n>>m;
    p2[0]=1;
    for(int i=1; i<=50; ++i) p2[i]=p2[i-1]*2;
    int l=1, r=n, cnt=n-1;
    for(int num=1; num<=n; ++num){
        --cnt;
        if(cnt>=0 && m>p2[cnt]){
            a[r--]=num;
            m-=p2[cnt];
        }else{
            a[l++]=num;
        }
    }
    for(int i=1; i<=n; ++i) cout<<a[i]<<' ';
    cout<<endl;
}

