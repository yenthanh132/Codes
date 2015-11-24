#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
 
char arr[8][8];
bool mark[8][8];
 
bool ok(int x, int y){
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}
 
char tolower(char ch){
    if(ch<='Z') ch=ch-'A'+'a';
    return ch;
}
 
const int kmove[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
 
void move(int x, int y, int dx, int dy) {
    mark[x][y] = false;
    FOR(step,1,7){
        int xx = step * dx + x, yy = step * dy + y;
        if (ok(xx, yy)) {
            if (arr[xx][yy] == '.')
                mark[xx][yy] = false;
            else
                break;
        } else {
            continue;
        }
        mark[xx][yy] = false;
    }
}
 
void goAskary(char ch, int x, int y) {
    mark[x][y] = false;
    if (ch == 'p') {
        if (ok(x + 1, y - 1) && arr[x + 1][y - 1] == '.') mark[x + 1][y - 1] = false;
        if (ok(x + 1, y + 1) && arr[x + 1][y + 1] == '.') mark[x + 1][y + 1] = false;
    }
    if (ch == 'P') {
        if (ok(x - 1, y - 1) && arr[x - 1][y - 1] == '.') mark[x - 1][y - 1] = false;
        if (ok(x - 1, y + 1) && arr[x - 1][y + 1] == '.') mark[x - 1][y + 1] = false;
    }
}
 
void goRook(int x, int y) {
    move(x, y, -1, 0);
    move(x, y, +1, 0);
    move(x, y, 0, +1);
    move(x, y, 0, -1);
}
 
void goFeel(int x, int y) {
    move(x, y, -1, -1);
    move(x, y, +1, +1);
    move(x, y, -1, +1);
    move(x, y, +1, -1);
}
 
void goQueen(int x, int y) {
    goRook(x, y);
    goFeel(x, y);
}
 
void goKnight(int x, int y) {
    mark[x][y] = false;
    FOR(dx,-2,2) FOR(dy,-2,2)
        if (abs(dx * dy) == 2) {
            int xx = dx + x, yy = dy + y;
            if (ok(xx, yy) && arr[xx][yy] == '.')
                mark[xx][yy] = 0;
        }
}
 
void goKing(int x, int y) {
    mark[x][y] = false;
    REP(i,8){
        int xx = x + kmove[i][0], yy = y + kmove[i][1];
        if (ok(xx, yy) && arr[xx][yy] == '.')
            mark[xx][yy] = 0;
    }
}

 
#include <conio.h>
int main() {
    //freopen("test.txt","r",stdin);
    string s,ss;
    while(cin>>s){
        REP(i,sz(s)) if (s[i] == '/') s[i] = ' ';
        reset(mark,1);
        stringstream sin(s);
        for (int row = 0; sin >> ss; ++row) {
            int posIndx = -1;
            for (int i = 0; i < sz(ss); ++i)
                if (isdigit(ss[i])) {
                    if (posIndx == -1) posIndx = i;
                    for (int j = i; j < i + (ss[i] - '0'); ++j)
                        arr[row][posIndx++] = '.';
                } else {
                    if (posIndx == -1) posIndx = i;
                    arr[row][posIndx++] = ss[i];
                }
        }
        
       REP(i,8) REP(j,8)
            if(tolower(arr[i][j])=='p') goAskary(arr[i][j],i,j);
            else if(tolower(arr[i][j])=='r') goRook(i, j);
            else if(tolower(arr[i][j])=='n') goKnight(i, j);
            else if(tolower(arr[i][j])=='b') goFeel(i, j);
            else if(tolower(arr[i][j])=='q') goQueen(i, j);
            else if(tolower(arr[i][j])=='k') goKing(i, j);
           
        int res = 0;
        REP(i,8) REP(j,8) res += mark[i][j];
        printf("%d\n", res);
    }
    //getch();
    return 0;
}
