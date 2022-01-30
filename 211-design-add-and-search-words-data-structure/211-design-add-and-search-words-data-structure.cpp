class WordDictionary {
public:
    struct node{
        char c;
        int end;
        node *child[26];
    };
    
    node* getNode(char c){
        node* newNode = new node();
        newNode->c = c;
        newNode->end = 0;
        for(int i=0; i<26; i++)
            newNode->child[i] = NULL;
        return newNode;
    }
    
    node* root = getNode('/');
    
    void TrieInsert(string s){
        int i = 0;
        int index;
        node *curr = root;
        while(s[i]){
            index = s[i] - 'a';
            if(!curr->child[index])
                curr->child[index] = getNode(s[i]);
            curr = curr->child[index];
            i++;
        }
        curr->end += 1;
    }
    
    bool TrieSearch(string s, node* curr, int pos, int n){
        if(s[pos] == '.'){
            bool res = false;
            node* current = curr;
            for(int i=0; i<26; i++){
                if(pos == n-1 && curr->child[i]){
                    current = curr->child[i];
                    res |= current->end>0?true:false;
                }
                else if(curr->child[i] && TrieSearch(s, curr->child[i], pos+1, n)){
                    return true;
                }
            }
            return res;
        }
        else if(curr->child[s[pos]-'a']) {
            if(pos == n-1){
                curr = curr->child[s[pos]-'a'];
                return curr->end>0?true:false;
            }
            return TrieSearch(s, curr->child[s[pos]-'a'], pos+1, n);
        }
        return false;
    }
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieInsert(word);
    }
    
    bool search(string word) {
        return TrieSearch(word,root,0,word.size());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */