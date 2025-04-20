#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <istream>

#include "Heap.h"
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

void loadData(RedBlackTree& tree /*add paramter for heap*/, Heap& heap) {

	// TO-DO: Create Heap Object

	// AMF 4/15/25 - Here are the attribute types of a game
	// Parsing requires the information to be caught in strings.

	string s_number,
		name, url, s_year, age_rating, s_rating, s_votes, plot,
		action, adventure, comedy, crime, family, fantasy, mystery,
		scifi, thriller;


	// AMF 4/15/25 - This is the start to parse the data from the .csv file. 
	// The delimeter format is "|"

	ifstream file("../DSA3-gamefinder/game_data/videogames.csv");

	if (!file.is_open()) {
		cout << "Cannot open the file. Try Again";
		return;
	} else {
		cout<< "yay! file opened!" << endl;
	}

	string line;

	getline(file, line);

	// New thing for heap: will be passing in a vector for heap
	vector<NodeHeap> games;

	// debug
	int count = 0;

	while (getline(file, line)) {
		count++;
		cout << "line " << count << ": " << line << endl;

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

		// initalize each node!
		NodeHeap game;
		game.name = name;
		game.url = url;
		game.year = s_year;
		game.cert = age_rating;
		game.votes = s_votes;
		game.plot = plot;
		game.rating = rating;

		// builds the genres map
		vector<string> genresL = {"Action", "Adventure", "Comedy", "Crime", "Family", "Fantasy", "Mystery", "Sci-Fi", "Thriller"};
		vector<string> genreVals = {action, adventure, comedy, crime, family, fantasy, mystery, scifi, thriller};

		// for each game, for each genre, set the node (game's) genres map at i to that genre + the bool of if it's val in the spreadsheet is TRUE or not
		for (int i = 0; i < genresL.size(); i++) {
			game.genres[genresL[i]] = (genreVals[i] == "TRUE");
		}

		games.push_back(game);
	}

	file.close();
	// now that we've built the vector, create heap!!!
	heap = Heap(games);
	cout << "games in vec: " << games.size() << endl;

}
