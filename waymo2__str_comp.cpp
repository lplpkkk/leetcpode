string compress(string s) {
    string ans;

    int i = 0;

    while (i < s.size()) {
        int j = i;

        while (j < s.size() && s[j] == s[i]) {
            j++;
        }

        int count = j - i;

        ans += to_string(count);
        ans += s[i];

        i = j;
    }

    return ans;
}
