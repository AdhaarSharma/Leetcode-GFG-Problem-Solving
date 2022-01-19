class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto str:wordDict)
            myset.insert(str);
        return partition(s,0);
    }
private:
    unordered_map<int,bool> mem;
    unordered_set<string>myset;
    bool partition(string s, int pos){
        if(pos == s.size()) return true;
        if(mem.count(pos))  return mem[pos];
        for(int i=pos; i<s.size(); i++)
            if(myset.count(s.substr(pos, i-pos+1)) && partition(s,i+1))
               return mem[pos] = true;
        return mem[pos] = false;
    }
};