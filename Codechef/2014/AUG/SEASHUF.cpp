#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

int n,a[maxn],len;
pii b[maxn];
vector<pii> q,p;

ll myabs(ll v){return v>0?v:-v;}

int main(){

    freopen("input.txt","r",stdin);

    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    ll init = 0, best;
    for(int i=1; i<=n; ++i) init += a[i]*(i<=n/2?1:-1);
    best = myabs(init);
    q.clear();
    ll left_sum = 0, right_sum = 0, val, cost;
    for(int len=1; len*(len+1)/2<=n && len<=n/2; ++len){
        right_sum += a[n/2+len];
        val = init + right_sum * 2;
        cost = len*(len+1)/2;
        p.clear();
        int pos = n/2+len;
        for(int i=n/2; i>=1 && sz(p)<len; --i){
            if(val<=0){
                for(int j=1; j<=i; ++j) b[j]=pii(a[j],-j);
                sort(b+1,b+i+1);
                for(int j=1; j<=i && sz(p)<len; ++j) if(cost + n/2+b[j].second+1 <= 2*n){
                    cost+=n/2-b[j].second+1;
                    val-=b[j].first*2;
                    p.pb(pii(-b[j].second,pos--));
                }
                break;
            }
            if(cost + n/2 - i + 1 <= 2*n && myabs(val - a[i]*2) < best ){
                cost += n/2-i+1;
                val -= a[i]*2;
                p.pb(pii(i,pos--));
            }
        }
        val=myabs(val);
        if(val < best){
            best = val;
            q=p;
        }
    }
    cout<<myabs(init)<<' '<<best<<endl;
    printf("%d\n",sz(q));
    for(int i=0; i<sz(q); ++i) printf("%d %d\n",q[i].first,q[i].second);



    return 0;
}
