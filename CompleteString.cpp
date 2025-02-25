struct Node
{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    
    void put(char ch, Node* node)
    {
        links[ch-'a'] = node;
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
    Trie()
    {
        root=new Node();
    }
    
    void insert(string word)
    {
        Node* node = root;
        for(int x=0; x<word.length(); x++)
        {
            if(!node->containsKey(word[x]))
            {
                node->put(word[x],new Node());
            }
            node = node->get(word[x]);
        }
        node->setEnd();
    }
               
    bool checkIfPrefixExists(string word)
    {
        bool flag = true;
        Node* node = root;
        for(int x=0; x<word.length(); x++)
        {
            if(!node->containsKey(word[x]))
            {
                return false;
            }
            node = node->get(word[x]);
            flag = flag & node->isEnd(); 
        }
        return flag; 
    }
};

string completeString(int n, vector<string> &a)
{
    Trie trie;
    for(auto &it: a)
    {
        trie.insert(it);
    }
    string longest = "";
    for(auto &it: a)
    {
        if(trie.checkIfPrefixExists(it))
        {
            if(it.length()>longest.length())
            {
                longest = it;
            }
            else if(it.length() == longest.length() && it<longest)
            {
                longest = it;
            }
        }
    }
    
    if(longest=="") return "None";
    return longest;
}