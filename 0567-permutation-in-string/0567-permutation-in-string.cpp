class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n1 = s1.size() , n2 = s2.size();

        if(n1 > n2)
            return false;
        
        vector<int> mp1(26 , 0);
        for(auto a : s1)
            mp1[a - 'a']++;

        vector<int> mp2(26 , 0);
        for(int i = 0 ; i < n1 ; i++)
            mp2[s2[i] - 'a']++;
        
        if(mp2 == mp1)
            return true;
        
        for(int i = 1 ; i <= n2 - n1 ; i++) {
            mp2[s2[i - 1] - 'a']--;
            mp2[s2[i + n1 - 1] - 'a']++;
            if(mp1 == mp2)
                return true;
        }

        return false;
    }
};