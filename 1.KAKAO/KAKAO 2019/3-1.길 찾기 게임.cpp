#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    Node *left;
    int N;
    Node *right;
};

Node *header;

void insert_leftNode(Node *prevNode, vector<pair<int, pair<int, int>>> info, int x_l, int x_r, int y);
void insert_rightNode(Node *prevNode, vector<pair<int, pair<int, int>>> info, int x_l, int x_r, int y);

bool compare(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
{
    if (a.second.second == b.second.second)
        return a.second.first < b.second.first;
    return a.second.second > b.second.second;
}

vector<int> pre;
vector<int> post;

//왼쪽 노드 삽입
void insert_leftNode(Node *prevNode, vector<pair<int, pair<int, int>>> info, int x_l, int x_r, int y_max)
{
    //탈출 조건
    // 빈 노드 생성
    Node *curNode = (struct Node *)malloc(sizeof(struct Node));

    int x, y, N;
    //왼쪽 자식찾기
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i].second.second < y_max)
        {
            if (info[i].second.first >= x_l && info[i].second.first <= x_r)
            {
                x = info[i].second.first;
                y = info[i].second.second;
                N = info[i].first;
                curNode->left = NULL;
                curNode->N = N;
                curNode->right = NULL;
                prevNode->left = curNode;
                post.push_back(N);
                insert_leftNode(curNode, info, x_l, x, y);
                insert_rightNode(curNode, info, x, x_r, y);
                pre.push_back(N);
                return;
            }
        }
    }
    prevNode->left = NULL;
    return;
}
//오른쪽 노드 삽입
void insert_rightNode(Node *prevNode, vector<pair<int, pair<int, int>>> info, int x_l, int x_r, int y_max)
{
    //탈출 조건
    Node *curNode = (struct Node *)malloc(sizeof(struct Node));
    int x, y, N;
    //왼쪽 자식찾기
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i].second.second < y_max)
        {
            if (info[i].second.first >= x_l && info[i].second.first <= x_r)
            {
                x = info[i].second.first;
                y = info[i].second.second;
                N = info[i].first;
                curNode->left = NULL;
                curNode->N = N;
                curNode->right = NULL;
                prevNode->right = curNode;
                post.push_back(N);
                insert_leftNode(curNode, info, x_l, x, y);
                insert_rightNode(curNode, info, x, x_r, y);
                pre.push_back(N);
                return;
            }
        }
    }
    prevNode->right = NULL;
    return;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;
    vector<pair<int, pair<int, int>>> info;
    int x_size = 0;
    int y_size = 0;
    int header_x = 0;
    int header_y = 0;
    int header_N = 0;

    for (int i = 0; i < nodeinfo.size(); i++)
    {
        info.push_back(make_pair(i + 1, make_pair(nodeinfo[i][0], nodeinfo[i][1])));
    }
    sort(info.begin(), info.end(), compare);
    //y좌표의 최대값 찾기
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        if (nodeinfo[i][0] > x_size)
        {
            x_size = nodeinfo[i][0] + 1;
        }
        if (nodeinfo[i][1] > y_size)
        {
            header_x = nodeinfo[i][0];
            header_y = nodeinfo[i][1];
            header_N = i + 1;
            y_size = nodeinfo[i][1];
        }
    }
    if (nodeinfo.size() == 1)
    {
        header_N = 1;
    }
    header = (struct Node *)malloc(sizeof(struct Node));
    header->left = NULL;
    header->right = NULL;
    header->N = header_N;

    post.push_back(header_N);
    insert_leftNode(header, info, 0, header_x, header_y);
    insert_rightNode(header, info, header_x + 1, x_size, header_y);
    pre.push_back(header_N);

    answer.push_back(post);
    answer.push_back(pre);
    // for (int i = 0; i < post.size(); i++)
    // {
    //     cout << post[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < post.size(); i++)
    // {
    //     cout << pre[i] << " ";
    // }
    return answer;
}