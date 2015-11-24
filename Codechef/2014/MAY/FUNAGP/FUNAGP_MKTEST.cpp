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

int maxn=10000;
int m=10000;
int maxv=100000;
int minv=50000;
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
    cout<<10<<endl;
    srand(time(NULL));
    REP(tt,10){
        cout<<maxn<<' '<<m<<' '<<rand()+1<<' '<<86028121<<' '<<86028157<<endl;
        
        FOR(i,1,maxn) cout<<randi(maxv-minv+1)+minv<<' '; cout<<endl;
        FOR(i,1,m){
            int type=rand()%3;
            cout<<type<<' ';
            if(type==0){
                int x=rand()%maxn+1;
                int y=randi(maxn)+1;
                if(x>y) swap(x,y);
                cout<<randi(maxv-minv+1)+minv<<' '<<randi(maxv-minv+1)+minv<<' '<<x<<' '<<y<<endl;
            }else if(type==1){
                cout<<randi(maxn)+1<<' '<<rand()%1000+1<<endl;
            }else{
                int x=randi(maxn)+1;
                int y=randi(maxn)+1;
                if(x>y) swap(x,y);
                cout<<x<<' '<<y<<endl;
            }
        }   
    }
    return 0;
}
