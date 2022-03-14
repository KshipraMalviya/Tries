struct Node
{
    Node* links[2];
    
    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
    }
    
    Node* get(int bit)
    {
        return links[bit];
    }
    
    void put(int bit, Node* node)
    {
        links[bit] = node;
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
    
    void insert(int nums)
    {
        Node* node = root;
        for(int x=31; x>=0; x--)
        {
            int bit = (nums >> x) & 1;
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    
    int getMax(int num)
    {
        Node* node = root;
        int maxNum = 0;
        for(int x=31; x>=0; x--)
        {
            int bit = (num >> x) & 1; // finding bit at x of num
            if(node->containsKey(1-bit))
            {
                maxNum = maxNum | (1 << x); // turning on bit at position x
                node = node->get(1-bit);
            }
            else // we will not turn bit on (turn on bit means set it to 1)
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie trie;
    for(auto &it: arr1)
    {
        trie.insert(it);
    }
    int maxi=0;
    for(auto &it: arr2)
    {
        maxi=max(maxi, trie.getMax(it));
    }
    return maxi;
}