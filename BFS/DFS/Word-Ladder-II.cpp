class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> results;
        vector<string> path = {beginWord};
        unordered_map<string, vector<string>> parents; // for backtracking
        unordered_set<string> currentLevel, nextLevel;
        currentLevel.insert(beginWord);

        if (!dict.count(endWord)) return results;

        bool found = false;

        while (!currentLevel.empty() && !found) {
            for (auto& w : currentLevel) dict.erase(w);
            nextLevel.clear();

            for (auto& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < (int)word.size(); ++i) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (dict.count(temp)) {
                            parents[temp].push_back(word);
                            nextLevel.insert(temp);
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[i] = original;
                }
            }
            currentLevel = nextLevel;
        }

        if (found) {
            vector<string> tempPath;
            backtrack(results, parents, endWord, beginWord, tempPath);
        }
        return results;
    }

private:
    void backtrack(vector<vector<string>>& results,
                   unordered_map<string, vector<string>>& parents,
                   const string& word, const string& beginWord,
                   vector<string>& path) {
        path.push_back(word);
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            results.push_back(temp);
        } else {
            for (auto& parent : parents[word]) {
                backtrack(results, parents, parent, beginWord, path);
            }
        }
        path.pop_back();
    }
};
