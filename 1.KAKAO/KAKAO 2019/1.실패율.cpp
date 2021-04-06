#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX 8

using namespace std;

bool select[MAX];

bool cmp(const pair<int, double> &a, const pair<int, double> &b)
{
    if (a.second != b.second)
        return a.second > b.second;
    else
        return a.first < b.first;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<int> stage(N + 2, 0);
    vector<pair<int, double>> fail;
    int users = stages.size();
    for (int i = 0; i < stages.size(); i++)
    {
        stage[stages[i]]++;
    }

    // stage -> 0~6���� ����� 1~5������ Ž��
    for (int i = 1; i < stage.size() - 1; i++)
    {
        double temp;
        if (users == 0)
        {
            temp = 0;
        }
        else
        {
            temp = (double)stage[i] / users;
        }
        fail.push_back(make_pair(i, temp));
        users = users - stage[i];
    }

    //fail ->1~5���� ����� ���ۺ��� ���������� sort
    sort(fail.begin(), fail.end(), cmp);

    //fail�� ���̸�ŭ answer�� ����
    for (int i = 0; i < fail.size(); i++)
    {
        answer.push_back(fail[i].first);
    }

    return answer;
}