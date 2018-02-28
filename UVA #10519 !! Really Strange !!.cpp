#include<bits/stdc++.h>
using namespace std;

int n[250], res[250];
void Preprocess(string s) {
    memset(n, 0, sizeof n);
    memset(res, 0, sizeof res);
    for (int i = s.length()-1; i >= 0; i--) n[s.length()-1-i] = (s[i] - '0');
}

void AddNumber(int num) {
    int i = 0;
    res[i] += num;
    while (res[i] > 9) {
        res[i+1] += res[i]/10;
        res[i++] %= 10;
    }
}

void SubtractNumber(int num) {
    int i = 0;
    n[i] -= num;
    while (n[i] < 0) {
        n[i++] += 10;
        n[i]--;
    }
}

void Add() {
    for (int i = 0; i < 250; i++) {
        res[i] = res[i] + n[i];
        if (res[i] > 9) res[i+1] += res[i]/10, res[i] = res[i]%10;
    }
}

void Multiply() {
    for (int i = 0; i < 250; i++) {
        for (int j = 0; j < 250; j++) {
            res[i+j] += n[i] * n[j];
            if (res[i+j] > 9) res[i+j+1] += res[i+j]/10, res[i+j] = res[i+j]%10;
        }
    }
}

void PrintArray() {
    int idx = 249;
    while (!res[idx]) idx--;
    while (idx != -1) printf("%d", res[idx--]);
    printf("\n");
}

int main() {
    string s;
    while (cin >> s) {
        if (s == "0") {
            printf("1\n");
            continue;
        }
        Preprocess(s);
        SubtractNumber(1);
        Multiply();
        Add();
        AddNumber(2);
        PrintArray();
    }
}
