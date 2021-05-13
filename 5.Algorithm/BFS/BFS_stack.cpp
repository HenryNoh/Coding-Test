// BFS�� �ʺ� �켱 Ž���̴�.
// �ַ� �ִܰŸ�, �ִܺ���� ���� �� ����Ѵ�.
// �⺻���� ������ ���� ���� ����� �ֺ� ������ Ž���ϴ� ���̴�.

//�ʺ� �켱 Ž�� ���� ��
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> Array, vector<int> v)
{
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        v[cur] = 1;
        cout << cur << " ";
        for (int i = 0; i < Array[cur].size(); i++)
        {
            if (Array[cur][i] == 1 && !v[i])
                q.push(i);
        }
    }
}

int main()
{
    vector<vector<int>> Array = {
        {0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0}};
    vector<int> v(7, 0);
    BFS(Array, v);
    return 0;
}

//�ִ� �Ÿ� ���� ��

//�ִ� ��� ���� ��