#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int get(int n){
    if(n==1) return 0;
    for(int i=1; ;++i) if(i*(i+1)/2 + 1>=n) return i;
}


int main(){
    //freopen("input.txt","r",stdin);
    int t,n;
    cin>>t;

    while(t--){
        cin>>n;
        cout<<get(n)<<endl;
    }
}

