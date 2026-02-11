struct Node {
    short min, max, lazy;
    Node():min(SHRT_MAX), max(SHRT_MIN), lazy(0) {}
    Node(int x): min(x), max(x), lazy(0) {}
};

class SegmentTree {
public:
    vector<Node> segTree;
    unsigned n;

    SegmentTree(vector<int>& arr) {
        n=arr.size();
        // 1-indexed segment tree
        segTree.assign(n<<2, Node());
        buildTree(1, 0, n-1, arr);
    }

    // Pulls values from children up to the parent
    void pull(int i) {
        segTree[i].min=min(segTree[2*i].min, segTree[2*i+1].min);
        segTree[i].max=max(segTree[2*i].max, segTree[2*i+1].max);
    }

    void buildTree(int i, int l, int r, vector<int>& arr) {
        if (l==r) {
            segTree[i]=Node(arr[l]);
            return;
        }
        int m=(l+r)>>1;
        buildTree(2*i, l, m, arr);
        buildTree(2*i+1, m+1, r, arr);
        pull(i);
    }

    void apply(int i, int l, int r) {
        if (segTree[i].lazy==0) return;
        segTree[i].min+=segTree[i].lazy;
        segTree[i].max+=segTree[i].lazy;
        if (l<r) {
            segTree[2*i].lazy+=segTree[i].lazy;
            segTree[2*i+1].lazy+=segTree[i].lazy;
        }
        segTree[i].lazy=0;
    }

    void updateRange(int start, int end, int i, int l, int r, int val) {
        apply(i, l, r);
        if (l>end || r<start) return;

        if (l>=start && r<=end) {
            segTree[i].lazy+= val;
            apply(i, l, r);
            return;
        }

        int m=(l+r)>>1;
        updateRange(start, end, 2*i, l, m, val);
        updateRange(start, end, 2*i+1, m+1, r, val);
        pull(i);
    }

    int findLast0(int i, int l, int r) {
        apply(i, l, r);
        // if 0 isn't within [min, max], no 0
        if (segTree[i].min>0|| segTree[i].max<0) return -1;

        if (l==r) return l;

        int m=(l+r)>>1;
        // To find the index for the last 0, 
        // search the right child first
        int right=findLast0(2*i+1, m+1, r);
        if (right!=-1) return right;
        return findLast0(2*i, l, m);
    }
};

constexpr int N=1e5+1;
bitset<N> seen=0;
class Solution {
public:
    static int longestBalanced0(vector<int>& nums) {
        const int n=nums.size();
        int len=0;
        for(int l=0; l<n; l++){
            if (l>n-len) break;// len cannot be longer
            int diff=0;
            for(int r=l; r<n; r++){
                const int x=nums[r];
                if (!seen[x]) {diff+=(1-(x&1)*2), seen[x]=1; }
                if (diff==0)
                    len=max(len, r-l+1);
            }
            for(int i=l; i<n; i++) seen[nums[i]]=0;
        }
        return len;
    }
    static int longestBalanced(vector<int>& nums) {
        const int n=nums.size();
        if (n<=2000) return longestBalanced0(nums);

        const int M=*max_element(nums.begin(), nums.end());
        vector<int> last(M+1, n);
        vector<int> nextPos(n, n);
        for (int i=n-1; i>= 0; i--) {
            const int x=nums[i];
            nextPos[i]=last[x];
            last[x]=i;
        }

        // Compute prefix sums 
        vector<int> prefix(n);
        int sum=0;
        for (int i=0; i<n; i++) {
            const int x=nums[i];
            if (!seen[x]) {
                sum+=(x&1)?1:-1;
                seen[x]=1;
            }
            prefix[i]=sum;
        }
        // reset for the next testcase
        for(int i=0; i<n; i++) seen[nums[i]]=0;

        SegmentTree seg(prefix);
        
        int ans=seg.findLast0(1, 0, n-1)+1;

        for (int i=0; i<n-1; i++) {
            int r=nextPos[i]-1;
            // Only update if the range is valid
            if (i+1<=r) {
                int val=(nums[i] & 1)?-1:1;
                seg.updateRange(i+1, r, 1, 0, n-1, val);
            }

            // Only search if a better answer is possible
            if (i+ans+1<n) {// this check saves half of time
                int right=seg.findLast0(1, 0, n-1);
                if (right!=-1) 
                    ans=max(ans, right-i);
            }
        }
        return ans;
    }
};
