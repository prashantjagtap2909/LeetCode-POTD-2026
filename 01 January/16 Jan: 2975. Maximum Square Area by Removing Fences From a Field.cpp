class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_set<int> st;
        for(int i = 0; i < hFences.size(); i++){
            for(int j = i+1; j < hFences.size(); j++){
                st.insert(hFences[j] - hFences[i]);
            }
        }
        int len = -1;
        for(int i = 0; i < vFences.size(); i++){
            for(int j = i + 1; j< vFences.size(); j++){
                if(st.count(vFences[j] - vFences[i]))
                    len = max(len, vFences[j] - vFences[i]);
            }
        }
        return len == -1 ? len : (len*1L*len)%(1000000007);
    }
};
