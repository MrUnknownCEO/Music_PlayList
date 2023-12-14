/*Author: MrUnknown*/
#include "Music.h"
#include "limits"
#include <iostream>
//#include <string>

using namespace  std;

void showMenu() {
    system("cls");
    cout<<"*****************************************\n";
    cout<<"* Press 1 to Add Song to Play List      *\n";
    cout<<"* Press 2 to Remove Song from Play List *\n";
    cout<<"* Press 3 to Display Play List          *\n";
    cout<<"* Press 4 to Play Muisc List            *\n";
    cout<<"* Press 5 to Quit                       *\n";
    cout<<"*****************************************\n";
    cout<<"=====>";
}

int GetResponse() {
    int response;
    showMenu();
    cin>>response;

    while(response < 1 || response > 5) {
        showMenu();
        cin>>response;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return response;
}

int main()
{
    int response;
    //object of class goes here
    DoublyLinkedList musicPlayList;

    while((response = GetResponse()) !=  5) {
        switch(response) {
        case 1: musicPlayList.Add_MusicTrack();
            break;
        case 2: musicPlayList.Remove_MusicTrack();
            break;
        case 3: musicPlayList.DisplayList();
            break;
        case 4: musicPlayList.Play();
            break;
        }
         system("pause");
    }


    cout<<"Thank You for Listening!"<<endl;
    return 0;
}
