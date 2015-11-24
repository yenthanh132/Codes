#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int point(int p, int t){
    return max(3*p/10, p - p*t/250);
}

int main(){
//    freopen("input.txt","r",stdin);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int p1=point(a,c), p2=point(b,d);
    if(p1>p2) cout<<"Misha";
    else if(p1<p2) cout<<"Vasya";
    else cout<<"Tie";
}

