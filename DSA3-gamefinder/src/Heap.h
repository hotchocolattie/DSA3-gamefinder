#pragma once
#include <vector>
#include <string>
#include <map>

/* Heap will be coded by: Grace Zhao
 *
 * Planning:
 * - build max heap with rating as the key
 * - also make sure genres are accessable and filterable in some way
 *
 * Notes:
 * - csv genres are stored individually with TRUE/FALSE if they're in genre
 * - we can probably store all that into a map for better searching
 *
 * NodeHeap structure:
 * - CSV has: |name|url|year|certificate|rating|votes|plot|Action|Adventure|Comedy|Crime|Family|Fantasy|Mystery|Sci-Fi|Thriller
 * - so, string, string, string, string, int (RATING + KEY), string, string, <MAP> (w/ string, then bool)
 * rest can be stored as string, since they'll only be printed, not the key which the heap will be based on
 * rating will be in int so comparing and building heap is easier!!!
 *
 *
 *
 *
 * basic heap structure (information provided by Geeksforgeeks: https://www.geeksforgeeks.org/max-heap-in-cpp/)
 * - some template will be what the heap stores (we will have a struct outlining NodeHeap) Each NodeHeap will be a game
 * - then, a vector that stores said template, aka NodeHeaps, aka games
 * - some constructor that intializes heap. will take in the vector of NodeHeaps/games and puts them into the heap
 * - some function to heapify the heap (reorganize subtree from x NodeHeap to make sure everythings still in heap order. maintains heap basically as new NodeHeaps are added/deleted)
 * - some function to insert new NodeHeap/game into heap (subfunction: to compare the rating of two games to ensure they're getting inserted correctly)
 *  ^^ actually it's needed to code the compare function separetly, as heapify will also use it
 * - some function that builds the heap by calling all the subfunctions listed above.
 *
 * stuff from geeksforgeeks thats unneeded:
 * - top (could probably just replace with a top 10 getter, as we don't need the best game of all time, we need the top 10)
 * - pop (we won't be removing anything)
 * - delete key (we won't be removing anything)
 *
 * stuff not in the geeksforgeeks we DO need:
 * - top 10 printer
 * - top 10 in [genre] printer (we will take in genre as a string!! will need to compare that against the map of genres (also stored as string) in each NodeHeap/game)
 * - print specific game by TITLE
 * ^^ omg guys i think search by title will actually be like O(n) TC :sob:
 */

// template for each game NodeHeap
    struct NodeHeap {
        std::string name;
        std::string url;
        std::string year;
        std::string cert;
        float rating; // OUR KEY!!!
        std::string votes;
        std::string plot;
        std::map<std::string, bool> genres;

        // ok we need to add a constructor for the node as well

        NodeHeap() = default;
    };

class Heap {

public:
    Heap() = default; // default heap, to be filled later
    Heap(std::vector<NodeHeap> gamesHeap); // constructor
    void buildHeap(); // build heap, will call all the subfuncts
    //void insert (NodeHeap game);
    // insert has been phased out and everything's just done in the constructor and buildHeap now, since like. the heap will never change, it'll always be the same CSV. also the geeksforgeeks example used an array, and the insert function was mostly just about resizing the array, which we don't need to do, because we're using vectors!!!
    void printTop10(); // print top 10
    void printGenreTop10(std::string genreFind); // print top 10 by genre
    void findGame(std::string title); // find game by title


private:
    std::vector<NodeHeap> gamesHeap; // vector that stores games
    void heapify(int key); // heapify
    //void insertGame OOPS this will be handled in setup as set up by Anna, we will just call the constructor with the games vector
    bool compareGames(const NodeHeap& game1, const NodeHeap& game2); // compare two games

    void printGame(const NodeHeap& game); // strucutre used to print a game
};