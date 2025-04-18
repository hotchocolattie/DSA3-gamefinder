#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "RedBlackTree.h"
using namespace std;

/*------------------------------------------ LOADING DATA ---------------------------------------------------*/
int stringtoInt(string s_attribute) {
	 //AMF 4/15/25 - This function convers the attributes from string to int
	int attribute = 0;

	attribute = stoi(s_attribute);

	return attribute;
}
float stringtoFloat(string s_attribute) {
	// AMF 4/15/25 - This function convers the attributes from string to float
	float attribute = 0;

	attribute = stof(s_attribute);

	return attribute;
}
void addGenres(string genre, string boolean, vector<string>& genres) {
	// AMF 4/15/25 - This function combines a game's genres into one vector.

	if (boolean == "TRUE") {
		genres.push_back(genre);
	}

}
void loadData() {

	RedBlackTree tree;

	// TO-DO: Create Heap Object

	// AMF 4/15/25 - Here are the attribute types of a game
	// Parsing requires the information to be caught in strings.

	string s_number,
		name, url, s_year, age_rating, s_rating, s_votes, plot,
		action, adventure, comedy, crime, family, fantasy, mystery,
		scifi, thriller;


	// AMF 4/15/25 - This is the start to parse the data from the .csv file. 
	// The delimeter format is "|"

	ifstream file("game_data/videogames.csv");

	if (!file.is_open()) {
		cout << "Cannot open the file. Try Again";
	}

	string line;

	getline(file, line);

	while (getline(file, line)) {

		vector<string> genres;
		stringstream source(line);

		getline(source, s_number, '|');
		getline(source, name, '|');
		getline(source, url, '|');
		getline(source, s_year, '|');
		getline(source, age_rating, '|');
		getline(source, s_rating, '|');
		getline(source, s_votes, '|');
		getline(source, plot, '|');
		getline(source, action, '|');
		getline(source, adventure, '|');
		getline(source, comedy, '|');
		getline(source, crime, '|');
		getline(source, family, '|');
		getline(source, fantasy, '|');
		getline(source, mystery, '|');
		getline(source, scifi, '|');
		getline(source, thriller, '|');

		addGenres("action", action, genres);
		addGenres("adventure", adventure, genres);
		addGenres("comedy", comedy, genres);
		addGenres("crime", crime, genres);
		addGenres("family", family, genres);
		addGenres("fantasy", fantasy, genres);
		addGenres("mystery", mystery, genres);
		addGenres("scifi", scifi, genres);
		addGenres("thriller", thriller, genres);


		int number = stringtoInt(s_number);
		int year = stringtoInt(s_year);
		int votes = stringtoInt(s_votes);
		float rating = stringtoFloat(s_rating);


		tree.insert(name, rating, plot, genres);

		// TO-DO: Add a new node to the Heap class
	}

	file.close();
}

