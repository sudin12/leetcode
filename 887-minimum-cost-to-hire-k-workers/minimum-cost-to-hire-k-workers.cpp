class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int >> ratios;
        for(int i = 0; i < n; ++i){
            ratios.push_back({static_cast<double>(wage[i]) / quality[i], quality[i]});
        }

        sort(ratios.begin(), ratios.end());

        double min_cost = numeric_limits<double>::infinity();
        double total_quality = 0;
        priority_queue<int> max_heap;

        for(auto& ratio : ratios){
            total_quality += ratio.second;
            max_heap.push(ratio.second);
            if (max_heap.size() > k){
                total_quality -= max_heap.top();
                max_heap.pop();
            }

            if (max_heap.size() == k){
                min_cost = min(min_cost, total_quality * ratio.first);            
            }
        }

        return min_cost;
    }
};