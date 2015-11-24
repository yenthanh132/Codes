#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

vector<pii> lst;

void go(int x, int y){
    lst.pb(pii(x,y));
}

int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    go(0,0); //black
    go(9,9);
    for(int c=79; c>=1; --c){
        int x=1, y=1;
        for(int r=0; r<c; ++r){
            go(x,y); //black
            ++y; if(y>9){ ++x; y=1; }
            if(r<c-1) go(0,0); //white
            else go(x,y); //white
        }
    }
    go(1,1); //black
    go(1,9); //white
    for(int c=79; c>=2; --c){
        int x=1, y=1;
        if(c==79) ++x;
        for(int r=0; r<c; ++r){
            go(x,y); //black
            if(c==79 && r==0) r=1;
            if(y>1){
                --x;
                if(x==0) { x=9; ++y; }
            }else{
                ++x;
                if(x>9){ x=9; ++y; }
            }
            if(r<c-1) go(0,0); //white
            else go(x,y); //white
        }
    }

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; ++i) printf("%d %d\n",lst[i].first, lst[i].second);

}

