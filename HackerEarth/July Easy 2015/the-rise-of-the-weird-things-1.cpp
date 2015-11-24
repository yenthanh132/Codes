#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

vector<int> a0,a1;

void printout(vector<int> &a){
    int total=0;
    sort(a.begin(),a.end());
    for(int i=0; i<sz(a); ++i){
        cout<<a[i]<<' ';
        total+=a[i];
    }
    cout<<total<<' ';
}

int main(){
//    freopen("input.txt","r",stdin);
    int n,v;
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>v;
        if(v&1) a1.pb(v);
        else a0.pb(v);
    }

    printout(a0); printout(a1);
}

