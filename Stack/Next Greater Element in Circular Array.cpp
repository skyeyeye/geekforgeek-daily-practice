class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        //Approach - 2
      // // First pass (standard NGE) - Next Greater Element
        for(int i = 0; i < n; i++){
            // if(!st.empty()){
                while(!st.empty() && arr[st.top()] < arr[i]){
                    ans[st.top()] = arr[i];
                    st.pop();
                }
            //}
            st.push(i);
        }
      // 2nd Pass
          for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
        }
        return ans;
        }
};
//Approach - 1
class Solution {
public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st; // stores indices
        
        // Process array twice to handle circular nature
        for(int i = 0; i < 2 * n; i++) {
            int idx = i % n; // Wrap around index
            
            while(!st.empty() && arr[st.top()] < arr[idx]) {
                ans[st.top()] = arr[idx];
                st.pop();
            }
            
            // Only push indices from the first pass
            if(i < n) {
                st.push(idx);
            }
        }
        
        return ans;
    }
};
