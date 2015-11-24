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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int n=100000;

double randf() {
    double base = 0.1;
    double res = 0;
    for (int i = 0; i < 15; i++) {
        res += base * (rand() % 10);
        base /= 10;
    }
    return res;
}

int randi(int n) {
    return (int)floor(randf() * n);
}

int main(){
    freopen("test.txt","w",stdout);
    cout<<n<<endl;
    FOR(i,1,n)
        cout<<randi(100000)+1<<' '<<randi(i)<<endl;
    cout<<n<<endl;
    FOR(i,1,n){
        int t=randi(2)+1;
        if(t==1) cout<<"1 "<<randi(n)+1<<' '<<randi(100000)+1<<endl;
        else cout<<"2 "<<randi(n)+1<<endl;
    }
    return 0;
}
