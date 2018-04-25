#include <bits/stdc++.h>
using namespace std;

int n, sol[25], arr[25], mem[25][25];
int LIS(int idx, int prev){
    if (idx == n+1) return 0;
    if (mem[idx][prev] != -1) return mem[idx][prev];
    int choice1 = LIS(idx+1,prev); //Leave
    int choice2 = 0;
    if (sol[arr[prev]] < sol[arr[idx]]) choice2 = LIS(idx+1,idx)+1; //Pick
    return mem[idx][prev] = max(choice1,choice2);
}

int main(){
    string s;
    arr[0] = sol[0] = 0;
    while (getline(cin,s)){
        istringstream iss(s);
        int x, k = 1;
        while (iss >> x){
            arr[x] = k; //Answer of student
            k++;
        }
        if (k == 2){
            n = x;
            for (int i = 1; i <= n; i++) cin >> sol[i]; //Solution
            cin.ignore();
        } else {
            for (int i = 0; i <= 24; i++){
                for (int j = 0; j <= 24; j++){
                mem[i][j] = -1;  //Clearing memoization table
                }
            }
            cout << LIS(1,0) << endl;
        }
    }
    return 0;
}
