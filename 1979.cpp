#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int a[20][20] = { 0 };
int ans=0;
char s[25][25];
void go(int n, int m,int x,int y,char s[][25]) {
	if (n < 0 || n >= y || m < 0 || m >= x || s[n][m] == '#' || a[n][m] == 1)
		return;
	a[n][m] = 1;
	++ans;
	go(n-1, m, x, y, s); go(n+1, m, x, y, s); go(n, m-1, x, y, s); go(n, m+1, x, y, s);
}
int main() {
	int dx, dy;
	while (cin >> dx >> dy,dx) {
		ans = 0;
		memset(a, 0, sizeof(a));
		int x = dx, y = dy;
		int n,m;
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				cin >> s[i][j];
				if (s[i][j] == '@') { n = i; m = j; }
			}getchar();
		}
		go(n, m,x,y,s);
		cout << ans << endl;
	}
	//system("PAUSE");
	return 0;
}