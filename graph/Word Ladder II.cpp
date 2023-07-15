class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        vector<vector<string>> ans;

        q.push({beginWord});
        bool found = false;
        while (!q.empty() && !found) 
        {
            int t = q.size();
            for (int i = 0; i < t; i++) 
            {
                vector<string> v = q.front();
                q.pop();
                string str = v.back();
                
                if (str == endWord) 
                {
                    ans.push_back(v);
                    found = true;
                }

                s.erase(str);

                for (int j = 0; j < str.length(); j++) 
                {
                    char c = str[j];
                    for (char ch = 'a'; ch <= 'z'; ch++) 
                    {
                        str[j] = ch;
                        if (s.count(str)) 
                        {
                            vector<string> newPath = v;
                            newPath.push_back(str);
                            q.push(newPath);
                        }
                    }
                    str[j] = c;
                }
            }

        }

        return ans;
    }
};
