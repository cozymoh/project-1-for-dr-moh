#include <iostream>
#include <string>
using namespace std;

const int edge=20; //more than enough dont tell me why its not dynamic 

struct song{
string title;
string artist;
};

song playlist[edge]={//its now 5 and different to show off the sorting better it was awful with 3 
{"Beat It","Michael Jackson"},
{"Dynamite","BTS"},
{"Cest la vie","Khaled"},
{"It was a good day","Ice cube"},
{"New jeans","Jiandro"}
};

int countSongs=5;

void addSong(){//add a new one
if(countSongs>=edge){
cout<<"Playlist full\n";//if the songs hit 20 it will say playlist full useles feature but whatever adds more lines
return;
}

string t,ar;

cin.ignore(1000,'\n'); //this removes the extra space from the cin cus getline suicides if theres a space at the end

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

void deleteSong(){//delete or reduce the amount of songs we have
string n;

cin.ignore(1000,'\n');

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

void updateSong(){//update existing song
int id;

cout<<"Enter ID:";//to see what song u want to update
cin>>id;

if(id<1||id>countSongs){
cout<<"wrong id\n";
return;
}

cin.ignore(1000,'\n');

cout<<"Enter new title:";
getline(cin,playlist[id-1].title);// id - 1 cus we pic the song id from 1 to 20 and the index starts from 0 so -1 to equal the index

cout<<"Enter new artist:";
getline(cin,playlist[id-1].artist);

cout<<"Updated\n";
}

void sortSongs(){//sort songs from A to Z
    cout<<"\nnote that the sorting is done as the following special symbols then numbers then letters.";//ASCII
for(int i=0;i<countSongs-1;i++){

for(int j=0;j<countSongs-i-1;j++){

if(playlist[j].title>playlist[j+1].title){

song temp=playlist[j];
playlist[j]=playlist[j+1];
playlist[j+1]=temp;

}
}
}

cout<<"Songs sorted A-Z\n";
}

int main(){
int c;

for(;;){
cout<<"\n [play list] \n";
cout<<" input the number next to the action you are willing to take.\n";

cout<<"\n1 add song";
cout<<"\n2 show songs";
cout<<"\n3 search a song by ID";
cout<<"\n4 delete a song";
cout<<"\n5 update a song";
cout<<"\n6 sort A-Z";
cout<<"\n0 exit\n";

cin>>c;

if(c==1)addSong();
else if(c==2)showSongs();
else if(c==3)searchid();
else if(c==4)deleteSong();
else if(c==5)updateSong();
else if(c==6)sortSongs();
else if(c==0){
cout<<"full mark for sure\n";
break;
}
else{
cout<<"enter a valid option pls\n";
}
}
}
