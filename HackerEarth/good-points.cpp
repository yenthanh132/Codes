#include <iostream>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

void print8(int x, int n){
    if(n==0){
        cout<<x<<' '<<1<<endl;
        cout<<x<<' '<<0<<endl;
        return;
    }
    cout<<x<<' '<<1<<endl;
    cout<<x<<' '<<2<<endl;
    cout<<x+1<<' '<<2<<endl;
    cout<<x+1<<' '<<1<<endl;
    print8(x+2,n-8);
    cout<<x+1<<' '<<0<<endl;
    cout<<x+1<<' '<<-1<<endl;
    cout<<x<<' '<<-1<<endl;
    cout<<x<<' '<<0<<endl;
}

int main(){
//    freopen("input.txt","r",stdin);
    int n;
    cin>>n;

    if(n==1){
        cout<<"YES"<<endl<<"0 0"<<endl;
        return 0;
    }else if(n==2){
        cout<<"YES"<<endl<<"0 0"<<endl<<"1 0"<<endl;
        return 0;
    }else if((n-4)%8==0){
        cout<<"YES"<<endl;
        cout<<0<<' '<<0<<endl;
        cout<<0<<' '<<1<<endl;
        print8(1,n-4);
        return 0;
    }

    cout<<"NO"<<endl;
}

