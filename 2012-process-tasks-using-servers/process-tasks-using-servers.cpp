class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m);

        // Available servers: {weight, index}
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        // Busy servers: {finishing time, index}
        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> busy;

        // Waiting tasks: FIFO
        queue<int> qu;

        for(int i = 0; i < n; i++) {
            pq.push({servers[i], i});
        }

        long long time = 0;
        int task = 0;

        while(task < m || !qu.empty() || !busy.empty()) {

            // Insert tasks arriving at current second
            while(task < m && task <= time) {
                qu.push(task);
                task++;
            }

            // Move completed servers to available PQ
            while(!busy.empty() && busy.top().first <= time) {

                int ind = busy.top().second;
                busy.pop();

                pq.push({servers[ind], ind});
            }

            // If no server is available, jump to next completion
            if(pq.empty() && !busy.empty() && !qu.empty()) {
                time = busy.top().first;

                while(!busy.empty() && busy.top().first <= time) {

                    int ind = busy.top().second;
                    busy.pop();

                    pq.push({servers[ind], ind});
                }
            }

            // Assign waiting tasks to available servers
            while(!pq.empty() && !qu.empty()) {

                int ind = pq.top().second;
                pq.pop();

                int t = qu.front();
                qu.pop();

                ans[t] = ind;

                // Store server's finishing time
                busy.push({time + tasks[t], ind});
            }

            // Move to next second
            if(task < m || !qu.empty() || !busy.empty()) {
                time = max(time + 1, (long long)task);
            }
        }

        return ans;
    }
};