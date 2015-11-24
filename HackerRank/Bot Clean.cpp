#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;


int n,x[30],y[30],a[30][30],d[30],f[30],best,sum;
bool free1[30];

/* Head ends here */

int dis(int x1, int y1, int x2, int y2){
    return abs(x1-x2)+abs(y1-y2);
}

void duyet(int id){
    if(id>n){
        if(sum<best){
            best=sum;
            for(int i=1; i<=n; i++) f[i]=d[i];
        }
        return;
    }
    if(sum>=best) return;
    for(int i=1; i<=n; i++) if(free1[i]){
        d[id]=i;
        sum+=a[d[id-1]][d[id]];
        free1[i]=0;
        duyet(id+1);
        sum-=a[d[id-1]][d[id]];
        free1[i]=1;
    }
}

void do_move(int x1, int y1, int x2, int y2){
    if(x1<x2) cout<<"DOWN"; 
    else if(x1>x2) cout<<"UP";
    else if(y1<y2) cout<<"RIGHT";
    else cout<<"LEFT";
    cout<<endl;
}

void next_move(int posx, int posy, vector <string> board) {
    if(board[posx][posy]=='d'){
        cout<<"CLEAN"<<endl;
        return;
    }
    
    n=0;
    for(int i=0; i<5; i++) for(int j=0; j<5; j++) if(board[i][j]=='d'){
        n++;
        x[n]=i; y[n]=j;
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) a[i][j]=dis(x[i],y[i],x[j],y[j]);
    for(int i=1; i<=n; i++) a[0][i]=a[i][0]=dis(posx,posy,x[i],y[i]);
    
    memset(free1,1,sizeof(free1));
    best=100007;
    sum=0;
    d[0]=0;
    duyet(1);
    do_move(posx,posy,x[f[1]],y[f[1]]);
}
/* Tail starts here */
