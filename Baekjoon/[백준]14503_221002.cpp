#include <iostream>
using namespace std;

int n, m;
int ans;
int map[51][51];
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

void dfs(int y, int x, int dir)
{
	if (map[y][x] == 0)     // 현재 위치 청소
	{
		map[y][x] = 2;
		ans++;
	}

	for (int i = 0; i < 4; i++)  // 네 방향 다 확인
	{
		int ndir = (dir + 3 - i) % 4;
		int ny = y + dr[ndir];
		int nx = x + dc[ndir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
		{
			continue;
		}

		if (map[ny][nx] == 0)   //청소하지 않은 공간이 존재할 경우
		{
			dfs(ny, nx, ndir);
		}
	}

	//네 방향을 다 확인한 후 뒤쪽 방향으로 후진
	int ndir = (dir + 2) % 4;   
	int ny = y + dr[ndir];
	int nx = x + dc[ndir];

	//후진도 불가할 경우
	if (map[ny][nx] == 1)
	{
		cout << ans;
		exit(0);
	}
	
	dfs(ny, nx, dir);
}

int main()
{
	cin >> n >> m;

	int r, c, d;
	cin >> r >> c >> d;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> map[y][x];
		}
	}

	dfs(r, c, d);
}