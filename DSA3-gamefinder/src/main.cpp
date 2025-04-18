#include "SetUp.h"
#include <iostream>
using namespace std;


void print_menu(){
  cout<<"WELCOME TO GAMEFINDERS!!"<<endl;
  cout<<endl;
  cout<<"--------------MENU---------------"<<endl;
  cout<<"1.Get the top 10 most popular games"<<endl;
  cout<<"2.Get the top 10 most popular games in a genre"<<endl;
  cout<<"3.Search a game by the name"<<endl;
  cout<<"4.I'm done!!"<<endl << "\n";
  cout<<"Make your choice:"<<endl;
}

int main()
{
    RedBlackTree tree;

    bool game_is_open = true;
    loadData(tree);
    int choice;
    while (game_is_open){
      print_menu();
      cin>>choice;

      if (choice == 1){
        cout << '\n';
        cout<<"How do you want your search to go?"<<endl;
        cout<<"1.Red Black Tree"<<"   "<<"2.Heap"<<endl;
        int structure;
        cin>>structure;
        if (structure == 1){
            tree.findTopTen();
        }
        else if (structure == 2){
          // call the function that returns the top 10 games with a heap.
        }
      }
      else if (choice == 2){
        cout << '\n';
        cout<<"How do you want your search to go?"<<endl;
        cout<<"1.Red Black Tree"<<"   "<<"2.Heap"<<endl;
        int structure;
        cin>>structure;
        if (structure == 1){

            // AMF: will most likely refactor
             
            cout << "\n" << "Please enter a number for genre: " << endl;
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
                cout << "Please pick a valid number!" << endl;
            }

        }
        else if (structure == 2){
          // call the function that returns the top 10 games with a heap in a genre.
        }
      }
      else if (choice == 3){

        cout << '\n';
        cout<<"How do you want your search to go?"<<endl;
        cout<<"1.Red Black Tree"<<"   "<<"2.Heap"<<endl;
        int structure;
        cin>>structure;
        if (structure == 1){
            string game;
            cout << "Please enter game title" << endl;
            cin.ignore();
            getline(cin, game);
            tree.findGame(game);

        }
        else if (structure == 2){
          // call the function that returns the top 10 games with a heap.
        }
      }
      else if (choice == 4){
        exit(0);
        game_is_open = false;
      }
    }

}

