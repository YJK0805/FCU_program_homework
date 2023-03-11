#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
    int l = 0;
    string str;
    map<string, int> dic;
    while (getline(cin, str))
    {
        int len = str.size();
        for (int i = 0; i < len; i++)
        {
            if (isalpha(str[i]))
            {
                str[i] = tolower(str[i]);
            }
            else
            {
                str[i] = ' ';
            }
        }
        int start = -1;
        int end = 0;
        for (int i = 0; i < len; i++)
        {
            if (str[i] == ' ')
            {
                l++;
                string b;
                end = i - 1;
                b = b.append(str, start + 1, (end - start - 1 + 1));
                dic.insert(make_pair(b, l));
                start = i;
            }
        }
        l++;
    }
    for (auto it = dic.begin(); it != dic.end(); ++it)
    {
        // if(it == dic.begin())
        // {
            // continue;
        // }
        cout << it->first << endl;
    }
    
}