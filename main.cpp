#include <iostream>
#include <string>
using namespace std;

const int edge=20; //more than enough dont tell me why its not dynamic 

struct song {
string title;
string artist;
};

song playlist[edge]={
    {"Beat It","Michael Jackson"},
    {"Billie Jean","Michael Jackson"},
    {"Smooth Criminal","Michael Jackson"}
};

int countSongs=3;

void addSong(){//add a new one
if(countSongs>=edge){
cout<<"Playlist full\n";//if the songs hit 20 it will say playlist full
return;
}

string t,ar;

cin.ignore(); //this removes the extra space from the cin cus getline suicides if theres a space at the end (u will ask where i got this from i learned it from dr basim lecture when the students gave a presentation)

cout<<"Enter Title:";//input title
getline(cin,t);

cout<<"Enter Artist:";//input singer
getline(cin,ar);

// checking duplicates
for(int i=0;i<countSongs;i++){
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

void searchid(){// search for it by id
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

void deleteSong(){//delete aka reducing the amount of songs we have
string n;

cin.ignore();

cout<<"enter title:";
getline(cin,n);

for(int i=0;i<countSongs;i++){
if(playlist[i].title==n){

for(int j=i;j<countSongs-1;j++){ //ill explain as i talk 
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

for(;;){
cout<<"\n [play list] \n";
cout<<" input the number next to the action you are willing to take.\n";
cout<<"\n1 add song\n2 show songs\n3 searchID\n4 delete\n0 exit\n";
cin>>c;

if(c==1)addSong();
else if(c==2)showSongs();
else if(c==3)searchid();
else if(c==4)deleteSong();
else if(c==0){cout<<"full mark for sure\n";break;}
else cout<<"enter a valid option pls\n";
}
}
