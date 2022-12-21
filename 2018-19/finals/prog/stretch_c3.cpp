#include <iostream>
#include <vector>
using namespace std;

pair<int,int> toRowCol(int r, int c, int s) {
	int ri = (s-1) / c;
	int ci = (s-1) % c;
	return {ri, ci};
}

int toSeqNum(int r, int c, int ri, int ci) {
	return ri * c + ci + 1;
}

bool isValid(int r, int c, int ri, int ci) {
	return 0 <= ri && ri < r && 0 <= ci && ci < c;
}

char nextPiece(char curr) {
	if(!curr)
		return 'A';
	return (curr - 'A' + 1) % 3 + 'A';
}

bool isEnd(int r, int c, int s) {
	auto rc = toRowCol(r, c, s);
	return rc.second == c - 1;
}

int endPole(int r, int c, int begPole, char piece) {
	auto rc = toRowCol(r, c, begPole); int rl = rc.first; int cl = rc.second;
	int rr, cr;
	switch(piece) {
	case 'A': rr = rl;   cr = cl + 2; break;
	case 'B': rr = rl+1; cr = cl + 1; break;
	case 'C': rr = rl+2; cr = cl + 1; break;
	}
	return isValid(r, c, rr, cr) ? toSeqNum(r, c, rr, cr) : 0;
}

bool canPlace(int r, int c, vector<bool>& blocks, int begPole, char piece) {
	auto rc = toRowCol(r, c, begPole);
	int ri = rc.first;
	int ci = rc.second;
	switch(piece) {
	case 'A':
		if( !isValid(r, c, ri, ci  ) || blocks[toSeqNum(r, c, ri, ci  )] || // left-pole (center cell)
			!isValid(r, c, ri, ci+1) || blocks[toSeqNum(r, c, ri, ci+1)] || // ‘A’
			!isValid(r, c, ri, ci+2) || blocks[toSeqNum(r, c, ri, ci+2)] )  // right-pole
			return false;
		break;
	case 'B':
		if(	!isValid(r, c, ri  , ci  )||blocks[toSeqNum(r, c, ri  , ci  )] || // left-pole (center cell)
			!isValid(r, c, ri+1, ci  )||blocks[toSeqNum(r, c, ri+1, ci  )] || // ‘B’
			!isValid(r, c, ri+1, ci+1)||blocks[toSeqNum(r, c, ri+1, ci+1)] )  // right-pole
			return false;
		break;
	case 'C':
		if( !isValid(r, c, ri  , ci  )||blocks[toSeqNum(r, c, ri  , ci  )] || // left-pole (center cell)
		    !isValid(r, c, ri  , ci+1)||blocks[toSeqNum(r, c, ri  , ci+1)] || // Upper ‘C’
		    !isValid(r, c, ri+1, ci+1)||blocks[toSeqNum(r, c, ri+1, ci+1)] || // Lower ‘C’
		    !isValid(r, c, ri+2, ci+1)||blocks[toSeqNum(r, c, ri+2, ci+1)] )  // right-pole
			return false;
		break;
	}
	return true;
}

int main(int argc, char* argv[]) {
	int N = argc > 1 ? atoi(argv[1]) : 5;
	for(int i = 0; i < N; ++i) {
		// Process input data
		int r,c,s,n;
		cin >> r >> c >> s >> n;
		vector<bool> blocks(r*c+1, false);
		for(int j = 0; j < n; ++j) {
			int b;
			cin >> b;
			blocks[b] = true;
		}
		// Complete Search - whenever a piece can be placed, move on to the next step
		char piece = '\0';
		string res;
		int ep = s;
		bool found = false;
		while(!found) {
			for(int i = 0; i < 3 && !found; ++i) {
				piece = nextPiece(piece);
				if(canPlace(r, c, blocks, ep, piece)) {
					res.push_back(piece);
					ep = endPole(r, c, ep, piece);
					if(isEnd(r, c, ep))
						found = true;
					else
						++ep;
					break;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
