#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


void loadData() {

	// AMF 4/15/25 - Here are the attribute types of a game
	// Parsing requires the information to be caught in strings.

	string s_number,
		name, url, s_year, c_rating, s_score, s_votes, plot,
		action, comedy, crime, family, fantasy, mystery,
		scifi, thriller;

	int number, year, votes, score;
	char rating;
	vector<string> genres;

	// AMF 4/15/25 - This is the start to parse the data from the .csv file. 
	// The delimeter format is "|"

	ifstream file("game_data/videogames.csv");
	string line;

	getline(file, line);

	while (getline(file, line)) {

		stringstream source(line);

		getline(source, s_number, '|');
		getline(source, name, '|');
		getline(source, url, '|');
		getline(source, s_year, '|');
		getline(source, c_rating, '|');
		getline(source, s_score, '|');
		getline(source, s_votes, '|');
		getline(source, plot, '|');
		getline(source, action, '|');
		getline(source, comedy, '|');
		getline(source, crime, '|');
		getline(source, family, '|');
		getline(source, fantasy, '|');
		getline(source, mystery, '|');
		getline(source, scifi, '|');
		getline(source, thriller, '|');


		cout << s_number << endl;
		cout << name << endl;
		cout << url << endl; 
		cout << plot << endl;

		break;
	}
}
