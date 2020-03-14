//! [[2019-11-11] Challenge #381 [Easy] Yahtzee Upper Section Scoring](https://www.reddit.com/r/dailyprogrammer/comments/dv0231/20191111_challenge_381_easy_yahtzee_upper_section/)
//!
//! The upper section scoring in the dice game of Yahtzee deals with determining the greatest
//! sum of numbers that are the same in a list of integers.

use std::collections::HashMap;

/// Checks a list containing `u64` values, finds the sum of those that are equal, and returns the
/// greatest sum.
///
/// # Examples
/// ```
/// use yahtzee_upper_section::yahtzee_upper;
/// assert_eq!(yahtzee_upper(vec![2, 3, 5, 5, 6]), 10);
/// assert_eq!(yahtzee_upper(vec![1, 1, 1, 1, 3]), 4);
/// assert_eq!(yahtzee_upper(vec![1, 1, 1, 3, 3]), 6);
/// assert_eq!(yahtzee_upper(vec![1, 2, 3, 4, 5]), 5);
/// assert_eq!(yahtzee_upper(vec![6, 6, 6, 6, 6]), 30);
/// assert_eq!(yahtzee_upper(vec![1654, 1654, 50995, 30864, 1654, 50995, 22747,
///                             1654, 1654, 1654, 1654, 1654, 30864, 4868, 1654,
///                             4868, 1654, 30864, 4868, 30864]), 123456);
/// ```
pub fn yahtzee_upper(rolls: Vec<u64>) -> u64 {
    let mut roll_sums: HashMap<u64, u64> = HashMap::new();

    for x in rolls {
        let a_sum = roll_sums.entry(x).or_insert(0);
        *a_sum += x;
    }

    let mut max_sum: u64 = 0;

    for val in roll_sums.values_mut() {
        if *val > max_sum {
            max_sum = *val;
        }
    }

    max_sum
}
