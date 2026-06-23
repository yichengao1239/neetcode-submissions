class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //vector<int> sorted = std::sort(nums.begin(). nums.end());
        std::unordered_map <int, int> item_occurence;
        // int current = nums[0];
        // int occurence = 0;
        // int prev = nums[0];
        // for (int i = 0 ; i < nums.size(); i++) {
        //     if (nums[i] == current) {
        //         prev = nums[i];
        //         current = nums[i];
        //         occurence++;
        //     }
        //     if (current != nums[i]) {
        //         item_occurence[occurence] = prev;
        //         occurence = 0;
        //         prev = nums[i];
        //     }
        // }
        for (auto num : nums) {
            item_occurence[num]++;
        }
        // A Min-Heap storing pairs of {frequency, item}
        // "greater" tells C++ to put the smallest frequency at the top
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for (auto& [item, count] : item_occurence) {
            min_heap.push({count, item}); // Push the current item into the club
            
            if (min_heap.size() > k) {
                min_heap.pop(); // Kick out the lowest frequency
            }
        }

        // Extract the survivors into the result vector
        vector<int> result;
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second); // Grab the item
            min_heap.pop();
        }

        return result;
    }     
        
    
};
