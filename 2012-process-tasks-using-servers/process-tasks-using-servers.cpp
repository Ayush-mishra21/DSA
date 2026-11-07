class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m);

        // Free servers: {weight, index}
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> free;

        // Busy servers: {free time, index}
        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> busy;

        for(int i = 0; i < n; i++) {
            free.push({servers[i], i});
        }

        long long time = 0;

        for(int i = 0; i < m; i++) {

            time = max(time, (long long)i);

            // Release all servers that are free
            while(!busy.empty() && busy.top().first <= time) {

                int ind = busy.top().second;
                busy.pop();

                free.push({servers[ind], ind});
            }

            // If no server is free, wait
            if(free.empty()) {

                time = busy.top().first;

                while(!busy.empty() && busy.top().first <= time) {

                    int ind = busy.top().second;
                    busy.pop();

                    free.push({servers[ind], ind});
                }
            }

            // Select minimum weight, then minimum index
            auto p = free.top();
            free.pop();

            int ind = p.second;

            ans[i] = ind;

            // Assign task and calculate server's free time
            busy.push({time + tasks[i], ind});
        }

        return ans;
    }
};