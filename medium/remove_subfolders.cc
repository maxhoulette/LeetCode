#include <iostream>
using namespace std;

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        vector<string>::iterator it_i = folder.begin();
        vector<string>::iterator it_j;

        bool erase_i;
        bool erase_j;

        for (int i = 0; i < folder.size() or it_i < folder.end(); i++)
        {
            erase_i = false;
            it_j = it_i;
            for (int j = i; j < folder.size() or it_j < folder.end(); j++)
            {
                erase_j = false;
                if (it_i != it_j)
                {
                    int li = it_i->size();
                    int lj = it_j->size();

                    int min_value = min(li, lj);
                    if (it_i->substr(0, min_value) == it_j->substr(0, min_value))
                    {
                        if (li < lj && (*it_j)[li] == '/')
                        {
                            folder.erase(it_j);
                            erase_j = true;
                        }
                        else if (lj < li && (*it_i)[lj] == '/')
                        {
                            folder.erase(it_i);
                            erase_i = true;
                        }
                    }
                }

                if (!erase_j)
                {
                    it_j++;
                }
            }
            if (!erase_i)
            {
                it_i++;
            }
        }

        return folder;
    }
};