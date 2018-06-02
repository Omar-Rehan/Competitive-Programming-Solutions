#include <bits/stdc++.h>
using namespace std;

pair<int,string> extractInfo(string s) {
    string numToBe = "", direction = "";
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) numToBe += s[i];
        else direction += s[i];
    }
    return pair<int,string>(stoi(numToBe), direction);
}

int main() {
    int cnt = 0;
    char str[205];
    char *step;
    double x, y;
    map<char, pair<int,int>> mp;
    mp['N'] = pair<int,int>(0,1);
    mp['S'] = pair<int,int>(0,-1);
    mp['E'] = pair<int,int>(1,0);
    mp['W'] = pair<int,int>(-1,0);

    while (scanf("%s", &str) && isdigit(str[0])) {
        x = y = 0.0;
        step = strtok(str, ",.");
        while (step != NULL) {
            pair<int,string> dir = extractInfo(step);
            double d = dir.second.length() < 2 ? dir.first : sqrt(dir.first*dir.first / 2.0);
            for (int i = 0; i < dir.second.length(); i++) {
                x += mp[dir.second[i]].first  * d;
                y += mp[dir.second[i]].second * d;
            }
            step = strtok(NULL, ",.");
        }
        printf("Map #%d\n", ++cnt);
        printf("The treasure is located at (%0.3lf,%0.3lf).\n", x, y);
        printf("The distance to the treasure is %0.3lf.\n\n", hypot(x, y));
    }
}
