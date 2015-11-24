#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const double PI = acos(-1);
double v,R;
int n;

int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n>>R>>v;
    double period = 2*R*PI / v;
    for(int i=1; i<=n; ++i){
        double s, f;
        cin>>s>>f;
        double len=f-s;

        double l=0, r=oo, mid;
        for(int i=0; i<100; ++i){
            mid=(l+r)/2;
            double x = v*mid;
            x += R*sin( mid / period * 2 * PI);
            if(x>=len){
                r=mid;
            }else{
                l=mid;
            }
        }
        cout<<r<<endl;
    }
}

