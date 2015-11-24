#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


int main(){
//    freopen("input.txt","r",stdin);
    int n,x,y;
    int maxx=-oo, minx=oo, maxy=-oo, miny=oo;
    cin>>n;
    for(int i=0; i<n;++i){
        cin>>x>>y;
        minx=min(minx,x);
        maxx=max(maxx,x);
        miny=min(miny,y);
        maxy=max(maxy,y);
    }
    int area = (maxy-miny)*(maxx-minx);
    if(area==0) area=-1;
    cout<<area<<endl;
}

