#include <iostream>
using namespace std;
const int edge=20; //more than enough
struct Song {
string title;
string artist;
};
Song playlist[edge] = {
    {"Beat_It", "Michael_Jackson"},
    {"Billie_Jean", "Michael_Jackson"},
    {"Smooth_Criminal", "Michael_Jackson"}};
 // continue after tea and biscuits
int countSongs=3;
void addSong(){//add a new one
if(countSongs>=edge){
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
cout<<"You already have this song\n";
return;
}
}
playlist[countSongs].title=t;
playlist[countSongs].artist=ar;
countSongs++;
cout<<"Song Added\n";
}
void showSongs(){
for(int i=0;i<countSongs;i++){
cout<<"\nID:"<<i+1<<"\n";
cout<<"Title:"<<playlist[i].title<<"\n";
cout<<"Artist:"<<playlist[i].artist<<"\n";
}
}
void searchByID(){// search for it by id
int id;
cout<<"Enter ID:";
cin>>id;
if(id<1||id>countSongs){
cout<<"unknown ID\n";
return;
}
cout<<"Title:"<<playlist[id-1].title<<"\n";
cout<<"Artist:"<<playlist[id-1].artist<<"\n";
}
void deleteSong(){//delete/remove song
string n;
cout<<"Enter title:";
cin>>n;

for(int i=0;i<countSongs;i++){
if(playlist[i].title==n){

for(int j=i;j<countSongs-1;j++){
playlist[j]=playlist[j+1];
}

countSongs--;
cout<<"deleted\n";
return;
}
}

cout<<"not found\n";
}

int main(){
int c;
// the choose ur action menu is if based
for(;;){
cout<<"\n [play list] \n";cout<<"pls dont leave spaces use _ to separate.\n";
cout<<" input the number next to the action you are willing to take.\n";
cout<<"\n1 add song and its artist\n2 show songs and artist\n3 searchID\n4 delete\n0 exit\n";
cin>>c;

if(c==1)addSong();
else if(c==2)showSongs();
else if(c==3)searchByID();
else if(c==4)deleteSong();
else if(c==0){cout<<"full mark for sure\n";break;}
else cout<<"enter one of the shown options\n";
}
}
