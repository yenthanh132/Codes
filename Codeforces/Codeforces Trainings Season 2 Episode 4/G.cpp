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
    int n,s,sign=1;
    cin>>n>>s;
    if(s<0){
        s=-s;
        sign=-1;
    }

    int sum = n*(n-1)/2;
    int left = sum - s;
    if(sum < s || left&1){
        cout<<-1<<endl;
        return 0;
    }

    printf("0");
    for(int i=2, val=0; i<=n; ++i){
        if((n-i+1)*2<=left){
            --val;
            left-=(n-i+1)*2;
        }else{
            ++val;
        }
        printf(" %d",val*sign);
    }

    return 0;
}

