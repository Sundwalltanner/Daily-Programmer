// [2020-03-09] Challenge #383 [Easy] Necklace Matching
//
// Objective:
// A necklace containing characters allows one to slide the letters around in a way that they maintain
// a certain order, and aren't ever removed from the string and manually placed in a different location.
// We want a function that returns true or false based on whether or not two strings can be made with the
// same necklace of characters.
//
// Source:
// https://www.reddit.com/r/dailyprogrammer/comments/ffxabb/20200309_challenge_383_easy_necklace_matching/

#include <string>
#include <assert.h>
#include <iostream>

using namespace std;

bool same_necklace(const string, const string);

int main()
{
    assert(same_necklace("nicole", "icolen"));
    assert(same_necklace("nicole", "lenico"));
    assert(!same_necklace("nicole", "coneli"));
    assert(same_necklace("aabaaaaabaab", "aabaabaabaaa"));
    assert(!same_necklace("abc", "cba"));
    assert(!same_necklace("xxyyy", "xxxyy"));
    assert(!same_necklace("xyxxz", "xxyxz"));
    assert(same_necklace("x", "x"));
    assert(!same_necklace("x", "xx"));
    assert(!same_necklace("x", ""));
    assert(same_necklace("", ""));

    cout << "Success!" << endl;

    return 0;
}

bool same_necklace(const string str_1, const string str_2)
{
    int str_length = str_1.length();

    if (str_length != str_2.length()) return false;
    if (str_length == 0) return true;
    if (str_length == 1)
    {
        if (str_1[0] == str_2[0]) return true;
        else return false;
    }

    for (int it_1 = 0; it_1 < str_1.length(); ++it_1)
    {
        for (int it_2 = 0; it_2 < str_2.length(); ++it_2)
        {
            if (str_1[it_1] == str_2[it_2])
            {
                int start = it_2;
                int current_1 = it_1 + 1;
                int current_2 = start + 1;

                while (current_2 != start)
                {
                    if (current_1 == str_length) current_1 = 0;
                    if (current_2 == str_length) current_2 = 0;
                    if (str_1[current_1] != str_2[current_2]) break;
                    ++current_1;
                    ++current_2;
                }

                if (current_2 == start) return true;
            }
        }
    }

    return false;
}
