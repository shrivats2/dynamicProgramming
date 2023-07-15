class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string>s;
       queue<pair<string,int>>q;

       q.push({beginWord,1});
       s.insert(wordList.begin(),wordList.end());
       s.erase(beginWord);

       while(!q.empty())
       {
           int t=q.size();

           while(t--)
           {
               auto i=q.front();
               q.pop();
               int cnt=i.second;
               string str=i.first;

               if(str==endWord) return cnt;

               for(int j=0;j<str.length();j++)
               {    char c=str[j];
                   for(char ch='a';ch<='z';ch++)
                   {
                       str[j]=ch;
                       if(s.find(str)!=s.end())
                       {
                           s.erase(str);
                           q.push({str,cnt+1});
                       }
                   }
                   str[j]=c;
               }
           }
       }

       return 0; 
    }
};