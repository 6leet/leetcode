class Solution {
public:
    vector<bool> discover;
    vector<bool> visited;
    vector<vector<int> > G;
    stack<int> s;
    bool cycle = false;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        discover.resize(numCourses);
        visited.resize(numCourses);
        G.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int s = prerequisites[i][1], t = prerequisites[i][0];
            G[s].push_back(t);
        }
        for (int i = 0; i < discover.size(); i++) {
            discover[i] = false;
            visited[i] = false;
        }
        for (int i = 0; i < numCourses; i++) {
            if (!discover[i] && !visited[i]) {
                dfs(i);
            }
        }
        return !cycle;
    }
    void dfs(int n) {
        discover[n] = true;
        for (int i = 0; i < G[n].size(); i++) {
            if (!discover[G[n][i]] && !visited[G[n][i]]) {
                dfs(G[n][i]);
            } else if (discover[G[n][i]] && !visited[G[n][i]]) {
                cycle = true;
                return;
            }
        }
        visited[n] = true;
    }
};
