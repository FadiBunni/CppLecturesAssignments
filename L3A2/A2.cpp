#include <iostream>
#include <string>

using namespace std;

enum material {
	wood, stone
};

struct field {
	int x, y;
	bool isWall;
	material type;
};

int main()
{
	int x = 5, y = 5;
	// define n 16
	// define m 12
	int m = 12;
	int n = 16;

	field playground[n][m];

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			playground[i][j].x = i;
			playground[i][j].y = j;
			playground[i][j].isWall = (i == 0 || i == (n - 1) || (j == 0 && i != 3) || j == (m - 1));
			if (playground[i][j].isWall && !(i == 3 && j == 0))
				playground[i][j].type = stone;
			else
				playground[i][j].type = wood;

		}
	}

	bool con = true;
	string commands, command;
	cin >> commands;
	int q = 0;
	while (con) {

		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (i == y && j == x) {
					cout << "O";
				}
				else if (playground[j][i].isWall) {
					cout << "*";
				}
				else {
					cout << " ";
				}

			}
			cout << endl;
		}

		command = commands.substr(q, 1);
		q++;
		// cout << command << " was executed" << endl;

		if (command == "l") {
			if (!playground[x - 1][y].isWall) {
				x--;
			}
		}
		else if (command == "r") {
			if (!playground[x + 1][y].isWall) {
				x++;
			}
		}
		else if (command == "d") {
			if (!playground[x][y + 1].isWall) {
				y++;
			}
		}
		else if (command == "u") {
			if (!playground[x][y - 1].isWall) {
				y--;
			}
		}
		else {
			con = false;
		}

		/*
		switch(command) {
		case "l":
		if (!playground[x-1][y].isWall) {
		x--;
		}
		break;
		case "r":
		if (!playground[x+1][y].isWall) {
		x++;
		}
		break;
		default :
		con = false;
		}
		*/

	}

	/*
	*** ************
	*              *
	*              *
	*              *
	*              *
	*    O         *
	*              *
	*              *
	*              *
	*              *
	*              *
	****************
	*/
	return 0;

}



