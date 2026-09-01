class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<pair<int,int>> litter;
        int sr = 0, sc = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // All litter already collected
        if (k == 0) return 0;

        // mask = collected litter
        // state: row, col, remaining energy, mask
        int totalMasks = 1 << k;

        struct State {
            int r, c, e, mask, dist;
        };

        queue<State> q;

        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> vis(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(totalMasks, false)
                )
            )
        );

        q.push({sr, sc, energy, 0, 0});
        vis[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int r = cur.r;
            int c = cur.c;
            int e = cur.e;
            int mask = cur.mask;
            int dist = cur.dist;

            if (mask == totalMasks - 1)
                return dist;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                // Cannot make a move with 0 energy
                if (e == 0)
                    continue;

                int ne = e - 1;
                int nmask = mask;

                // Collect litter
                for (int i = 0; i < k; i++) {
                    if (litter[i].first == nr && litter[i].second == nc) {
                        nmask |= (1 << i);
                        break;
                    }
                }

                // Reset energy on R
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                if (!vis[nr][nc][ne][nmask]) {
                    vis[nr][nc][ne][nmask] = true;
                    q.push({nr, nc, ne, nmask, dist + 1});
                }
            }
        }

        return -1;
    }
};