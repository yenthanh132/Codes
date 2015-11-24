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

int main(){
    int c,n,a,b;
    cin>>n;
    c=0;
    for(int i=0; i<n; ++i){
        cin>>a>>b;
        if(a+2<=b) ++c;
    }
    cout<<c<<endl;
    return 0;
}
