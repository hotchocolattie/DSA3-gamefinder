#include "Heap.h"
#include <iostream>

/* Heap assigned to: Grace Zhao
 * Heap structure referenced from: https://www.geeksforgeeks.org/max-heap-in-cpp/
 */

// constructor, initialize heap
// use the set up created by Anna
Heap::Heap(std::vector<NodeHeap> games) {
    // Old line used for debugging: std::cout << "heap will be loading in: " << games.size() << " games" << std::endl;


    gamesHeap = games;
    buildHeap();
}

// compare games, used by heapify
bool Heap::compareGames(const NodeHeap& game1, const NodeHeap& game2) {
    if (game1.rating > game2.rating) {
        return true;
    } else if (game1.rating < game2.rating) {
        return false;
    }

    // ok, sometimes two games might be tied for rating.
    // in that case, we will sort by name a-z

    return game1.name < game2.name;
}


// heapify to maintain heap as heap built
void Heap::heapify(int key) {
    int largest = key;
    int left = 2 * key + 1;
    int right = 2 * key + 2;

    if (left < gamesHeap.size() && compareGames(gamesHeap[left], gamesHeap[largest])) {
        largest = left;
    }

    if (right < gamesHeap.size() && compareGames(gamesHeap[right], gamesHeap[largest])) {
        largest = right;
    }

    if (largest != key) {
        std::swap(gamesHeap[key], gamesHeap[largest]);
        heapify(largest);
    }
}


// build heap from vector anna provided (called by constructor)
void Heap::buildHeap() {
    for (int i = (gamesHeap.size()-1) / 2; i >= 0; i--) {
        heapify(i);
    }
}

void Heap::printGame(const NodeHeap& game) {
    std::cout << game.name << " (" + game.year + ") | Certification: " + game.cert + " | IMBD rating: " << game.rating << " | IMBD votes: " << game.votes << "\n======================================================================================================\n" << game.plot << "\n" << std::endl;
    std::cout << "Genres: ";

    bool firstGame = true;

    for (const auto& genre : game.genres) {
        if (genre.second) {
            if (!firstGame) {
                std::cout << ", ";
            }

            std::cout << genre.first;
            firstGame = false;
        }
    }

    std::cout << "\n\n\n";
}


// print top 10
void Heap::printTop10() {
    // Old line used for debugging: std::cout << "heap size: " << gamesHeap.size() << std::endl;

    std::cout << "Top 10 Games by IMBD Rating (found using Heap data structure): \n\n" << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << (i+1) << ". ";
        printGame(gamesHeap[i]);
    }
}

// Planning:
// To print by genre... since we've sorted by RATING as our key,
// ermmm hmmm we might just have to brute force this by going thru each game and checking their genre maps individually, and print them if they match the wanted genre.
// once you've all finished with the red-black tree filtering, lmk if you've implemented or thought of a better solution!
void Heap::printGenreTop10(std::string genreFind) {
    int weNeed10 = 0;

    std::cout << "Top 10 Games in " << genreFind << " genre by IMBD Rating (found using Heap data structure): \n\n" << std::endl;

    for (const auto& game : gamesHeap) {
        if (game.genres.count(genreFind) && game.genres.at(genreFind)) {
            std::cout << (weNeed10+1) << ". ";
            printGame(game);
            weNeed10++;

            if (weNeed10 == 10) {
                break; // abort!!!
            }
        }
    }
}

