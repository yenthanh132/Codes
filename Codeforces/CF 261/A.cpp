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
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1!=x2 && y1!=y2 && abs(x2-x1)!=abs(y2-y1)){
        puts("-1");
        return 0;
    }
    int l=abs(x2-x1);
    if(l==0) l=abs(y2-y1);
    int x3,y3,x4,y4;

    if(x1==x2){
        y3=y1; y4=y2;
        x3=x1+l; x4=x2+l;
    }else if(y1==y2){
        y3=y1+l; y4=y2+l;
        x3=x1; x4=x2;
    }else{
        if(x1<x2){
            y3=y1; y4=y2;
            x3=x1+l; x4=x2-l;
        }else{
            y3=y1; y4=y2;
            x3=x1-l; x4=x2+l;
        }
    }
    cout<<x3<<' '<<y3<<' '<<x4<<' '<<y4;
    return 0;
}
