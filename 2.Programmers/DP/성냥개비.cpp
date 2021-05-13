#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<string> max(102);
    vector<string> min(102);
    max[2] = '1';
    max[3] = '7';
    for (int i = 4; i < 101; i++)
    {
        if (i % 2 == 0)
            max[i] = max[i - 2] + max[2];
        else
            max[i] = max[i - 2] + max[2];
    }
    min[2] = "1";
    min[3] = "7";
    min[4] = "4";
    min[5] = "2";
    min[6] = "6";
    min[7] = "8";

    min[8] = "10";
    min[9] = "18";
    min[10] = "22";
    min[11] = "20";
    min[12] = "28";
    min[13] = "68";
    min[14] = "88";
    min[17] = "200";
    for (int i = 15; i < 101; i++)
    {
        if (i != 17)
            min[i] = min[i - 7] + min[7];
    }
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        cin >> num;
        cout << min[num] << " " << max[num] << endl;
    }
}