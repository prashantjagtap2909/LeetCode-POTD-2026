class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> ans;
        int n = servers.size(), m = tasks.size();
        multiset<vector<long long>> st, free;
        for(int i=0;i<n;i++) {
            st.insert({servers[i], i});
        }
        long long i=0, time=0;
        while(i<m) {
            if(time < i) time = i;
            while(free.size()) {
                auto topv = *free.begin();
                if(topv[0]<=time) {
                    free.erase(free.begin());
                    st.insert({servers[topv[1]], topv[1]});
                }
                else break;
            }
            if(st.empty()) {
                time = (*free.begin())[0];
                continue;
            }
            auto first= *st.begin();
            st.erase(st.begin());
            ans.push_back(first[1]);
            free.insert({time + tasks[i++], first[1]});
        }
        return ans;
    }
};
