class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> sortTask;

        for (int i = 0; i < n; i++) {
            int strt = tasks[i][0];
            int process_time = tasks[i][1];
            sortTask.push_back({strt, process_time, i});
        }

        sort(sortTask.begin(), sortTask.end());  

        vector<int> result;
        long long curr_time = 0;
        int idx = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        while (idx < n || !pq.empty()) {
            if (pq.empty() && curr_time < sortTask[idx][0]) {
                curr_time = sortTask[idx][0];
            }

            while (idx < n && sortTask[idx][0] <= curr_time) {
                pq.push({sortTask[idx][1], sortTask[idx][2]});  
                idx++;
            }

            if (!pq.empty()) {
                auto curr_task = pq.top(); pq.pop();
                curr_time += curr_task.first;
                result.push_back(curr_task.second);
            }
        }

        return result;
    }
};
