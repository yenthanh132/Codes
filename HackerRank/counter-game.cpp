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
typedef unsigned long long ll;

int main(){
    int T;
    ll v;
    cin>>T;
    for(int tt=0; tt<T; ++tt){
        cin>>v;
        int c=0;
        for(int i=0; i<64; ++i) if(((v>>i)&1)==0) ++c; else break;
        for(int i=0; i<64; ++i) if(((v>>i)&1)==1) ++c;
        --c;
        if(c&1) cout<<"Louise"<<endl;
        else cout<<"Richard"<<endl;
    }
    return 0;
}
