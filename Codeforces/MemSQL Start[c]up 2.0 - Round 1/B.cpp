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

int m,n;
bool rev = 0;

void pp(int x, int y){
    if(rev) cout<<y<<' '<<x<<endl;
    else cout<<x<<' '<<y<<endl;
}

double len(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
    return hypot(x1-x2,y1-y2)+hypot(x2-x3,y2-y3)+hypot(x3-x4,y3-y4);
}

int main(){

    cin>>m>>n;
    rev=0;
    if(m>n){
        swap(m,n);
        rev=1;
    }
    if(m==0){
        pp(0,1);
        pp(0,n);
        pp(0,0);
        pp(0,n-1);
    }else{
        if(len(0,0,m,n,m,0,0,n) > max(len(1,0,m,n,0,0,m-1,n), len(0,1,m,n,0,0,m,n-1))){
            pp(0,0);
            pp(m,n);
            pp(m,0);
            pp(0,n);
        }else if(len(1,0,m,n,0,0,m-1,n) > len(0,1,m,n,0,0,m,n-1)){
            pp(1,0);
            pp(m,n);
            pp(0,0);
            pp(m-1,n);
        }else{
            pp(0,1);
            pp(m,n);
            pp(0,0);
            pp(m,n-1);
        }

    }
}
