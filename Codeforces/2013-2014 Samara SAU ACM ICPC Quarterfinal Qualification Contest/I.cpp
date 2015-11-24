#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

multiset<int> mys;
int n,res;
ll sum;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    res=0; sum=0;
    int t,d;
    for(int i=0; i<n; ++i){
        scanf("%d%d",&t,&d);
        sum+=d;
        mys.insert(d);
        if(sum>t){
            multiset<int>::iterator it = mys.end();
            it--;
            sum-=*it;
            mys.erase(it);
            ++res;
        }
    }
    cout<<res<<endl;
}

