#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

vector<int> T;
int D[1111];
int n;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0; i<n; ++i){
        int k;
        string s;
        cin>>s>>k;
        if(s=="T") T.pb(k);
        else ++D[k];
    }
    double res=0;
    int cnt=1;
    sort(T.begin(),T.end());
    int it=0;
    for(int i=0; i<1000; ++i){
        cnt+=D[i];
        double cost=cnt;
        double len=1;
        while(it<sz(T) && res+cost>=T[it]){
            len-=(T[it]-res)/cnt;
            res=T[it];
            ++it;
            ++cnt;
            cost=len*cnt;
        }
        res+=cost;
    }
    printf("%0.0f",res);
}

