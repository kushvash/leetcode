class Solution {
public: 
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> tree(n);
        for (auto &e : hierarchy) {
            int u = e[0] - 1, v = e[1] - 1;   // 1-based -> 0-based
            tree[u].push_back(v);
        }

        const long long NEG = -(1LL << 60);

        auto mergeDP = [&](const vector<long long>& A, const vector<long long>& B) {
            vector<long long> C(budget + 1, NEG);
            for (int i = 0; i <= budget; ++i) {
                if (A[i] <= NEG / 2) continue;
                for (int j = 0; i + j <= budget; ++j) {
                    if (B[j] <= NEG / 2) continue;
                    C[i + j] = max(C[i + j], A[i] + B[j]);
                }
            }
            for (int b = 1; b <= budget; ++b) C[b] = max(C[b], C[b - 1]); // "at most" budget
            return C;
        };

        // Postorder traversal (children -> parent)
        vector<int> order;
        order.reserve(n);
        stack<int> st;
        st.push(0);
        while (!st.empty()) {
            int u = st.top(); st.pop();
            order.push_back(u);
            for (int v : tree[u]) st.push(v);
        }
        reverse(order.begin(), order.end());

        vector<vector<long long>> dp0(n, vector<long long>(budget + 1, 0)); // parent not bought
        vector<vector<long long>> dp1(n, vector<long long>(budget + 1, 0)); // parent bought (u discounted)

        for (int u : order) {
            vector<long long> noDiscount(budget + 1, 0);   // u NOT bought -> children not discounted
            vector<long long> withDiscount(budget + 1, 0); // u bought -> children discounted

            for (int v : tree[u]) {
                noDiscount   = mergeDP(noDiscount, dp0[v]);
                withDiscount = mergeDP(withDiscount, dp1[v]);
            }

            vector<long long> newDp0 = noDiscount;
            vector<long long> newDp1 = noDiscount;

            // Buy u at full cost (parent didn't buy u)
            int fullCost = present[u];
            long long fullProfit = 1LL * future[u] - fullCost;
            for (int b = fullCost; b <= budget; ++b) {
                newDp0[b] = max(newDp0[b], withDiscount[b - fullCost] + fullProfit);
            }

            // Buy u at half cost (parent bought u)
            int halfCost = present[u] / 2;
            long long halfProfit = 1LL * future[u] - halfCost;
            for (int b = halfCost; b <= budget; ++b) {
                newDp1[b] = max(newDp1[b], withDiscount[b - halfCost] + halfProfit);
            }

            for (int b = 1; b <= budget; ++b) {
                newDp0[b] = max(newDp0[b], newDp0[b - 1]);
                newDp1[b] = max(newDp1[b], newDp1[b - 1]);
            }

            dp0[u] = std::move(newDp0);
            dp1[u] = std::move(newDp1);
        }

        return (int)*max_element(dp0[0].begin(), dp0[0].end());
    }
};