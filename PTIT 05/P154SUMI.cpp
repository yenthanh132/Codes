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
    int n;
    cin>>n;
    int c=0;
    for(int x=1; x<=n; ++x) for(int y=x+1; y<=n; ++y){
        int t=x*x+y*y;
        int st=(int)(sqrt(t)+1e-9);
        if(st<=n && st*st==t) ++c;
    }
    cout<<c<<endl;
}

