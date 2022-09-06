// without recursion
bool checkPalindrome(long long N)
{
 string s="";
    int r;
    while(N>0)
    {
        r=N%2;
        N=N/2;
        s.push_back(r);
    }
    int i=0;
    int j=s.length()-1;
    while(i<=j)
      if(s[i++]!=s[j--]) return 0;
    return 1; 
}


// using recursion
// with recursion
bool solve(vector<bool> ans, int s) {
    // base case - 1
    if(s > ans.size()-1-s) {
        return 1;
    }
    // base case - 2
    if(ans[s] != ans[ans.size()-1-s]) {
        return 0;
    }
    s++;
    // recurrence relation
    return solve(ans, s);
}

bool checkPalindrome(long long N)
{
    vector<bool> ans;
    while(N) {
        bool bit = N&1;
        ans.push_back(bit);
        N = N >> 1;
    }
    return solve(ans, 0);
}
