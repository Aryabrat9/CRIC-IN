#include "game.h"

using namespace std;


Game::Game() {

	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "Karthik";
	players[5] = "KLRahul";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "BKumar";
	players[10] = "Ishant";

	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";
}

void Game::welcome() {

	cout << "-------------------------------------" << endl;
	cout << "|============= CRIC-IN =============|" << endl;
	cout << "|                                   |" << endl;
	cout << "|  Welcome to Virtual Cricket Game  |" << endl;
	cout << "-------------------------------------" << endl << endl;


	cout << "----------------------------------------------------" << endl;
	cout << "|================== INSTRUCTIONS ==================|" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "|                                                  |" << endl;
	cout << "| 1. Create 2 teams (Team-A and Team-B with 4      |" << endl;
	cout << "|    players each) from a given pool of 11 players.|" << endl;
	cout << "| 2. Lead the toss and decide the choice of play.  |" << endl;
	cout << "| 3. Each innings will be of 6 balls.              |" << endl;
	cout << "----------------------------------------------------" << endl;
}

void Game::playerPool() {

	cout << "-------------------------------------" << endl;
	cout << "|========= Pool of Players =========|" << endl;
	cout << "-------------------------------------" << endl;

	for (int i = 0; i < 10; i++) {
		cout << "\t\t[" << i << "] " << players[i] << endl;
	}
	cout << endl;
}

int Game::takeIntegerInput() {

	int n;

	while (!(cin >> n)) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input! Please try again with valid input: ";
	}

	return n;
}

bool Game::validateSelectedPlayer(int index) {

	int n;
	vector<Player> players;

	//Team A
	players = teamA.players;
	n = players.size();
	for (int i = 0; i < n; i++) {
		if (players[i].index == index) {
			return false;
		}
	}

	//Team B
	players = teamB.players;
	n = players.size();
	for (int i = 0; i < n; i++) {
		if (players[i].index == index) {
			return false;
		}
	}

	return true;
}

void Game::selectPlayers() {

	cout << endl;
	cout << "----------------------------------------" << endl;
	cout << "|====== Create Team-A and Team-B ======|" << endl;
	cout << "----------------------------------------" << endl;

	for (int i = 0; i < playersPerTeam; i++) {

		//Team A
		teamASelection:
			cout << endl << "Select Player " << i + 1 << " of Team A - ";
			int playerIndexTeamA = takeIntegerInput();

			if (playerIndexTeamA < 0 || playerIndexTeamA > 10) {
				cout << endl << "Please select from the given Players." << endl;
				goto teamASelection;
			} else if (!validateSelectedPlayer(playerIndexTeamA)) {
				cout << "Please select from given Players." << endl;
				goto teamASelection;
			} else {
				Player teamAPlayer;
				teamAPlayer.index = playerIndexTeamA;
				teamAPlayer.name = players[playerIndexTeamA];
				teamA.players.push_back(teamAPlayer);
			}


		//Team B
		teamBSelection:
			cout << endl << "Select player " << i + 1 << " of Team B - ";
			int playerIndexTeamB = takeIntegerInput();

			if (playerIndexTeamB < 0 || playerIndexTeamB > 10) {
				cout << endl << "Please select from the given players" << endl;
				goto teamBSelection;
			} else if (!validateSelectedPlayer(playerIndexTeamB)) {
				cout << "Please select from given Players." << endl;
				goto teamBSelection;
			} else {
				Player teamBPlayer;
				teamBPlayer.name = players[playerIndexTeamB];
				teamB.players.push_back(teamBPlayer);
			}
	}
}

void Game::showTeamPlayers() {

	cout << "--------------------------\t\t" << "--------------------------\t" << endl;
	cout << "|======== Team-A ========|\t\t" << "|======== Team-B ========|\t" << endl;
	cout << "--------------------------\t\t" << "--------------------------\t" << endl;

	for (int i = 0; i < playersPerTeam; i++) {

	cout << "|\t[" << i << "] " << teamA.players[i].name << "\t |\t\t" << "|\t[" << i << "] " << teamB.players[i].name << "\t |" << endl;
	}
	cout << "--------------------------\t\t" << "--------------------------\t" << endl << endl;
}


void Game::toss() {

	cout << endl;
	cout << "--------------------------------" << endl;
	cout << "|========= Let's Toss =========|" << endl;
	cout << "--------------------------------" << endl << endl;

	cout << "Tossing the coin......." << endl;
	Sleep(2000);

	srand(time(NULL));
	int toss = rand() % 2;
	switch (toss) {
		case 0:
			cout << "Team-A won the toss!" << endl << endl;
			tossChoice(teamA);
			break;
		case 1:
			cout << "Team-B won the toss!" << endl << endl;
			tossChoice(teamB);
			break;
	}
}

void Game::tossChoice(Team tossWinnerTeam) {

	cout << "Enter 1 to bat or 2 to bowl." << endl;
	cout << "1. Bat" << endl;
	cout << "2. Bowl" << endl;
	int tossInput = takeIntegerInput();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	switch (tossInput) {
		case 1:
			cout << tossWinnerTeam.name << " won the toss and elected to bat first." << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			} else {
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}

			break;
		case 2:
			cout << tossWinnerTeam.name << " won the toss and elected to bowl first." << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			} else {
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			}

			break;

		default:
			cout << endl << "Invalid Input. Please try again:" << endl << endl;
			tossChoice(tossWinnerTeam);
			break;
	}
}


void Game::startFirstInnings() {

	cout << "\t\t ||| FIRST INNINGS ||| " << endl << endl;

	isFirstInnings = true;

	initializePlayers();
	playInnings();
}

void Game::initializePlayers() {

	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout << battingTeam->name << " - " << batsman->name << " is batting. " << endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling. " << endl << endl;
}


void Game::playInnings() {

	for (int i = 0; i < maxBalls; i++) {

		cout << "Press Enter to bowl.....";
		cin.get();
		cout << "Bowling..." << endl;
		bat();

		if (!validateInningsScore()) {
			break;
		}
	}
}


void Game::bat() {

	srand(time(NULL));
	int runsScored = rand() % 7;

	batsman->runsScored += runsScored;
	battingTeam->totalRunsScored += runsScored;
	batsman->ballsPlayed += 1;

	bowler->ballsBowled += 1;
	bowlingTeam->totalBallsBowled += 1;
	bowler->runsGiven += runsScored;
	Sleep(1250);

	if (runsScored != 0) {
		cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
		showGameScorecard();
	} else {
		cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

		battingTeam->wicketsLost += 1;
		bowlingTeam->wicketsTaken += 1;
		bowler->wicketsTaken += 1;

		showGameScorecard();

		int nextPlayerIndex = battingTeam->wicketsLost;
		batsman = &battingTeam->players[nextPlayerIndex];
	}
}


bool Game::validateInningsScore() {

	if (isFirstInnings) {

		if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

			cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;
			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
					<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
					<< ")" << endl;
			cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
					<< " runs to win the match." << endl << endl;

			return false;
		}
	} else {

		if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

			cout << "\t\t ||| SECOND INNINGS ENDS ||| " << endl << endl;
			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
					<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
					<< ")" << endl << endl;

			return false;
		}
	}

	return true;
}


void Game::showGameScorecard() {

    cout << "--------------------------------------------------------------------------" << endl;

    cout << "\t" << battingTeam->name << "  " << battingTeam->totalRunsScored << " - "
      << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") | " << batsman->name
      << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
	  << bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;

    cout << "--------------------------------------------------------------------------" << endl << endl;
}


void Game::startSecondInnings() {

	cout << "\t\t ||| SECOND INNINGS ||| " << endl << endl;

	isFirstInnings = false;

	initializeTeamSwap();
	initializePlayers();
	playInnings();
}


void Game::initializeTeamSwap() {

	swap(battingTeam, bowlingTeam);
}


void Game::validateWinner() {

	if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored) {
		cout << battingTeam->name << " WON THE MATCH!!!" << endl << endl;
	} else if (battingTeam->totalRunsScored < bowlingTeam->totalRunsScored) {
		cout << bowlingTeam->name << " WON THE MATCH!!!" << endl << endl;
	} else {
		cout << battingTeam->name << " AND " << bowlingTeam << " TIE!!!" << endl << endl;
	}
}

void Game::showMatchSummary() {

	cout << "\t\t ||| MATCH ENDS |||" << endl << endl;


	cout << battingTeam->name << " " << battingTeam->totalRunsScored << "-" << battingTeam->wicketsTaken
			<< " (" << battingTeam->totalBallsBowled << ")" << endl;

	cout << "==========================================" << endl;
	cout << "| PLAYER\t BATTING\t BOWLING |" << endl;
	for (int i = 0; i < playersPerTeam; i++) {
		cout <<"| [" << i << "] " << battingTeam->players[i].name << "\t "
				<< battingTeam->players[i].runsScored << "(" << battingTeam->players[i].ballsPlayed
				<< ")\t\t " << battingTeam->players[i].ballsBowled << "-"
				<< battingTeam->players[i].runsGiven << "-" << battingTeam->players[i].wicketsTaken
				<< "\t |" << endl;
	}
	cout << "==========================================" << endl;


	cout << bowlingTeam->name << " " << bowlingTeam->totalRunsScored << "-" << bowlingTeam->wicketsTaken
			<< " (" << bowlingTeam->totalBallsBowled << ")" << endl;

	cout << "==========================================" << endl;
	cout << "| PLAYER\t BATTING\t BOWLING |" << endl;
	for (int i = 0; i < playersPerTeam; i++) {
		cout <<"| [" << i << "] " << bowlingTeam->players[i].name << "\t "
				<< bowlingTeam->players[i].runsScored << "(" << bowlingTeam->players[i].ballsPlayed
				<< ")\t\t " << bowlingTeam->players[i].ballsBowled << "-"
				<< bowlingTeam->players[i].runsGiven << "-" << bowlingTeam->players[i].wicketsTaken
				<< "\t |" << endl;
	}
	cout << "==========================================" << endl;
}





















