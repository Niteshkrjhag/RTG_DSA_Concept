class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        
        for (int ast : asteroids) {
            bool destroyed = false;   // when current ast is destroyed then updated to true; if previous ast is destroyed then no change
            
            // Handle potential collision
            while (!stk.empty() && ast < 0 && stk.top() > 0) {
                // Collision case: positive stack top meets negative asteroid
                if (stk.top() < -ast) {
                    stk.pop(); // destroy the smaller positive asteroid
                } else if (stk.top() == -ast) {
                    stk.pop(); // destroy both if equal in size
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // current negative asteroid is destroyed
                    break;
                }
            }
            // If no destruction happens, add the current asteroid to the stack
            if (!destroyed) {
                stk.push(ast);
            }
        }
        
        // Collect result from stack
        vector<int> result(stk.size());
        for (int i = stk.size() - 1; i >= 0; i--) {
            result[i] = stk.top();
            stk.pop();
        }
        
        return result;
    }
};
