class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> vec(n, 0);
        for(int i = 0; i < edges.size(); ++i) {
            int fr = edges[i].front(), to = edges[i].back();
            vec.at(to)++;
        }
        vector<int> ans;
        for(int i = 0; i < vec.size(); ++i) {
            if(!vec.at(i)) ans.push_back(i);
        }
        return ans;
    }
};