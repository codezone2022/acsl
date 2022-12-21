#include <bits/stdc++.h>
using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;

void dfs(vvb& connected, vvi& weights, string path, int total_weight, int& max_weight) {
	if(path.length() > 1 && path.front() == path.back()) { // found a cycle
		max_weight = max(max_weight, total_weight);
		return;
	}
	for(int i = 0; i < path.length()-1; ++i)
		if(path[i] == path.back())
			return; // visited in the path
	int curr = path.back() - 'A';
	for(int i = 0; i < 26; ++i) {
		if(!connected[curr][i]) // include self-loop
			continue;
		int weight = weights[curr][i];
		char next = 'A' + i;
		dfs(connected, weights, path + next, total_weight + weight, max_weight);
	}
}

int main() {
	while(true) {
		string line;
		getline(cin, line);
		if(!cin || line.empty())
			break;
		vvb connected(26,vb(26,false)); // 0 weight is not specified
		vvi weights(26,vi(26,0));
		set<int> vertices;
		istringstream sin(line);
		while(sin) {
			string edge;
			sin >> edge;
			if(!sin || edge.empty())
				break;
			int weight;
			sin >> weight;
			if(!sin)
				break;
			int from = edge[0] - 'A'; int to = edge[1] - 'A';
			connected[from][to] = true;
			weights[from][to] = weight;
			vertices.insert(from);
			vertices.insert(to);
		}
		int res = INT_MIN;
		for(int start : vertices) {
			string path;
			path += ('A' + start);
			dfs(connected, weights, path, 0, res);
		}
		cout << (res == INT_MIN ? 0 : res) << endl;
	}
	return 0;
}
