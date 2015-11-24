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
    int n,x,y;
    int c=0;
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>x>>y;
        if(x+2<=y) ++c;
    }
    cout<<c<<endl;
}

