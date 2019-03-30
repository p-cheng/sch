
#include "iostream"
#include "vector"

using namespace std;

bool condition(int x, int y, int k)
{
	if (x < 0 || y < 0 || k < 0)
		return false;
	int count = 0;
	while (x || y)
	{
		count += x % 10;
		count += y % 10;
		x = x / 10;
		y = y / 10;
	}
	return count <= k;
}

void backTracking(bool* reachable, int nextX, int nextY, int k, int m, int n, int* count)
{
	if (!condition(nextX, nextY, k))
		return;

	if (nextX >= 0 && nextY >= 0 && nextX < m && nextY < n && !reachable[nextX*m + nextY])
	{
		++*count;
		reachable[nextX*m + nextY] = true;
		backTracking(reachable, nextX - 1, nextY, k, m, n, count);
		backTracking(reachable, nextX + 1, nextY, k, m, n, count);
		backTracking(reachable, nextX, nextY - 1, k, m, n, count);
		backTracking(reachable, nextX, nextY + 1, k, m, n, count);
	}
}


int movable(int m, int n, int k)
{
	int total = m * n;
	bool* reachable = new bool[total];
	for (int i = 0; i < total; ++i)
		reachable[i] = false;

	int count = 0;
	backTracking(reachable, 0, 0, k, m, n, &count);

	delete[] reachable;
	return count;
}


int main()
{
	int m = 0, n = 0, k = 0;
    cin >> m >> n >> k;
	cout << movable(m, n, k) << endl;
	return 0;
}
