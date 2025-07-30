#include <iostream>
using namespace std;

class Solution
{
public:
    static vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int spaces = 0;
        int words_number = 0;

        int spaces_per_word = 0;
        int remainder = 0;
        int added_spaces = 0;

        bool last_line = false;

        vector<int> indexes;
        vector<string> justified;
        justified.push_back("");

        vector<string>::iterator iteWords = words.begin();
        for (int k = 0; iteWords < words.end(); k++)
        {

            if (justified.back().length() + iteWords->length() <= maxWidth)
            {
                justified.back() += *iteWords + " ";
                indexes.push_back(justified.back().length() - 2);
                words_number += 1;

                if (iteWords - words.end() + 1 == 0)
                    last_line = true;

                iteWords++;
            }
            else
            {
                justified.back().erase(justified.back().length() - 1);
                spaces = maxWidth - justified.back().length();

                if (indexes.size() == 1)
                    justified.back().insert(indexes.back() + 1, spaces, ' ');

                else
                {
                    indexes.pop_back();

                    remainder = words_number > 1 ? spaces % (words_number - 1) : spaces;
                    spaces_per_word = words_number > 1 ? (spaces - remainder) / (words_number - 1) : 0;
                    
                    for (int i = 0; i < indexes.size() && (spaces != 0); i++)
                    {
                        if (spaces_per_word != 0)
                        {
                            justified.back().insert(indexes[i] + 1 + added_spaces, spaces_per_word, ' ');
                            spaces -= spaces_per_word;
                            added_spaces += spaces_per_word;
                        }

                        if (remainder != 0)
                        {
                            justified.back().insert(indexes[i] + 1 + added_spaces, 1, ' ');
                            spaces -= 1;
                            remainder -= 1;
                            added_spaces += 1;
                        }
                    }
                }

                justified.push_back("");
                words_number = 0;
                added_spaces = 0;
                indexes.clear();
            }

            if (last_line)
            {
                justified.back().erase(justified.back().length() - 1);
                spaces = maxWidth - justified.back().length();

                justified.back().insert(indexes.back() + 1, spaces, ' ');
            }
        }

        return justified;
    }
};