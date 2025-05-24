class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks) freq[task]++;
        
        priority_queue<int> pq;
        for (auto& [_, f] : freq) pq.push(f);

        int time = 0;
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> tmp;

            for (int i = 0; i < cycle && !pq.empty(); ++i) {
                tmp.push_back(pq.top() - 1);
                pq.pop();
                ++time;
            }

            for (int count : tmp) {
                if (count > 0) pq.push(count);
            }

            if (!pq.empty()) time += cycle - tmp.size();
        }

        return time;
    }
};
