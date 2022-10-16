// Q127 Word Ladder

// Time: O(n*k*26)
// Space: O(n)+O(n)

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        bool present = false;
        for(auto word:wordList)
        {
            if(word == endWord) present = true;
            st.insert(word);
        }
        if(!present) return 0;
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        while(!q.empty())
        {
            depth++;
            int qSize = q.size();
            while(qSize--)
            {
                string temp = q.front();
                q.pop();
                for(int i=0; i<temp.size(); i++)
                {
                    string temp1 = temp;
                    for(char j = 'a'; j<='z'; j++)
                    {
                        temp1[i] = j;
                        if(temp1 == temp) continue;
                        if(temp1 == endWord) return depth + 1;
                        if(st.find(temp1) != st.end())
                        {
                            q.push(temp1);
                            st.erase(temp1);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
