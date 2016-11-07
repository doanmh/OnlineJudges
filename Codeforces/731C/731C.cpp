#include <cstdio>
#include <vector>

using namespace std;

#define MAXNUM 200000
#define DFS_VISTIED 1
#define DFS_UNVISITED -1

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int c[MAXNUM + 5], cnt[MAXNUM + 5];
vi adj[MAXNUM + 5], dfs_num, vs;

void dfs(int u) {
	if (dfs_num[u] == DFS_VISTIED) {
		return;
	}
	dfs_num[u] = DFS_VISTIED;
	vs.push_back(u);
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int w = adj[u][i];
		dfs(w);
	}
}

int main() {
	int m, n, k, x, y;
	int ans = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs_num.assign(n+1, DFS_UNVISITED);
	for (int i = 1; i <= n; i++) {
		if (dfs_num[i] == DFS_UNVISITED) {
			dfs(i);
			int max_color = 0;
			for (int i = 0; i < vs.size(); i++) {
				cnt[c[vs[i]]]++;
				max_color = max(max_color, cnt[c[vs[i]]]);
			}
			ans += vs.size() - max_color;
			for (int i = 0; i < vs.size(); i++) {
				cnt[c[vs[i]]] = 0;
			}
			vs.clear();
		}
	}
	printf("%d\n", ans);
	return 0;
}