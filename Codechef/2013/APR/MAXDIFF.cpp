#include <iostream>
#include <algorithm>

using namespace std;

int n,t,a[107],k;

int main(){
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n>>k;
        for(int j=1; j<=n; j++) cin>>a[j];
        sort(a+1,a+n+1);
        if(k*2>n) k=n-k;
        int s1=0,s2=0;
        for(int j=1; j<=k; j++) s1+=a[j];
        for(int j=k+1; j<=n; j++) s2+=a[j];
        cout<<abs(s2-s1)<<endl;
    }
    return 0;
}
