#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

int a[18],n,d[262144];
string s1,s2,s3;

bool canfix(int s, int f){
    string str=s2.substr(s,f-s+1);
    string s1_dao,s3_dao;
    int i;
    s1_dao=""; for (i=s1.size()-1;i>=0;i--) s1_dao=s1_dao+s1[i];
    s3_dao=""; for (i=s3.size()-1;i>=0;i--) s3_dao=s3_dao+s3[i];
    if ((s1.find(str)!=-1) || (s1_dao.find(str)!=-1) || (s3.find(str)!=-1) || (s3_dao.find(str)!=-1)) return 1; else return 0;
}
    

int solve(){
    queue <int> q;
    memset(d,0,sizeof(d));
    q.push(0);
    while (!q.empty()){
        int tt = q.front(); q.pop();
        int i,j,x,y,k;
        s3=s2;
        for (i=0;i<n;i++) if ((tt >> i) & 1) a[i]=1; else {a[i]=0; s3[i]="0";}
        
        i=0; while ((i<n) && (a[i]!=0)) i++;
        while (i<n){
            j=i;
            while ((j<n-1) && (a[j+1]=0)) j++;
            for (x=i; x<=j; x++)
                for (y=j; y>=x; y--) if (canfix(x,y)){
                    int tt_new=tt;
                    for (k=x; k<=y; k++) tt_new = tt_new | (1 << k);
                    if (tt_new == 1 << (n - 1)) return d[tt]+1;
                    if (d[tt_new]=0){
                        d[tt_new]=d[tt]+1;
                        q.push(tt_new);
                    }
                    break;
                }
            i=j+1; while ((i<n) && (a[i]!=0)) i++;
        }
    }
    return -1;
}

int main(){
    freopen("test.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int test;
    cin >> test;
    for (int index=0; index<test; index++){
        int i;
        cin >> s1;
        cin >> s2;
        n=s2.size();
        int res=solve();
        if (res!=-1) cout << res << endl; else cout << "Impossible" << endl;
    }
    return 0;
}
