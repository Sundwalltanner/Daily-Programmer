//! [[2020-03-09] Challenge #383 [Easy] Necklace Matching](https://www.reddit.com/r/dailyprogrammer/comments/ffxabb/20200309_challenge_383_easy_necklace_matching/)
//!
//! A necklace containing characters allows one to slide the letters around in a way that they maintain
//! a certain order, and aren't ever removed from the string and manually placed in a different location.
//! We want a function that returns true or false based on whether or not two strings can be made with the
//! same necklace of characters.

/// Checks two strings to see if they could possibly match if all the letters from each string
/// were placed on two separate necklaces.
///
/// The idea with this solution is that if we concatenate either of the two strings to itself,
/// and we also know that the two strings are of the same length, we can save ourselves the trouble
/// of dealing with manually iterating through them in order to make individual comparisons, and just
/// compare the other string to this newly concatenated string.
///
/// # Examples
/// ```
/// use necklace_matching::same_necklace;
/// assert_eq!(same_necklace("nicole", "icolen"), true);
/// assert_eq!(same_necklace("nicole", "lenico"), true);
/// assert_eq!(same_necklace("nicole", "coneli"), false);
/// assert_eq!(same_necklace("aabaaaaabaab", "aabaabaabaaa"), true);
/// assert_eq!(same_necklace("abc", "cba"), false);
/// assert_eq!(same_necklace("xxyyy", "xxxyy"), false);
/// assert_eq!(same_necklace("xyxxz", "xxyxz"), false);
/// assert_eq!(same_necklace("x", "x"), true);
/// assert_eq!(same_necklace("x", "xx"), false);
/// assert_eq!(same_necklace("x", ""), false);
/// assert_eq!(same_necklace("", ""), true);
/// ```
pub fn same_necklace(str_1: &str, str_2: &str) -> bool {
    // .join("") can be replaced with .concat() if need be.
    // There's a lot of different methods to combine two strings.
    str_1.len() == str_2.len() && [str_1, str_1].join("").contains(str_2)
}
