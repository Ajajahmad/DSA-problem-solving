struct Node
{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL) ;
    }
    
    void put(char ch )
    {
        Node *node = new Node();
        links[ch-'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie {
private:
    Node *root;
    
public:
    Trie() {
        // creating new object
        root = new Node();
        
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i] );
            }
            node = node->get(word[i]);
        }
        node->setEnd();
        
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node *node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
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