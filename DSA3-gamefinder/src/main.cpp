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
  cout<<"4.I'm done!!"<<endl;
  cout<<"Make your choice:"<<endl;
}

int main()
{
    bool game_is_open = true;
    loadData();
    int choice;
    while (game_is_open){
      print_menu();
      cin>>choice;

      if (choice == 1){
        cout<<"How do you want your search to go?"<<endl;
        cout<<"1.Red Black Tree"<<"   "<<"2.Heap"<<endl;
        int structure;
        cin>>structure;
        if (structure == 1){
          // call the function that returns the top 10 games.
        }
        else if (structure == 2){
          // call the function that returns the top 10 games with a heap.
        }
      }
      else if (choice == 2){
        cout<<"How do you want your search to go?"<<endl;
        cout<<"1.Red Black Tree"<<"   "<<"2.Heap"<<endl;
        int structure;
        cin>>structure;
        if (structure == 1){
          // call the function that returns the top 10 games in a genre.
        }
        else if (structure == 2){
          // call the function that returns the top 10 games with a heap in a genre.
        }
      }
      else if (choice == 3){
        cout<<"How do you want your search to go?"<<endl;
        cout<<"1.Red Black Tree"<<"   "<<"2.Heap"<<endl;
        int structure;
        cin>>structure;
        if (structure == 1){
          // call the function that returns the top 10 games.
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

