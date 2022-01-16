/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
public:
    Trie() {}
    Trie* next[26] = {};
    bool isWord=false;
    void insert(string word) {
        Trie* node = this;
        for (auto &ch : word)
        {
            ch -= 'a';
            if(!node->next[ch]) node->next[ch] = new Trie();
            node = node->next[ch];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (auto &ch : word)
        {
            ch -= 'a';
            if(!node->next[ch]) return false;
            node = node->next[ch];
        }
        return node->isWord;
        
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto &ch : prefix)
        {
            ch -= 'a';
            if(!node->next[ch]) return false;
            node = node->next[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

