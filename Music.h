#ifndef MUSIC_H
#define MUSIC_H
#include<string>
#include <iostream>
using namespace std;

class Music
{
private:
    //data memebers(music track data for Node)
    string ID;
    string Title;
    string Artist;
    string Duration;
    string Album;

public:
    //constructor
    Music(string id = "", string title = "", string artist = "", string = "", string = "");

    //set functions
    void setID(string id);
    void setTitle(string title);
    void setArtist(string artist);
    void setDuration(string duration);
    void setAlbum(string album);

    //get functions
    string getID();
    string getTitle();
    string getArtist();
    string getDuration();
    string getAlbum();
};

//second class for the doubly linked list
class DoublyLinkedList {
private:
    class Node{
        Music data;
        Node* next;
        Node* prev;

        //constructor for the node to take in a Music_track object
        //and also set next to null as well as prev
        Node(const Music& _data) {
            data = _data;
            next = NULL;
            prev = NULL;
        }

        //allows us to access private member of the node class
        friend DoublyLinkedList;
    };

    Node* Head;
public:
    //constructor
    DoublyLinkedList();

    //destructor
    ~DoublyLinkedList();

    //member functions
    void Add_MusicTrack(); //Add a track at end of list
    void Remove_MusicTrack();//Remove a track based on id
    void DisplayList();//Display the list of the track
    void Play();//play the track and then go either left for previous track or right for next track
};

#endif // MUSIC_H
