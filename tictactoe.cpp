#include <bits/stdc++.h>
using namespace std;
int grid[10][10];
int posx, posy;
int isDone(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;
}

int getScore(int n) {
	for(int i = 0; i < n; i++) {
		int now = grid[i][0];
		int flag = 1;
		for(int j = 1; j < n; j++) {
			if(now != grid[i][j]) {
				flag = 0;
				break;
			}
		}
		if(flag) {
			if(now == 1) return 10;
			else if(now == 2) return -10;
		}
	}

	for(int i = 0; i < n; i++) {
		int now = grid[0][i];
		int flag = 1;
		for(int j = 1; j < n; j++) {
			if(now != grid[j][i]) {
				flag = 0;
				break;
			}
		}
		if(flag) {
			if(now == 1) return 10;
			else if(now == 2) return -10;
		}
	}

	int flag = 1;
	int now = grid[0][0];
	for(int i = 1; i < n; i++) {
		if(now != grid[i][i]) {
			flag = 0;
			break;
		}
	}
	if(flag) {
		if(now == 1) return 10;
		else if(now == 2) return -10;
	}

	flag = 1;
	now = grid[0][n - 1];
	for(int i = 1; i < n; i++) {
		if(now != grid[i][n - i - 1]) {
			flag = 0;
			break;
		}
	}
	if(flag) {
		if(now == 1) return 10;
		else if(now == 2) return -10;
	}

	return 0;
}

void print(int n) {
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t-------------";
	cout << endl;
	int row = 0;
	for(int i = 0; i < 2 * n; i++) {
		if(i % 2 == 0) {
			cout << "\t\t\t\t\t\t\t|";
			for(int j = 0; j < n; j++) {
				if(grid[row][j] == 1) {
					cout << " o";
				}
				else if(grid[row][j] == 2) {
					cout << " x";
				}
				else if(grid[row][j] == 0) {
					cout << "  ";
				}
				cout << " |";
			}
			cout << endl;
			row++;
		}
		else {
			cout << "\t\t\t\t\t\t\t-------------";
			cout << endl;
		}
	}
}

int minimax(int n, int play) {
	int score = getScore(n);
	if(score != 0) return score;
	if(isDone(n)) return score;
	int best;
	if(play == 1)
		best = 1000;
	else
		best = -1000;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j] == 0) {
				if(play == 0) {
					grid[i][j] = 1;
					best = max(best, minimax(n, (play + 1) % 2));
					grid[i][j] = 0;
				}
				else if(play == 1) {
					grid[i][j] = 2;
					best = min(best, minimax(n, (play + 1) % 2));
					grid[i][j] = 0;
				}
			}
		}
	}
	return best;
}

int main() {
	cout << "\n\n\n\t\t\t\t\t\t\t Tic-Tac-Toe \t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t 1. Main Tic-Tac-Toe" << endl;
	cout << "\t\t\t 2. Cara Bermain\n" << endl;
	cout << "\t\t\t Pilihan: ";
	int cmenu;
	char tmpstr[10];
	cin >> cmenu;
	if(cmenu==2){
		system("cls");
		printf("\n\n\n\t\t\t\t\t\tCara Bermain Tic-Tac-Toe\n");
		cout << "\t\t\t 1. Tic-Tac-Toe adalah permainan dimana pemain yang berhasil membuat 3 bidak nya" << endl;
		cout << "\t\t\t    horizontal/vertikal/diagonal berurutan lebih dulu, ia yang menang" << endl;
		cout << "\t\t\t    Contoh permainan:\n" << endl;
		cout << "\t\t\t\t-------------\t\t\t\t-------------" << endl;
		cout << "\t\t\t\t| x | x | o |\t\t\t\t| x | x | o |" << endl;
		cout << "\t\t\t\t-------------\t\t\t\t-------------" << endl;
		cout << "\t\t\t\t|   | o |   |\t\t\t\t|   | o | o |" << endl;
		cout << "\t\t\t\t-------------\t\t\t\t-------------" << endl;
		cout << "\t\t\t\t| x |   | o |\t\t\t\t| x |   | o |" << endl;
		cout << "\t\t\t\t-------------\t\t\t\t-------------" << endl;
		cout << "\t\t\t\tAI(x y): 0 2\t\t\t\tPemain(x y): 1 2\n" << endl;
		cout << "\t\t\t    Pemain menang karena berhasil membuat 3 bidaknya berurutan pada posisi (x y):" << endl;
		cout << "\t\t\t    (0 2) , (1 2), (2 2)." << endl;
		cout << "\t\t\t 2. Pemain menggunakan bidak dengan simbol 'o'." << endl;
		cout << "\t\t\t 3. AI menggunakan bidak dengan simbol 'x'." << endl;
		
		cmenu=1;
		cout << "\n\t\t\t\t\t\t  Tekan Enter untuk bermain...";
        fflush(stdin);
        gets(tmpstr);
	}
	if(cmenu==1){
		while(1){
			system("cls");
			int n=3;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					grid[i][j] = 0;
				}
			}
			
			int flag = 1;
			int win = 0;
			int res;
			int cmenu;
			while(1){
				int score = getScore(n);
				print(n);
				if(score == 10) win = 1;
				if(isDone(n) || score != 0) {
					res = score;
					break;
				}
				int x, y;
				cout << "\n\t\t\t\t\t\t\t  x y : ";
				cin >> x >> y;
				if(grid[x][y] || x < 0 || x >= n || y < 0 || y >= n) {
					cout << "ulangi" << endl;
					continue;
				}
				grid[x][y] = 1;
				int bestVal = 1000, moveVal;
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < n; j++) {
						if(grid[i][j] == 0) {
							grid[i][j] = 2;
							moveVal = minimax(n, 0);
							if(bestVal > moveVal || getScore(n) == -10) {
								bestVal = moveVal;
								posx = i;
								posy = j;
							}
							grid[i][j] = 0;
						}
					}
				}
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < n; j++) {
						if(i == posx && j == posy) {
							grid[i][j] = 2;
						}
					}
				}
				system("cls");
			}
			cout << endl;
			if(res == 0) cout << "\t\t\t\t\t\t\tHasil imbang!" << endl;
			else if(res == 10) printf("\t\t\t\t\t\t\tPemain menang!\n");
			else printf("\t\t\t\t\t\t\tPemain Kalah!\n");
			
			cout << endl;
			cout << "\t\t\t\t\t\t\t  Main lagi?" << endl;
			cout << "\t\t\t\t\t\t 1. Ya\t\t\t 2. Tidak" << endl;
			int pilihannya;
			cin >> pilihannya;
			if(pilihannya==2) break;
			else continue;
		}
	}
	return 0;
}
