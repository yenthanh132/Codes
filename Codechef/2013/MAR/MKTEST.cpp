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
    freopen("input.txt","w",stdout);
    cout<<1<<endl;
    REP(i,2){
        cout<<"94 ";
        FOR(j,1,94) cout<<char(j+32);
        cout<<endl;
    }
    srand(time(NULL));
    REP(i,94) REP(j,94) cout<<char(i+33)<<char(j+33)<<' '<<randi(10000000)<<endl;
    return 0;
}
