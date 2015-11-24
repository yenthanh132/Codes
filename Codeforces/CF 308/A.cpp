#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
//    freopen("input.txt","r",stdin);
    int n,x1,y1,x2,y2;
    cin>>n;
    int res=0;
    for(int i=0; i<n; ++i){
        cin>>x1>>y1>>x2>>y2;
        res+=(x2-x1+1)*(y2-y1+1);
    }
    cout<<res<<endl;
}

