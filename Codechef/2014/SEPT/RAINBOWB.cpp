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

int C[1000007][7];

int main(){
    C[0][0]=1;
    for(int i=1; i<=1000000; ++i){
        C[i][0]=1;
        for(int j=0; j<=6; ++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%oo;
    }
    int res,n;
    cin>>n;
    res = 0;
    for(int v=1; v<=n-12; ++v)
        if((n-v)%2==0)
            res = (res + C[(n-v)/2-1][5])%oo;
    cout<<res<<endl;

    return 0;
}
