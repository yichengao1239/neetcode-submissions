class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<string>> AnagramGroups;

        for(const auto& word: strs) {
            string label = word;
            std::sort(label.begin(), label.end());
            AnagramGroups[label].push_back(word);
        }
        vector<vector<string>> result;
        for (const auto& pair : AnagramGroups) {
            result.push_back(pair.second);
        }
        return result;

        
    }
};
