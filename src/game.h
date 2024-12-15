#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <Windows.h>
#include "team.h"		// "player.h", <string>, <vector>


class Game {

	public:
		Game();
		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string players[11];

		bool isFirstInnings;
		Team teamA, teamB;
		Team *battingTeam, *bowlingTeam;
		Player *batsman, *bowler;

		int takeIntegerInput();

		bool validateSelectedPlayer(int);
		bool validateInningsScore();

		void welcome();
		void playerPool();
		void selectPlayers();
		void showTeamPlayers();
		void toss();
		void tossChoice(Team);
		void startFirstInnings();
		void startSecondInnings();
		void initializePlayers();
		void playInnings();
		void bat();
		void showGameScorecard();
		void initializeTeamSwap();
		void validateWinner();
		void showMatchSummary();
};
