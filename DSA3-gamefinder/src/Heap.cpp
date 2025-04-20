#include "Heap.h"
#include <iostream>

/* Heap assigned to: Grace Zhao
 * Heap structure referenced from: https://www.geeksforgeeks.org/max-heap-in-cpp/
 */

// constructor, initialize heap
// use the set up created by Anna
Heap::Heap(std::vector<NodeHeap> games) {
    std::cout << "heap will be loading in: " << games.size() << " games" << std::endl;


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
    std::cout << game.name << " (" + game.year + ") | Certification: " + game.cert + " | IMBD rating: " << game.rating << " | IMBD votes: " << game.votes << "\n============================================================================================\n" << game.plot << "\n" << std::endl;
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

    std::cout << "\n\n\n\n\n";
}


// print top 10
void Heap::printTop10() {
    std::cout << "heap size: " << gamesHeap.size() << std::endl;

    for (int i = 0; i < 10; i++) {
        printGame(gamesHeap[i]);
    }
}
