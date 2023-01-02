class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(word[0] >= 65 && word[0] <= 90){
            bool flag = false;
            int i=1;
            while(word[i] >= 65 && word[i] <= 90) i++;
            if(i == 1){while(word[i] >= 97 && word[i] <= 122) i++;}
            if(i!=n) return false;
        } else {
            for(int i=0; i<n; i++){
                if(!(word[i] >= 97 && word[i] <= 122))
                    return false;
            }
        }
        return true;
    }
};