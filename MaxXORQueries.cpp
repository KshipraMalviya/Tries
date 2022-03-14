#include<bits/stdc++.h>

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

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
	   sort(arr.begin(), arr.end());
    vector<pair<int, pair<int,int>>> offlineQueries;
    int q = queries.size();
    for(int x=0; x<q; x++)  // T.C. - O(Q)
    {
        offlineQueries.push_back({queries[x][1],{queries[x][0],x}});
    }
    sort(offlineQueries.begin(), offlineQueries.end());  // T.C. - Qlog Q
    
    vector<int> ans(q,0);
    int i=0;
    int n = arr.size();
    Trie trie;
    for(int x=0; x<q; x++)   // T.C. - O(Q*32 + N*32)
    {
        int ai=offlineQueries[x].first;
        int xi=offlineQueries[x].second.first;
        int qi=offlineQueries[x].second.second;
        while(i<n && arr[i]<=ai)
        {
            trie.insert(arr[i]);
            i++;
        }
        if(i==0)
        {
            ans[qi] = -1;
        }
        else
        {
            ans[qi] = trie.getMax(xi);
        }
    }
    return ans;
}