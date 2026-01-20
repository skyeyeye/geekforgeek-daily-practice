class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        //Approach - 2
        for(int i = 0; i < n; i++){
            // if(!st.empty()){
                while(!st.empty() && arr[st.top()] < arr[i]){
                    ans[st.top()] = arr[i];
                    st.pop();
                }
            //}
            st.push(i);
        }
          for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
        }
        return ans;
        }
};
