struct Node
{
    Node* links[26];
    
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    
    void put(char ch, Node* node)
    {
        links[ch-'a']=node;
    }
    
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    
};

int countDistinctSubstrings(string &s)
{
    int cnt=0;
    Node* root = new Node();
    int n=s.length();
    for(int x=0; x<n; x++)
    {
        Node* node = root;
        for(int y=x; y<n; y++)
        {
            if(!node->containsKey(s[y]))
            {
                cnt++;
                node->put(s[y], new Node());
            }
            node = node->get(s[y]);
        }
    }
    return cnt+1;
}