/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node
{
    Node* links[26];
    bool flag=false;
    
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    
    void put(char ch, Node* node)
    {
        links[ch-'a'] = node;
    }
    
    Node* get(char ch)
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

class Trie 
{
private: Node* root;

public:

    /** Initialize your data structure here. */
    Trie() 
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)  // T.C. - O(length of word)
    {
        Node* node = root;
        for(int x=0; x<word.length(); x++)  
        {
            if(!node->containsKey(word[x]))
            {
                node->put(word[x], new Node());
            }
            //moves to the reference trie
            node = node->get(word[x]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)   // T.C. - O(length of word)
    {
        Node* node = root;
        for(int x=0; x<word.length(); x++)
        {
            if(!node->containsKey(word[x]))
            {
                return false;
            }
            node = node->get(word[x]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)   // T.C. - O(length of word)
    {
        Node* node = root;
        for(int x=0; x<prefix.length(); x++)
        {
            if(!node->containsKey(prefix[x]))
            {
                return false;
            }
            node = node->get(prefix[x]);
        }
        return true;
    }
};