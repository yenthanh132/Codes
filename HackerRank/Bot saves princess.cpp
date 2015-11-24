#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
/* Head ends here */
void displayPathtoPrincess(int n, vector <string> grid){
    int x1, y1,x2,y2;
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) 
        if(grid[i][j]=='m'){x1=i;y1=j;}
        else if(grid[i][j]=='p') {x2=i; y2=j;}
    for(int i=0; i<abs(x1-x2); ++i) if(x1<x2) cout<<"DOWN"<<endl; else cout<<"UP"<<endl;
    for(int i=0; i<abs(y1-y2); ++i) if(y1<y2) cout<<"RIGHT"<<endl; else cout<<"LEFT"<<endl;
}
