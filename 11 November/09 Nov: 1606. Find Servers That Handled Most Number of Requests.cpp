#define pi pair<int,int>
class Solution {
public:
    static const int N = 1e5;
    int seg_tree[4*N+50];
    void insert(int node,int l,int r,int idx,int val){
        if(l==r){
            seg_tree[node] = val;
            return;
        }
        int mid = (l+r)/2;
        if(idx<=mid){
            insert(node*2,l,mid,idx,val);
        }else{
            insert(node*2+1,mid+1,r,idx,val);
        }
        seg_tree[node] = min(seg_tree[node*2],seg_tree[node*2+1]);
    }
    int query(int node,int l,int r,int ql,int qr){
        if(l>r) return INT_MAX;
        if(r<ql || l>qr) return INT_MAX;
        if(l>=ql && r<=qr){
            return seg_tree[node];
        }
        int mid = (l+r)/2;
        return min(query(node*2,l,mid,ql,qr),query(node*2+1,mid+1,r,ql,qr));

    }
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> cnt(k,0);
        int time = 0;
        for(int i = 0;i<k;i++){
            insert(1,0,k-1,i,i);
        }
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i = 0;i<n;i++){
            int& t = arrival[i];
            int& l = load[i];
            while(pq.size() && pq.top().first<=t){
                auto x = pq.top();pq.pop();
                insert(1,0,k-1,x.second,x.second);
            }
            int idx = i%k;
            int first_half = query(1,0,k-1,idx,k-1);
            int second_half = query(1,0,k-1,0,idx);
            if(first_half!=INT_MAX){
                cnt[first_half]++;
                insert(1,0,k-1,first_half,INT_MAX);
                pq.push({t+l,first_half});
            }else if(second_half!=INT_MAX){
                cnt[second_half]++;
                insert(1,0,k-1,second_half,INT_MAX);
                pq.push({t+l,second_half});
            }

        }
        vector<int> ans;
        int mx = 0;
        for(int i = 0;i<k;i++){
            mx = max(mx,cnt[i]);
        }
        for(int i = 0;i<k;i++){
            if(cnt[i]==mx){
                ans.push_back(i);
            }
        }
        return ans;




    }
};
