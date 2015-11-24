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
    //freopen("input.txt","r",stdin);
    int n;
    int minx,maxx,miny,maxy;
    minx=miny=oo;
    maxx=maxy=-oo;
    int x,y;
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>x>>y;
        minx=min(minx,x);
        miny=min(miny,y);
        maxx=max(maxx,x);
        maxy=max(maxy,y);
    }
    cout<<sqr(max(maxx-minx,maxy-miny))<<endl;
}

