bool checkDuplicatesWithinK(vector<int>& arr, int k) {
    unordered_map<int, int> mapp;

    // Initial window setup for the first 'k' elements
    for (int i = 0; i < arr.size(); i++) {
        if (i > k) {
            // Remove the element that is sliding out of the window
            mapp[arr[i - k - 1]]--;
            if (mapp[arr[i - k - 1]] == 0) {
                mapp.erase(arr[i - k - 1]);
            }
        }
        
        // Check and add the current element
        if (++mapp[arr[i]] >= 2) {
            return true;
        }
    }

    return false;
}