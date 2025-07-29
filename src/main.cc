#include <iostream>
#include "valid_parentheses.cc"
using namespace std;

int main()
{
    string s = "[({(())}[()])]";

    bool res = Solution::isValid(s);

    cout << res << endl;

    return 0;
}