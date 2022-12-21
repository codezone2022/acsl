#include <iostream>
#include <vector>
using namespace std;

int canPlace(int r, int c, vector<bool>& blocks, int beg, char piece) {
	int end = 0;
	switch(piece) {
	case 'A': {
		int end_ri = (beg-1)/c;
		int end_ci = (beg-1)%c+2;
		if(end_ri >= r || end_ci >= c)
			return 0;
		end = end_ri * c + end_ci + 1;
		for(int p = beg; p <= end; ++p)
			if(blocks[p-1])
				return 0;
		} break;
	case 'B': {
		int end_ri = (beg-1)/c+1;
		int end_ci = (beg-1)%c+1;
		if(end_ri >= r || end_ci >= c)
			return 0;
		end = end_ri * c + end_ci + 1;
		if(blocks[beg-1] || blocks[beg-1+c] || blocks[beg-1+c+1])
			return 0;
		} break;
	case 'C': {
		int end_ri = (beg-1)/c+2;
		int end_ci = (beg-1)%c+1;
		if(end_ri >= r || end_ci >= c)
			return 0;
		end = end_ri * c + end_ci + 1;
		if(blocks[beg-1] || blocks[beg-1+1] || blocks[beg-1+1+c] || blocks[end-1])
			return 0;
		} break;
	}
	return end;
}

bool isEnd(int r, int c, int pos) {
	if(pos >= r*c)
		return true;
	for(int end = c; end <= r*c; end += c)
		if(end == pos)
			return true;
	return false;
}

char nextPiece(char curr) {
	if(!curr)
		return 'A';
	return (curr - 'A' + 1) % 3 + 'A';
}

bool backtrack(int r, int c, vector<bool>& blocks, char piece, int curr_beg, string& res) {
	for(int i = 0; i < 3; ++i) {
		piece = nextPiece(piece);
		int end = canPlace(r, c, blocks, curr_beg, piece);
		if(end) {
			res.push_back(piece);
			if(isEnd(r, c, end))
				return true;
			if(backtrack(r, c, blocks, piece, end+1, res))
				return true;
			res.pop_back();
		}
	}
	return false;
}

int main() {
	for(int i = 0; i < 5; ++i) {
		int r,c,s,n;
		cin >> r >> c >> s >> n;
		vector<bool> blocks(r*c, false);
		for(int j = 0; j < n; ++j) {
			int b;
			cin >> b;
			blocks[b-1] = true;
		}
		string res;
		backtrack(r, c, blocks, 0, s, res);
		cout << res << endl;
	}
	return 0;
}
