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
    int n,min1,max1,min2,max2,min3,max3;
    cin>>n>>min1>>max1>>min2>>max2>>min3>>max3;
    int a=min1, b=min2, c=min3;
    while(a+b+c<n){
        if(a<max1){
            ++a;
        }else if(b<max2){
            ++b;
        }else{
            ++c;
        }
    }
    cout<<a<<' '<<b<<' '<<c<<endl;
}

