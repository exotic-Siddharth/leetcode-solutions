class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indegree;

        // Build graph
        for (int i = 0; i < recipes.size(); i++) {

            for (auto it : ingredients[i]) {
                adj[it].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        queue<string> q;

        for (int i = 0; i < supplies.size(); i++) {
            q.push(supplies[i]);
        }

        vector<string> ans;

        while (!q.empty()) {

            string node = q.front();
            q.pop();

            for (auto it : adj[node]) {

                indegree[it]--;

                if (indegree[it] == 0) {
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }

        return ans;
    }
};