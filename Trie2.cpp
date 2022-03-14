struct Node  // 'CP' means 'count prefix' ans 'EW' means 'ends with'
{
    Node* links[26];
    int ew = 0;
    int cp = 0;
    
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
    
    void incrementCP()
    {
        cp++;
    }
    
    void incrementEW()
    {
        ew++;
    }
    
    void decrementEW()
    {
        ew--;
    }
    
    void decrementCP()
    {
        cp--;
    }
    
    int getEW()
    {
        return ew;
    }
    
    int getCP()
    {
        return cp;
    }
};

class Trie
{
    private: Node* root;

    public:

    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node* node = root;
        for(int x=0; x<word.length(); x++)
        {
            if(!node->containsKey(word[x]))
            {
                node->put(word[x],new Node());
            }
            node = node->get(word[x]);
            node->incrementCP();
        }
        node->incrementEW();
    }

    int countWordsEqualTo(string &word)
    {
        Node* node = root;
        for(int x=0; x<word.length(); x++)
        {
            if(!node->containsKey(word[x]))
            {
                return 0;
            }
            node = node->get(word[x]);
        }
        return node->getEW();
    }

    int countWordsStartingWith(string &word)
    {
        Node* node = root;
        for(int x=0; x<word.length(); x++)
        {
            if(!node->containsKey(word[x]))
            {
                return 0;
            }
            node = node->get(word[x]);
        }
        return node->getCP();
    }

    void erase(string &word)
    {
        Node* node = root;
        for(int x=0; x<word.length(); x++)
        {
            if(node->containsKey(word[x]))
            {
                node = node->get(word[x]);
                node->decrementCP();
            }
            else
            {
                return;
            }
        }
        node->decrementEW();
    }
};