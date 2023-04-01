class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> v1(26 , 0);
        for(auto a : p)
            v1[a - 'a']++;
        
        int n1 = p.size() , n2 = s.size();
        vector<int> ans;

        if(n1 > n2)
            return ans;
        
        vector<int> v2(26 , 0);
        for(int i = 0 ; i < n1 ; i++)
            v2[s[i] - 'a']++;
        
        if(v2 == v1)
            ans.push_back(0);
        
        for(int i = 1 ; i <= n2 - n1 ; i++) {
            v2[s[i - 1] - 'a']--;
            v2[s[i + n1 - 1] - 'a']++;
            if(v2 == v1)
                ans.push_back(i);
        }

        return ans;
    }
};