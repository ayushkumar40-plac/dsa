class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        int maxFreq = 0;

        // Counting the value of the frequencies
        for(char ch : s) {
            freq[ch]++;
            maxFreq = max(maxFreq, freq[ch]);
        }

        // creating bucket to store the values of the frequency
        vector<vector<char>> buckets(maxFreq + 1);
        for(auto &p : freq) {
            buckets[p.second].push_back(p.first);
        }
        string result;
        for(int i = maxFreq; i > 0; i--) {
            for(char c : buckets[i]) {
                result.append(i, c); 
            }
        }

        return result;
    }
};
