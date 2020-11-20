#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct Piece {
	int y, x, d, number;
};

const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { 1, -1, 0, 0 };

int N, K;
int chessboard[13][13];
Piece pieces[11];
vector<Piece> A[13][13];

int main() {
	int i, j, turn(0);

	scanf("%d %d", &N, &K);

	for (i = 1; i <= N; ++i)
		for (j = 1; j <= N; ++j)
			scanf("%d", &chessboard[i][j]);

	for (i = 1; i <= K; ++i) {
		Piece piece;
		scanf("%d %d %d", &piece.y, &piece.x, &piece.d);
		--piece.d, piece.number = i;
		pieces[i] = piece;
		A[piece.y][piece.x].push_back(piece);
	}

	while (true) {
		if (++turn > 1000) {
			printf("-1");
			return 0;
		}

		for (i = 1; i <= K; ++i) {
			Piece piece = pieces[i];
			int y = piece.y + dy[piece.d];
			int x = piece.x + dx[piece.d];

			// Off the chessboard, or Blue
			if (y < 1 || y > N || x < 1 || x > N || chessboard[y][x] == 2) {
				piece.d = (piece.d == 0 || piece.d == 2) ? (piece.d + 1) : (piece.d - 1);
			
				y = piece.y + dy[piece.d];
				x = piece.x + dx[piece.d];
				pieces[i].d = piece.d;
				
				if (y < 1 || y > N || x < 1 || x > N || chessboard[y][x] == 2) 
					continue;
			}

		

			// White
			if (chessboard[y][x] == 0) {
				Piece stacked_piece = A[piece.y][piece.x].back();
				A[piece.y][piece.x].pop_back();

				vector<Piece> v;
				v.push_back(stacked_piece);

				while (stacked_piece.number != piece.number) {
					stacked_piece = A[piece.y][piece.x].back();
					A[piece.y][piece.x].pop_back();
					v.push_back(stacked_piece);
				}

				while (!v.empty()) {
					Piece unstacked_piece = v.back();
					v.pop_back();

					if (unstacked_piece.number == piece.number)
						unstacked_piece.d = piece.d;

					A[y][x].push_back(unstacked_piece);

					pieces[unstacked_piece.number].y = y, pieces[unstacked_piece.number].x = x;
				}

				if (A[y][x].size() >= 4) {
					printf("%d", turn);
					return 0;
				}
			}

			// Red
			if (chessboard[y][x] == 1) {
				Piece stacked_piece = A[piece.y][piece.x].back();
				A[piece.y][piece.x].pop_back();

				queue<Piece> q;
				q.push(stacked_piece);

				while (stacked_piece.number != piece.number) {
					stacked_piece = A[piece.y][piece.x].back();
					A[piece.y][piece.x].pop_back();
					q.push(stacked_piece);
				}

				while (!q.empty()) {
					Piece unstacked_piece = q.front();
					q.pop();

					if (unstacked_piece.number == piece.number)
						unstacked_piece.d = piece.d;

					A[y][x].push_back(unstacked_piece);

					pieces[unstacked_piece.number].y = y, pieces[unstacked_piece.number].x = x;
				}

				if (A[y][x].size() >= 4) {
					printf("%d", turn);
					return 0;
				}
			}
		}
	}

	return 0;
}
