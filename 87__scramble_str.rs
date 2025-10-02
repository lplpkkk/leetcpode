impl Solution {
    pub fn is_scramble(s1: String, s2: String) -> bool {
        fn char_idx(c: u8) -> usize {
            // converts character byte to the array index (in range 0..=26)
            (c - b'a') as usize
        }

        fn is_good_slice(s1: &str, s2: &str) -> bool {
            // check if strings are same or are reverse of each other
            if s1.as_bytes().iter().eq(s2.as_bytes().iter())
                || s1.as_bytes().iter().eq(s2.as_bytes().iter().rev())
            {
                return true;
            }

            // gets the index where the subslice have same char count
            let mut left_count = [0; 26];
            let mut right_count = [0; 26];
            let idx = s2
                .as_bytes()
                .iter()
                .zip(s1.as_bytes().iter())
                .position(|(x, y)| {
                    left_count[char_idx(*x)] += 1;
                    right_count[char_idx(*y)] += 1;
                    left_count == right_count
                });

            let left_check = if let Some(idx) = idx {
                // if such an index exists, check if the slice is not the same slice as the input
                if idx != s1.len() - 1 {
                    // if it is a new subslice, return the status of these subslices
                    is_good_slice(&s1[..=idx], &s2[..=idx])
                        && is_good_slice(&s1[idx + 1..], &s2[idx + 1..])
                } else {
                    // not a new subslice, this means it would have called
                    // the function with same subslice and hence be in an
                    // infinite loop, so exit with false as solution doesn't exist
                    false
                }
            } else {
                // if such an index doesn't exists, it means the char
                // count of both is not the same, so exit with false
                false
            };
            if left_check {
                return true;
            }

            // if we get a false, we do the same process but with one of the strings reversed
            let mut left_count = [0; 26];
            let mut right_count = [0; 26];
            let idx = s2
                .as_bytes()
                .iter()
                .zip(s1.as_bytes().iter().rev())
                .position(|(x, y)| {
                    left_count[char_idx(*x)] += 1;
                    right_count[char_idx(*y)] += 1;
                    left_count == right_count
                });
            let right_check = if let Some(idx) = idx {
                let n = s2.len() - idx - 1;
                if idx != s1.len() - 1 {
                    is_good_slice(&s1[n..], &s2[..=idx]) && is_good_slice(&s1[..n], &s2[idx + 1..])
                } else {
                    false
                }
            } else {
                false
            };
            right_check
        }

        is_good_slice(&s1, &s2)
    }
}
