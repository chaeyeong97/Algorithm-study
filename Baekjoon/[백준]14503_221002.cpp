#include <iostream>
using namespace std;

int n, m;
int ans;
int map[51][51];
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

void dfs(int y, int x, int dir)
{
	if (map[y][x] == 0)     // ���� ��ġ û��
	{
		map[y][x] = 2;
		ans++;
	}

	for (int i = 0; i < 4; i++)  // �� ���� �� Ȯ��
	{
		int ndir = (dir + 3 - i) % 4;
		int ny = y + dr[ndir];
		int nx = x + dc[ndir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
		{
			continue;
		}

		if (map[ny][nx] == 0)   //û������ ���� ������ ������ ���
		{
			dfs(ny, nx, ndir);
		}
	}

	//�� ������ �� Ȯ���� �� ���� �������� ����
	int ndir = (dir + 2) % 4;   
	int ny = y + dr[ndir];
	int nx = x + dc[ndir];

	//������ �Ұ��� ���
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