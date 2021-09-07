/*
* ����������һ��2x3�Ļ���ƴͼ����һ��2x3������board��ʾ��ƴͼ��������0-5������0�ʹ�����ŵĸ��ӣ������ƶ�����boardΪ[[1,2,3],[4,5,0]]ʱӮ����Ϸ���������ƶ�����
* 2 1 4     2 1 4 5 0 3
* 5 0 3     0 1 2 3 4 5
*/
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;

int slidingPuzzle(vector<vector<int>>& board)
{
	int m = board.size(); 
	int n = board[0].size();

	string start = "";
	string target = "123450";

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			start.push_back(board[i][j] + '0');
		}
	}

	vector<vector<int>> neighbor = {
		{1, 3},
		{0, 4, 2},
		{1, 5},
		{0, 4},
		{1, 3, 5},
		{2, 4}
	};

	queue<string> q;
	unordered_set<string> visited;
	q.push(start);
	visited.insert(start);
	int step = 0;

	while (!q.empty())
	{
		for (int i = 0; i < q.size(); i++) {
			string cur = q.front();
			q.pop();
			if (cur == target) {
				return step;
			}
			int zeroIndex = 0;
			for (; cur[zeroIndex] != '0'; zeroIndex++);
			for (int swapIndex : neighbor[zeroIndex]){
				string swapStr = cur;
				swap(swapStr[swapIndex], swapStr[zeroIndex]);
				if (!visited.count(swapStr)) {
					q.push(swapStr);
					visited.insert(swapStr);
				}
			}
		}
		step++;
	}
	return -1;

}