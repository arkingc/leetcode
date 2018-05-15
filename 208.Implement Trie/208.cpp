class TrieNode{
public:
    TrieNode(){ 
        memset(next,0,sizeof(next));
        word = false;
    }
    
    bool containChar(char c){return next[c - 'a'] == NULL ? false : true;}
    
    void putNext(char c,TrieNode *nd){next[c - 'a'] = nd;}
    
    TrieNode* getNext(char c) {return next[c - 'a'];}
    
    bool isWord() {return word;}
    
    void setWord() {word = true;} 
private:
    bool word;//从根节点到当前节点的所有字符组成的单词是否包含在字典中
    TrieNode* next[26];
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for(char c : word){
            if(curr->containChar(c))    curr = curr->getNext(c);
            else{
                TrieNode *newNode = new TrieNode();
                curr->putNext(c,newNode);
                curr = newNode;
            }
        }
        curr->setWord();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        int len = 0;
        for(char c : word){
            if(!curr->containChar(c))   break;
            else    curr = curr->getNext(c);
            len++;
        }
        if(len != word.size())  return false;
        return curr->isWord();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        int len = 0;
        for(char c : prefix){
            if(!curr->containChar(c))   break;
            else    curr = curr->getNext(c);
            len++;
        }
        if(len != prefix.size())  return false;
        return true;
    }
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */