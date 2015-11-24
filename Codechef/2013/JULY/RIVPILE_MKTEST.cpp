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


const int T=30;
const int w=1000000000;

const int max_x=100;
const int max_y=1000000000;

const int max_r=100000000;
const int max_c=10000;

const int max_n=200;
const int max_m=150;

int n,m,x,y,r,c;

int main(){
    freopen("test.txt","w",stdout);
    printf("%d\n",T);
    srand(time(NULL));
    REP(tt,T){
        n=rand()%(max_n-150+1)+150;
        m=rand()%(max_m-150+1)+150;
        printf("%d %d %d\n",n,m,w);
        FOR(i,1,n){
            x=randi(max_x+1);
            y=randi(max_y)+1;
            printf("%d %d\n",x,y);
        }
        FOR(i,1,m){
            r=randi(max_r)+1;
            c=randi(max_c)+1;
            printf("%d %d\n",r,c);
        }
    }
    return 0;
}
