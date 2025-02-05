class node {
public:
    node(char v) {
        val = v;
        is_term = false;
        for (int i = 0; i < 26; i++) { child[i] = NULL; }
    }
    char val;
    node* child[26];
    bool is_term;
};

class Trie {
public:
    Trie() {
        top = new node(0);
    }
    
    void insert(string word) {
        node *cur = top;
        node **child;
        for (int i = 0; i < word.length(); i++) {
            child = &(cur->child[word[i]-'a']);
            if (*child == NULL) {
                *child = new node(word[i]-'a');
            }
            cur = *child;
        }
        cur->is_term = true;
    }
    
    bool search(string word) {
        node *cur = top;
        node *child;
        for (int i = 0; i < word.length(); i++) {
            child = cur->child[ word[i]-'a'];
            if (child == NULL) {
                return false;
            }
            cur = child;
        }
        if (!cur->is_term) { return false; }
        return true;
    }
    
    bool startsWith(string prefix) {
        node *cur = top;
        node *child;
        for (int i = 0; i < prefix.length(); i++) {
            child = cur->child[ prefix[i]-'a'];
            if (child == NULL) {
                return false;
            }
            cur = child;
        }
        return true;
    }
private:
    node* top;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
