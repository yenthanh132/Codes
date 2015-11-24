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
    if(x1==x2){
        int l=abs(y1-y2);
        cout<<x1+l<<' '<<y1<<' '<<x2+l<<' '<<y2<<endl;
    }else if(y1==y2){
        int l=abs(x1-x2);
        cout<<x1<<' '<<y1+l<<' '<<x2<<' '<<y2+l<<endl;
    }else if(abs(x1-x2)==abs(y1-y2)){
        cout<<x1<<' '<<y2<<' '<<x2<<' '<<y1<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}
