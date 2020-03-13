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
    // If one of the asserts below fails, a message is written to the terminal
    // notifying us of which assert failed, and the program is terminated.
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

    // If we hit this, none of the asserts above failed, so we've succeeded.
    cout << "Success!" << endl;

    return 0;
}

// Checks two strings to see if they could possibly match if all the letters from each string
// were placed on two separate necklaces.
bool same_necklace(const string str_1, const string str_2)
{
    int str_length = str_1.length();

    // If the two strings aren't the same length, they can't be equal.
    if (str_length != str_2.length()) return false;

    // If both strings are empty, they're equal.
    if (str_length == 0) return true;

    // Iterate through indices of first string.
    for (int it_1 = 0; it_1 < str_length; ++it_1)
    {
        // Stop iterating through indices of first string when we find a
        // character that matches the first character in the second string.
        if (str_1[it_1] == str_2[0])
        {
            int it_2;
            int current_1 = it_1;

            // Iterate through indices of second string.
            for (it_2 = 0; it_2 < str_length; ++it_2)
            {
                // If we've hit the end of the first string, we need to loop back to the start.
                if (current_1 == str_length) current_1 = 0;

                // If a character in the first string doesn't match a character in the second string,
                // these slices aren't equal, and we can break out of this loop.
                if (str_1[current_1] != str_2[it_2]) break;

                ++current_1;
            }

            // If we got through the entirety of the second string without breaking, then
            // the two strings have at least one slice that is equal, so we can return true.
            if (it_2 == str_length) return true;
        }
    }

    return false;
}
