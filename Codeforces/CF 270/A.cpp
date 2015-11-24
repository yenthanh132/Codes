#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

bool isprime(int n){
    if(n==2 || n==3) return 1;
    if(n<2 || n%2==0 || n%3==0) return 0;
    int sn=(int) sqrt(n);
    int k=0;
    do{
        k+=6;
        if(n%(k-1)==0 || n%(k+1)==0) break;
    }while(k<=sn-1);
    return k>sn-1;
}

int main(){
    //freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=4; i<=n; ++i){
        if(!isprime(i) && !isprime(n-i)){
            cout<<i<<' '<<n-i<<endl; return 0;
            }
    }
    return 0;
}

