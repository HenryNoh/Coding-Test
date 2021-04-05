#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string line;
    int n;

    cin >> n;
    vector<int> map(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
        scanf("%1d", &map[i]);
    dp[0] = 1;
    (map[1] == 0) ? dp[1] = 0 : dp[1] = 1;
    for (int i = 2; i < n; i++)
    {
        if (map[i] == 0)
            dp[i] = 0;
        else
            dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n - 1];

    return 0;
}