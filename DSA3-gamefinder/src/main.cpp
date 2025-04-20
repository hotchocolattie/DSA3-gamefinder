#include "SetUp.h"
#include "Heap.h"
#include <iostream>
using namespace std;


void print_menu(){
  cout<<"\nWELCOME TO GAMEFINDERS!!"<<endl;
  cout<<endl;
  cout<<"--------------MENU---------------"<<endl;
  cout<<"1. Get the top 10 best rated games"<<endl;
  cout<<"2. Get the top 10 best rated games in a genre"<<endl;
  cout<<"3. Search a game by name"<<endl;
  cout<<"4. I'm done!!"<<endl << "\n";
  cout<<"Make your choice: " <<endl;
}

int main(){


    RedBlackTree tree;
    Heap heap;

    bool game_is_open = true;
    loadData(tree, heap);
    int choice;
    while (game_is_open){
      print_menu();
      cin>>choice;

      if (choice == 1){
        cout<<"What data structure do you want to use for your search?"<<endl;
        cout<<"1. Red Black Tree"<<"   "<<"2. Heap"<<endl;
        int structure;
        cin>>structure;

          cout << "\n" << endl;

        if (structure == 1){
            tree.findTopTen();
        }
        else if (structure == 2){
          // call the function that returns the top 10 games with a heap.
            heap.printTop10();
        }

      }
      else if (choice == 2){
        cout<<"What data structure do you want to use for your search?"<<endl;
        cout<<"1. Red Black Tree"<<"   "<<"2. Heap"<<endl;
        int structure;
        cin>>structure;

          // AMF: will most likely refactor

          cout << "Please enter a number for genre: " << endl;
          cout << "1. Action" << endl;
          cout << "2. Adventure " << endl;
          cout << "3. Comedy" << endl;
          cout << "4. Crime" << endl;
          cout << "5. Family" << endl;
          cout << "6. Fantasy" << endl;
          cout << "7. Mystery" << endl;
          cout << "8. Sci-Fi" << endl;
          cout << "9. Thriller" << endl;

          int genre;
          cin >> genre;

          cout << "\n" << endl;
        if (structure == 1){

            if (genre == 1) {
                tree.findTopTenGenre("action");
            }
            else if (genre == 2) {
                tree.findTopTenGenre("adventure");
            }
            else if (genre == 3) {
                tree.findTopTenGenre("comedy");
            }
            else if (genre == 4) {
                tree.findTopTenGenre("crime");
            }
            else if (genre == 5) {
                tree.findTopTenGenre("family");
            }
            else if (genre == 6) {
                tree.findTopTenGenre("fantasy");
            }
            else if (genre == 7) {
                tree.findTopTenGenre("mystery");
            }
            else if (genre == 8) {
                tree.findTopTenGenre("scifi");
            }
            else if (genre == 9) {
                tree.findTopTenGenre("thriller");
            }
            else {
                cout << "Please pick a valid number!\n\n" << endl;
            }

        }
        else if (structure == 2){
          // call the function that returns the top 10 games with a heap in a genre.

            if (genre == 1) {
                heap.printGenreTop10("Action");
            }
            else if (genre == 2) {
                heap.printGenreTop10("Adventure");
            }
            else if (genre == 3) {
                heap.printGenreTop10("Comedy");
            }
            else if (genre == 4) {
                heap.printGenreTop10("Crime");
            }
            else if (genre == 5) {
                heap.printGenreTop10("Family");
            }
            else if (genre == 6) {
                heap.printGenreTop10("Fantasy");
            }
            else if (genre == 7) {
                heap.printGenreTop10("Mystery");
            }
            else if (genre == 8) {
                heap.printGenreTop10("Scifi");
            }
            else if (genre == 9) {
                heap.printGenreTop10("Thriller");
            }
            else {
                cout << "Please pick a valid number!\n\n" << endl;
            }
        }


      }
      else if (choice == 3){

        cout<<"What data structure do you want to use for your search?"<<endl;
        cout<<"1. Red Black Tree"<<"   "<<"2. Heap"<<endl;
        int structure;
        cin>>structure;

          string game;
          cout << "Please enter game title: " << endl;
          cin.ignore();
          getline(cin, game);

          cout << "\n" << endl;

        if (structure == 1){
            tree.findGame(game);

        }
        else if (structure == 2){
          // call the function that returns the top 10 games with a heap.
            // WILL DO SOON!!
            heap.findGame(game);
        }


      }
      else if (choice == 4){
          cout << "Thank you for using GAMEFINDERS!" << endl;
        exit(0);
        game_is_open = false;
      } else {
          cout << "Please pick a valid choice!\n\n" << endl;
      }
    }
}

