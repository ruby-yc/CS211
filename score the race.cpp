#include <iostream>
using namespace std;

void scoreRace(string result) {
    int teamCounts[26] = {0}; //amount of runner
    double teamScores[26] = {0}; //total score

    for (int i = 0; i < result.length(); ++i) {
        char team = result[i];
        int teamIndex = team - 'A';
        teamCounts[teamIndex]++;
        teamScores[teamIndex] += (i + 1); //score is equal to ranking
    }

    // make sure num of runners are equal
    int numRunners = -1;
    bool isValid = true;
    for (int i = 0; i < 26; ++i) {
        if (teamCounts[i] > 0) {
            if (numRunners == -1) {
                numRunners = teamCounts[i]; 
            } else if (teamCounts[i] != numRunners) {
                isValid = false;
                break;
            }
        }
    }

    if (!isValid) {
        cout << "Teams do not have the same number of runners. Please enter again: " << endl;
        return;
    }

    //average score of team
    double teamAverages[26] = {0};
    for (int i = 0; i < 26; ++i) {
        if (teamCounts[i] > 0) {
            teamAverages[i] = teamScores[i] / teamCounts[i];
        }
    }
    // num of total teams
    int totalTeams = 0;
    for (int i = 0; i < 26; ++i) {
        if (teamCounts[i] > 0) {
            totalTeams++;
        }
    }
    cout << "There are " << totalTeams << " teams." << endl;

    //num of runner
    cout << "Each team has " << numRunners << " runners." << endl;

    //output team score
    cout << "Team Score" << endl;
    for (int i = 0; i < 26; ++i) {
        if (teamCounts[i] > 0) {
            char teamName = 'A' + i;
            cout << teamName << " " << teamAverages[i] << endl;
        }
    }

    //find winning team
    double minScore = -1;
    char winningTeam = 'A';
    for (int i = 0; i < 26; ++i) {
        if (teamCounts[i] > 0 && (minScore == -1 || teamAverages[i] < minScore)) {
            minScore = teamAverages[i];
            winningTeam = 'A' + i;
        }
    }
    cout << "The winning team is team " << winningTeam << " with a score of " << minScore << "." << endl;
}

int main() {
    while (true) {
        cout << "Enter the race result (or 'done' to finish): ";
        string result;
        cin >> result;

        if (result == "done") {
            break;
        }

        // uppercase or not
        bool isValidInput = true;
        for (int i = 0; i < result.length(); ++i) {
            char c = result[i];
        
            if (c < 'A' || c > 'Z') {
                isValidInput = false;
                break;
            }
        }

        if (!isValidInput) {
            cout << "Invalid input. Please enter only uppercase letters." << endl;
            continue;
        }

        scoreRace(result);
    }

    return 0;
}