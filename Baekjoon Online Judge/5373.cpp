#include <cstdio>
#include <cstring>

enum Color {
	white = 0,
	yellow,
	red,
	orange,
	green,
	blue
};

char orignalDice[6][3][4] = {
	{ "www", "www", "www" },
    { "yyy", "yyy", "yyy" },
    { "rrr", "rrr", "rrr" },
    { "ooo", "ooo", "ooo" },
    { "ggg", "ggg", "ggg" },
    { "bbb", "bbb", "bbb" }
};

char dice[6][3][4] = {
	{ "www", "www", "www" },
    { "yyy", "yyy", "yyy" },
    { "rrr", "rrr", "rrr" },
    { "ooo", "ooo", "ooo" },
    { "ggg", "ggg", "ggg" },
    { "bbb", "bbb", "bbb" }
};


void rotate(int side) {
	char t_dice[3][4];

	for (int i(0); i < 3; ++i)
		for (int j(0); j < 3; ++j)
			t_dice[j][3 - i - 1] = dice[side][i][j];

	for (int i(0); i < 3; ++i)
		for (int j(0); j < 3; ++j)
			dice[side][i][j] = t_dice[i][j];

	char t[4];

	switch (side)
	{
	case white:
		memcpy(t, dice[red][0], sizeof(char) * 4);
		memcpy(dice[red][0], dice[blue][0], sizeof(char) * 4);
		memcpy(dice[blue][0], dice[orange][0], sizeof(char) * 4);
		memcpy(dice[orange][0], dice[green][0], sizeof(char) * 4);
		memcpy(dice[green][0], t, sizeof(char) * 4);
		break;
	case yellow:
		memcpy(t, dice[red][2], sizeof(char) * 4);
		memcpy(dice[red][2], dice[green][2], sizeof(char) * 4);
		memcpy(dice[green][2], dice[orange][2], sizeof(char) * 4);
		memcpy(dice[orange][2], dice[blue][2], sizeof(char) * 4);
		memcpy(dice[blue][2], t, sizeof(char) * 4);
		break;
	case red:
		memcpy(t, dice[white][2], sizeof(char) * 4);
		for (int i(0); i < 3; ++i)
			dice[white][2][i] = dice[green][2 - i][2];
		for (int i(0); i < 3; ++i)
			dice[green][i][2] = dice[yellow][0][i];
		for (int i(0); i < 3; ++i)
			dice[yellow][0][i] = dice[blue][2 - i][0];
		for (int i(0); i < 3; ++i)
			dice[blue][i][0] = t[i];
		break;
	case orange:
		memcpy(t, dice[white][0], sizeof(char) * 4);
		for (int i(0); i < 3; ++i)
			dice[white][0][i] = dice[blue][i][2];
		for (int i(0); i < 3; ++i)
			dice[blue][i][2] = dice[yellow][2][2 - i];
		for (int i(0); i < 3; ++i)
			dice[yellow][2][i] = dice[green][i][0];
		for (int i(0); i < 3; ++i)
			dice[green][i][0] = t[2 - i];
		break;
	case green:
		for (int i(0); i < 3; ++i)
			t[i] = dice[white][i][0];
		for (int i(0); i < 3; ++i)
			dice[white][i][0] = dice[orange][2 - i][2];
		for (int i(0); i < 3; ++i)
			dice[orange][i][2] = dice[yellow][2 - i][0];
		for (int i(0); i < 3; ++i)
			dice[yellow][i][0] = dice[red][i][0];
		for (int i(0); i < 3; ++i)
			dice[red][i][0] = t[i];
		break;
	case blue:
		for (int i(0); i < 3; ++i)
			t[i] = dice[white][i][2];
		for (int i(0); i < 3; ++i)
			dice[white][i][2] = dice[red][i][2];
		for (int i(0); i < 3; ++i)
			dice[red][i][2] = dice[yellow][i][2];
		for (int i(0); i < 3; ++i)
			dice[yellow][i][2] = dice[orange][2 - i][0];
		for (int i(0); i < 3; ++i)
			dice[orange][i][0] = t[2 - i];
		break;
	default:
		break;
	}
}

void twirl(char side, char direction) {

	switch (side)
	{
	case 'U': 
		if (direction == '+')
			rotate(white);
		else
			for (int i(0); i < 3; ++i)
				rotate(white);
		break;
	case 'D':
		if (direction == '+')
			rotate(yellow);
		else
			for (int i(0); i < 3; ++i)
				rotate(yellow);
		break;
	case 'F':
		if (direction == '+')
			rotate(red);
		else
			for (int i(0); i < 3; ++i)
				rotate(red);
		break;
	case 'B':
		if (direction == '+')
			rotate(orange);
		else
			for (int i(0); i < 3; ++i)
				rotate(orange);
		break;
	case 'L':
		if (direction == '+')
			rotate(green);
		else
			for (int i(0); i < 3; ++i)
				rotate(green);
		break;
	case 'R':
		if (direction == '+')
			rotate(blue);
		else
			for (int i(0); i < 3; ++i)
				rotate(blue);
		break;
	default:
		break;
	}
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t(0); t < T; ++t) {
		int n;
		scanf("%d", &n);

		for (int i(0); i < n; ++i) {
			char m[3];
			scanf("%s", &m);
			twirl(m[0], m[1]);
		}

		for (int i(0); i < 3; ++i)
			printf("%s\n", dice[0][i]);			

		memcpy(dice, orignalDice, sizeof(dice));
	}

	return 0;
}
