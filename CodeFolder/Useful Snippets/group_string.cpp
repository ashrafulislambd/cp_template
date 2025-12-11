
vector<pair<char, int>> segments;
char prev = s[0];
int cnt = 0;
for(auto c : s) {
    if(c != prev) {
        segments.pb({prev, cnt});
        cnt = 0;
        prev = c;
    }
    cnt++;
}
segments.pb({prev, cnt});
