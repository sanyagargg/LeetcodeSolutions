class Solution {
    public:
        bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            deque<int> dq(workers.end() - k, workers.end());  // strongest k workers
            int n = tasks.size();
    
            for (int i = k - 1; i >= 0; --i) {  // assign hardest of k tasks
                if (dq.back() >= tasks[i]) {
                    dq.pop_back();  // assign directly
                } else {
                    if (pills == 0 || dq.front() + strength < tasks[i]) return false;
                    dq.pop_front();  // use pill on weakest eligible
                    pills--;
                }
            }
            return true;
        }
    
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());
    
            int low = 0, high = min((int)tasks.size(), (int)workers.size()), answer = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (canAssign(mid, tasks, workers, pills, strength)) {
                    answer = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return answer;
        }
    };
    
    
    //time : O(n log n + m log m + log(min(n, m)) * k)
    //This is slightly faster in practice than the multiset version due to simpler operations with deque.
    //space : O(k) for deque