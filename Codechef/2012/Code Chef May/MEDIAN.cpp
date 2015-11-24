#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

typedef pair<int,int> II;

int a[30],n;

void solve(){
    int count=0,imax=0,i,j,k,v=0,m;
    II t;
    for(i=1;i<n;i++) if(a[imax]<a[i]) imax=i;
    for(i=0;i<n;i++) if(a[i]==a[imax]) count++;
    m=(int) (log(n)/log(2));
    if (pow(2,m)<n) m++;
    if (count==1){
        cout<<m<<endl;
        return;
    }
    queue<II> q;
    for(i=0;i<n;i++) if(a[i]==a[imax]) v+=1<<i;
    if (v==(1<<n)-1){
        cout<<0<<endl;
        return;
    }
    q.push(II(v,0));
    while (!q.empty()){
        t=q.front(); q.pop(); 
        for(i=0;i<n;i++){
            count=0;
            for(j=i;j>=0;j--) if ((t.first>>j)&1==1) count++;
            for(j=0;j <= i && (i-j+1)/2+1 <= (i-j+1)-count;j++) if ((t.first>>j)&1==1) count--;
            if (j<=i){
                v=t.first;
                for (k=j;k<=i;k++) v|=1<<k;
                if (v == (1<<n) - 1){
                    cout<<t.second+1<<endl;
                    return;
                }
                if (t.second<m-1 && v>t.first) q.push(II(v,t.second+1));
            }
        }
    }
}
int main(){
    freopen("test.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,i,j;
    cin >>t;
    for(i=0;i<t;i++){
        cin>>n;
        for(j=0;j<n;j++) cin>>a[j];
        solve();
    }
}
