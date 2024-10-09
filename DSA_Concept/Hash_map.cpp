//  In C++, hash maps are implemented using the unordered_map container class.

// Syntax to Declare a HashMap

// unordered_map<key, value> hashMap;
//The average time complexity for search, insertion and deletion of a std::unordered_map is O(1),

// To search 

auto it = hashmap.find(nums2[i]);
    if (it == hashmap.end() && hashmap[nums2[i]]==false)


    // understand the solution 

     bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        set<int> s;
        for(int x : arr)
            mp[x]++;

        for(auto x : mp){
            if(s.find(x.second)!=s.end())
            return false;
            else
            s.insert(x.second);
        }
    return true;
    }