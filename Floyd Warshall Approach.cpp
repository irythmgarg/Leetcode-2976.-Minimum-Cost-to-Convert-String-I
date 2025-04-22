class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    { 
        // If source and target strings are not of equal length, transformation is not possible
        if (source.length() != target.length())
            return -1;

        int n = original.size();

        // Initialize a 26x26 cost matrix for all lowercase letters
        // ans[i][j] represents the minimum cost to convert character i to character j
        vector<vector<int>> ans(26, vector<int>(26, INT_MAX));

        // Populate the direct transformation costs
        for (int i = 0; i < n; i++) {
            char from = original[i];
            char to = changed[i];
            int costy = cost[i];

            // Cost to convert a character to itself is 0
            ans[from - 'a'][from - 'a'] = 0;
            ans[to - 'a'][to - 'a'] = 0;

            // Update the minimum cost for the given direct transformation
            ans[from - 'a'][to - 'a'] = min(ans[from - 'a'][to - 'a'], costy);
        }

        // Floyd-Warshall algorithm to compute all-pairs shortest transformation cost
        for (char via = 'a'; via <= 'z'; via++) {
            for (char i = 'a'; i <= 'z'; i++) {
                for (char j = 'a'; j <= 'z'; j++) {
                    int u = i - 'a';
                    int v = j - 'a';
                    int k = via - 'a';

                    // If path i -> via -> j is valid, update ans[i][j] if cheaper
                    if (ans[u][k] != INT_MAX && ans[k][v] != INT_MAX) {
                        ans[u][v] = min(ans[u][v], ans[u][k] + ans[k][v]);
                    }
                }
            }
        }

        long long mainans = 0;

        // Calculate the total cost of converting source to target
        for (int i = 0; i < source.length(); i++) {
            if (source[i] != target[i]) {
                int from = source[i] - 'a';
                int to = target[i] - 'a';

                // If a valid transformation exists, add its cost
                if (ans[from][to] < INT_MAX) {
                    mainans += ans[from][to];
                } else {
                    // Transformation not possible for this character
                    return -1;
                }
            }
        }

        return mainans; // Return the total minimum transformation cost
    }
};
