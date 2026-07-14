class Solution {
public:
    vector<int>prevSmaller(vector<int>& heights){
        int n=heights.size();
        vector<int>left(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())
               left[i]=-1;
            else
               left[i]=st.top();
            st.push(i);
        }
        return left;
    }
    vector<int>nextSmaller(vector<int>& heights){
        int n=heights.size();
        vector<int>right(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())
               right[i]=n;
            else
               right[i]=st.top();
            st.push(i);
        }
        return right;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left=prevSmaller(heights);
        vector<int>right=nextSmaller(heights);
        int ans=0;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            int area=heights[i]*width;
            ans=max(ans,area);
        }
        return ans;
    }
};