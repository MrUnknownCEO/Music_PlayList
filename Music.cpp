#include "Music.h"
#include <iostream>
#include <limits>
#include <string>
//#include <conio.h>
#include <chrono>
#include <thread>

using namespace std;

//Music Class
Music::Music(string id, string title, string artist, string duration, string album) {
    ID = id;
    Title = title;
    Artist = artist;
    Duration = duration;
    Album = album;
}

//set functions
//set Music ID
void Music::setID(string id) {
    ID = id;
}

//set Music Title
void Music::setTitle(string title) {
    Title = title;
}

//set Music Author/artist
void Music::setArtist(string artist) {
    Artist = artist;
}

//set Music time duration
void Music::setDuration(string duration) {
    Duration = duration;
}

//set Album name if it came form an album
void Music::setAlbum(string album) {
    Album = album;
}

//get functions
//get ID number
string Music::getID() {
    return ID;
}

//get Title name
string Music::getTitle() {
    return Title;
}

//get artist name
string Music::getArtist() {
    return Artist;
}

//get duration time
string Music::getDuration() {
    return Duration;
}

//get Album name if exists
string Music::getAlbum() {
    return Album;
}


//DoublyLinkedList Class
DoublyLinkedList::DoublyLinkedList() {
    Head = NULL;
}

//doubly linked list destructor
DoublyLinkedList::~DoublyLinkedList() {
    while(Head != nullptr) {
        Node* temp = Head;
        Head = Head->next;
        delete temp;

        if(Head != nullptr) {
            Head->prev = nullptr;
        }
    }
}

//function to add a music track to the playlist
void DoublyLinkedList::Add_MusicTrack() {
    //declare our variables
    string id, music_title, artist_name, song_duration;
    string album_name = "NONE";

    //get user input
    cout<<"Enter ID for new song: ";
    cin>>id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Enter song title!: ";
    getline(cin, music_title);
    cout<<"Enter artist's Name: ";
    getline(cin, artist_name);
    cout<<"Enter songs Time duration eg(3:00 mins): ";
    getline(cin, song_duration);
    cout<<"Enter Album name if it exists(if None type(None)): ";
    getline(cin, album_name);

    //create Music object for the input
    Music newSong(id, music_title, artist_name, song_duration, album_name);

    //create node for the new track
    Node* newnode = new Node(newSong);
    //check if linked list is empty
    if(Head == NULL) {
        Head = newnode;
        return;
    }

    //traverse list to find the last node
    Node* currentnode = Head;
    while(currentnode->next != NULL) {
        currentnode = currentnode->next;
    }

    //update pointer to insert node at the end
    currentnode->next = newnode;//set our last node to point to our newnode
    newnode->prev = currentnode;//set our newnode's prev to point to the last node
    newnode->next = NULL;//set our newnode's next to NULL

}

//function to remove a song from the Play List
void DoublyLinkedList::Remove_MusicTrack() {
    //display the list
    cout<<"Play List: "<<endl;

    DisplayList();

    cout<<endl;


    //set nodes so we can traverse and find the node to delete
    //using the Music Id to locate it and delete it
    if(Head == NULL) {
        cout<<"Play List is empty! "<<endl;
        return;
    }

    //then ask user to enter ID of song
    cout<<"***********************************************************************"<<endl;
    cout<<"Plays list Displayed Above choose, which to delete based on Song ID!"<<endl;
    string Id_delete;
    cout<<"Enter ID of song you want to remove of the Play List: ";
    cin.ignore();
    getline(cin, Id_delete);


    //if the ID is the head node
    if(Head->data.getID() == Id_delete) {
        Node* temp = Head;
        Head = Head->next;
        if(Head != NULL) {
            Head->prev = NULL;
        }
        delete temp;
        cout<<"Song with ID "<<Id_delete<<" has been removed."<<endl;
        return;
    }

    Node* previous = Head;
    Node* current = Head->next;

    //traverse Plays list to find song with matching ID
    while(current != NULL) {
        if(current->data.getID() == Id_delete) {
            previous->next = current->next;
            if(current->next != NULL) {
                current->next->prev = previous;
                delete current;
                cout<<"Song with ID "<<Id_delete<<" has been removed."<<endl;
            }
            return;
        }
        previous = current;
        current = current->next;
    }
}

//function to display the Playlist
void DoublyLinkedList::DisplayList() {
    Node* list = Head;

    //check if the Play list has Data
    if(list == NULL) {
        cout<<"No songs in Playlist!"<<endl;
        return;
    }
    //display the list and with its information
    while(list != NULL) {
        cout<<"Song ID: "<<list->data.getID()<<", ";
        cout<<"Song Name: "<<list->data.getTitle()<<", ";
        cout<<"Artist Name: "<<list->data.getArtist()<<", ";
        cout<<"Time Duration: "<<list->data.getDuration()<<", ";
        cout<<"Album Name: "<<list->data.getAlbum()<<", ";

        cout<<endl;
        list = list->next;
    }

}

//function to play the playlist
void DoublyLinkedList::Play() {
    Node* song = Head;
    //int user_response;

    //check if the Play list has Data
    if(song == NULL) {
        cout<<"No song in Playlist!"<<endl;
        return;
    }


    int user_response;
    //display the list and with its information
    while(true/*user_response != 0*/) {
        //clear the console
        system("cls");


        //Display song info
        cout<<"****************************************************"<<endl;
        cout<<"* Song ID: "<<song->data.getID()<<endl;
        cout<<"* Song Name: "<<song->data.getTitle()<<endl;
        cout<<"* Artist Name: "<<song->data.getArtist()<<endl;
        cout<<"* Time Duration: "<<song->data.getDuration()<<endl;
        cout<<"* Album Name: "<<song->data.getAlbum()<<endl;
        cout<<"****************************************************"<<endl;


        cout<<endl;
        cout<<endl;

        //give user the options
        cout<<"*********************************************"<<endl;
        cout<<"*Prev Song, Enter 1! || Next Song, Enter 2! *"<<endl;
        cout<<"*********************************************"<<endl;
        //cout<<"Next Song, Press 2!"<<endl;
        cout<<"To Exit, Enter 0!"<<endl;


        //get user input
        cin>>user_response;


        switch (user_response) {
        case 1: if(song->prev != NULL) {
                song = song->prev;
            }else {
                cout<<"No song!"<<endl;
            }
            break;
        case 2: if(song->next != NULL) {
                song = song->next;
            }else {
                cout<<"No song"<<endl;
            }
            break;
        case 0:
            return;
        default:
            cout << "Invalid input. Please try again." << endl;
            break;
        }
        this_thread::sleep_for(chrono::seconds(1));
    }

}

