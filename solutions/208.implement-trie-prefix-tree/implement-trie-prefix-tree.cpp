class TrieNode {
public:
    char var;
    bool isWord;
    TrieNode* children[26];
    // Initialize your data structure here
    TrieNode(){
        var = 0;
        isWord = false;
        memset(children, 0x0, sizeof(TrieNode*)*26);
    }
    
    TrieNode(char c){
        var = c;
        isWord = false;
        memset(children, 0x0, sizeof(TrieNode*)*26);
    }
    
};

class Trie {
    
private:
    TrieNode* root; 
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *pNode = root;
        if(word.length() <= 0){
            return;
        }
        for(int i = 0; i < word.length(); i++){
            char c = word[i];
            if(pNode->children[c-'a'] == 0){
                TrieNode *pNew = new TrieNode(c);
                pNode->children[c-'a'] = pNew;
            }
            pNode = pNode->children[c-'a'];
        }
        pNode->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *pNode = root;
        if(word.length() <= 0)
            return true;
        for(int i = 0; i < word.length(); i++){
            char c = word[i];
            pNode = pNode->children[c-'a'];
            if(pNode == NULL)
                return false;
        }
        return pNode->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *pNode = root;
        if(prefix.length() <= 0)
            return true;
        for(int i = 0; i < prefix.length(); i++){
            char c = prefix[i];
            pNode = pNode->children[c-'a'];
            if(pNode == NULL)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */