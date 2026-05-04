#include <iostream>
using namespace std;
const int max=20; //more than enough 
struct Song {
string title;
string artist;
};
Song playlist[max] = {
    {"Beat It", "Michael Jackson"},
    {"Billie Jean", "Michael Jackson"},
    {"Smooth Criminal", "Michael Jackson"}};
 // continue after tea and biscuits 
int countSongs=3;
void addSong(){//add a new one
if(countSongs>=max){
cout<<"Playlist full\n";
return;
}

string t,ar;

cout<<"Enter Title:";
cin>>t;

cout<<"Enter Artist:";
cin>>ar;

for(int i=0;i<countSongs;i++){//checking if song is already there
if(playlist[i].title==t){
cout<<"Duplicate Song!\n";
return;
}
}
playlist[countSongs].title=t;
playlist[countSongs].artist=ar;
countSongs++;
cout<<"Song Added\n";
}
void searchByID(){// search for it by id 
int id;
cout<<"Enter ID:";
cin>>id;
if(id<1||id>countSongs){
cout<<"Invalid ID\n";
return;
}
cout<<"Title:"<<playlist[id-1].title<<"\n";
cout<<"Artist:"<<playlist[id-1].artist<<"\n";
}
