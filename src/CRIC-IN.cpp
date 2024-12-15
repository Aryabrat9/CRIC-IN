#include "game.h"
using namespace std;

int main() {

	Game game;
	game.welcome();
	Sleep(500);
	system("pause");

	game.playerPool();
	Sleep(500);
	system("pause");
	cin.ignore();

	game.selectPlayers();
	Sleep(300);
	game.showTeamPlayers();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	Sleep(500);

	cout << "Press Enter to Toss";
	cin.get();

	game.toss();
	Sleep(500);

	game.startFirstInnings();
	system("pause");
	Sleep(500);
	game.startSecondInnings();
	system("pause");
	Sleep(1000);

	game.validateWinner();
	Sleep(500);

	game.showMatchSummary();
	system("pause");

	return 0;
}
