/*
 * @Author: LetMeFly
 * @Date: 2024-12-20 21:06:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-20 21:14:34
 */
void count(int times[], char s[], int l, int r) {
    for (int i = l; i < r; i++) {
        times[s[i] - 'a']++;
    }
}

int same26(int a[], int b[]) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int minAnagramLength(char* s) {
    int n = strlen(s);
    for (int ans = 1; ans < n; ans++) {
        if (n % ans) {
            continue;
        }
        int should[26] = {0};
        count(should, s, 0, ans);
        for (int i = ans; i < n; i += ans) {
            int now[26] = {0};
            count(now, s, i, i + ans);
            if (!same26(should, now)) {
                goto loop;
            }
        }
        return ans;
        loop:;
    }
    return n;
}