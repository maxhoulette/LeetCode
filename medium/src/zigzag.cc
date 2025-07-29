#include <iostream>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        string::iterator iteString = s.begin();

        vector<string> rows;
        for (int i = 0; i < numRows; i++)
            rows.push_back("");
        vector<string>::iterator iteRows = rows.begin();

        bool zigzag = false;

        string res = "";

        while (iteString < s.end())
        {
            if (iteRows < rows.end() && !zigzag)
            {
                *iteRows += *iteString;
                iteRows++;
                iteString++;
            }
            else if (iteRows == rows.end() && !zigzag)
            {
                iteRows = rows.end() - 2;
                zigzag = true;

                *iteRows += *iteString;
                iteRows--;
                iteString++;
            }
            else if (iteRows > rows.begin() && zigzag)
            {
                *iteRows += *iteString;
                iteRows--;
                iteString++;
            }
            else if (iteRows <= rows.begin() && zigzag)
            {
                if (iteRows < rows.begin())
                    iteRows = rows.begin() + 1;
                    
                *iteRows += *iteString;
                iteRows++;
                iteString++;
                zigzag = false;
            }
        }

        for (iteRows = rows.begin(); iteRows < rows.end(); iteRows++)
            res += *iteRows;

        return res;
    }
};