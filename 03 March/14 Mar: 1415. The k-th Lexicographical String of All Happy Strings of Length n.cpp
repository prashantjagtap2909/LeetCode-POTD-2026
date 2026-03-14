class Solution {

private:
    void solve(int&n, char prev, vector<string>&happy,string ds){
        if(ds.size()==n){
            happy.push_back(ds);
            return;
        }
        for(char c='a';c<='c';++c){
            if(c==prev){continue;}
            ds.push_back(c);
            solve(n,c,happy,ds);
            ds.pop_back();
        }
    }

public:
    string getHappyString(int n, int k) {
        vector<string>happy;
        solve(n,'z',happy,"");
        return happy.size()>=k?happy[k-1]:"";
    }
};
