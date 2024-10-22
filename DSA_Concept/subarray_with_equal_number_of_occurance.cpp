    int sameOccurrence(vector<int>& arr, int x, int y) {
    unordered_map<int, int> diffMap;  // To store the frequency of each difference
    diffMap[0] = 1;  // Initialize for case where diff is 0 from the start
    int count = 0;
    int diff = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        // Update the difference based on whether the current element is x or y
        if (arr[i] == x) {
            diff++;
        } else if (arr[i] == y) {
            diff--;
        }
        
        // If the same difference has been seen before, we found a valid subarray
        if (diffMap.find(diff) != diffMap.end()) {
            count += diffMap[diff];
        }
        
        // Increment the frequency of the current difference in the map
        diffMap[diff]++;
    }
    
    return count;
    }