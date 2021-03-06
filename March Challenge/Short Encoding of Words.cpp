
/*
Approach
  We will first remove all those strings from words such that they are suffix for other strings in words.
  For this purpose we will reverse each string in words and then insert them in the form of Trie.
  
  The leaves of this Trie will be those nodes which have no suffix in them and we have to encode these words only.
  
  So will we will calculate the length of such strings and will add len + 1 to res.
  len +1 is added because we have to add # after each word.


*/

struct Trie{
    map<char, Trie*> m;
};

class Solution {
    
public:
    
    static bool comp(string a, string b)
    {
        return a.size() > b.size();
    }
    
    int insertNode(Trie *head, string s)
    {
        Trie *cur = head;
        bool flag = false;
        
        for(int i = s.length()-1;i>=0;i--)
        {
            char x = s[i];
            if(!cur->m[x])
            {
                flag = true;
                cur->m[x] = new Trie();
            }
            cur = cur->m[x];
        }
        return flag ? s.size() : 0;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        int res=0;
        Trie *head = new Trie();
        
        sort(words.begin(), words.end(), comp);
        
        int n = words.size();
        
        for(int i=0;i<n;i++)
        {
            int temp = insertNode(head, words[i]);
            if(temp)
            {
                res+=(temp+1);
            }
        }
        return res;      
    }
};
