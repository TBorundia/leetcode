class Solution {
public:
    void dfs(int node, int dist, vector<int>& edges, vector<int>& fromNode) {
        if (fromNode[node] != INT_MAX) {
            return;
        }
        fromNode[node] = dist;
        if (edges[node] != -1) {
            dfs(edges[node], dist + 1, edges, fromNode);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> fromNode1(n, INT_MAX);
        dfs(node1, 0, edges, fromNode1);
        vector<int> fromNode2(n, INT_MAX);
        dfs(node2, 0, edges, fromNode2);
        int mini = INT_MAX;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int maxi = max(fromNode1[i], fromNode2[i]);
            if (maxi < mini) {
                ans = i;
                mini = maxi;
            }
        }
        return ans;
    }
};