class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i=0; i<k; i++) {
            int e=nums[i];
            while(!dq.empty() && nums[dq.back()]<e) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        vector<int> a;
        a.push_back(nums[dq.front()]);

        for(int i=k; i<nums.size(); i++) {
            if(!dq.empty() && dq.front()<=i-k) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            a.push_back(nums[dq.front()]);
        }
        
        return a;
    }
};
   
