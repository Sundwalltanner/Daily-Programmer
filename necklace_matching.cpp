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

    return 0;
}

bool same_necklace(const string str_1, const string str_2)
{
    if (str_1.length() != str_2.length()) return false;

    for (int it_1 = 0; it_1 < str_1.length(); ++it_1)
    {
        for (int it_2 = 0; it_2 < str_2.length(); ++it_2)
        {
            if (str_1[it_1] == str_2[it_2])
            {
                int start = it_2;
                int current = start + 1;

                while (current != start)
                {
                    if (current >= str_2.length()) current = 0;
                    if (str_1[current] != str_2[current]) break;
                    ++current;
                }

                if (current == start) return true;
            }
        }
    }

    return false;
}