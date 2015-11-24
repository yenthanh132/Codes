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

struct Point{
    int x,y;
    Point(){}
    Point(int _x, int _y):x(_x),y(_y){}
};

int n,r,m,mys[70*70];
Point convex[70*70];
Point arr[70*70];

vector<int> best_list, list;
int best_value, value;

int Turn(Point x, Point a, Point b){
    return (b.y-x.y) * (a.x-x.x) - (a.y-x.y) * (b.x-x.x);
}

int dis2(Point a, Point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool cmp(const Point &a, const Point &b){
    int v = Turn(arr[0],a,b);
    return (v>0 || (v==0 && dis2(arr[0],a) < dis2(arr[0],b)));
}

void generateConvex(){
    m=0;
    for(int x=-r; x<=r; ++x) for(int y=-r; y<=r; ++y) if(x*x+y*y<=r*r){
        arr[m++]=Point(x,y);
    }
    for(int i=1; i<m; ++i){
        if(arr[i].y<arr[0].y || (arr[i].y==arr[0].y && arr[i].x<arr[0].x)) swap(arr[i],arr[0]);
    }
    sort(arr+1,arr+m,cmp);
    int last=1;
    mys[1]=0;
    for(int i=1; i<m; ++i){
        while(last>1 && Turn(arr[mys[last-1]], arr[mys[last]], arr[i])<=0) --last;
        mys[++last] = i;
    }
    m=0;
    for(int i=1; i<=last; ++i) convex[m++]=arr[mys[i]];
}

void scan(int i, int prev, int sum_x, int sum_x2, int sum_y, int sum_y2){
    if(i==n){
        if(best_value == -1 || best_value < value){
            best_value = value;
            best_list = list;
        }
        return;
    }

    for(int idx = prev; idx < m; ++idx){
        int inc = i*(convex[idx].x*convex[idx].x) - 2*convex[idx].x*sum_x + sum_x2 +
                  i*(convex[idx].y*convex[idx].y) - 2*convex[idx].y*sum_y + sum_y2;
        value += inc;
        list.pb(idx);
        scan(i+1,idx,sum_x + convex[idx].x, sum_x2 + convex[idx].x*convex[idx].x,
                     sum_y + convex[idx].y, sum_y2 + convex[idx].y*convex[idx].y);
        list.pop_back();
        value -=inc;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&r);
    generateConvex();
    best_value=-1;
    scan(0,0,0,0,0,0);
    printf("%d\n",best_value);
    for(int i=0; i<sz(best_list); ++i) printf("%d %d\n",convex[best_list[i]].x,convex[best_list[i]].y);
    return 0;
}

