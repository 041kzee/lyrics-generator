#include <iostream>
#include <ctime>  
using namespace std;

class Song {
private:
    string title;
    int lineCount;
    string lyrics[50];
    int delays[50]; 
    string singer ;
    string date;
    string songWriter;
    string album;
    string genre;

 
    void delaySeconds(int seconds) {
        clock_t start_time = clock();
        while (clock() < start_time + seconds * CLOCKS_PER_SEC);
    }

    
    void typeWritereffect(const string& line, double speed = 0.5) { 
        for (char c : line) {
            cout << c << flush;
            clock_t start_time = clock();
            while (clock() < start_time + speed * CLOCKS_PER_SEC);
        }
        cout << endl;
    }

public:
    Song(string name) {
        title = name;
        lineCount = 0;
    }

    void addLine(string text, int delay) {
        lyrics[lineCount] = text;
        delays[lineCount] = delay;
        lineCount++;
    }

    void play() {
        cout << "\nNow Playing:  " << title << " \n" << endl;
         cout<<"\nSinger:"<<singer;
        cout<<"\nDate of Release:"<<date;
        cout<<"\nLyricist :"<<songWriter;
        cout<<"\nAlbum:"<<album;
        cout<<"\nGenre:"<<genre<<"\n"<<endl;
    

        for (int i = 0; i < lineCount; i++) {
            delaySeconds(delays[i]);  
            typeWritereffect(lyrics[i], 0.09); 
        }
       
    
        cout << "\n --- End of Song --- " << endl;
    }

    void addDetails(string name, string d, string writer , string alb , string gen){
        singer = name;
        date = d;
       songWriter = writer;
       album = alb;
       genre = gen;

    }
};

int main() {
    cout<<"-----Lyrics Generator-----";
    cout<<"\n so that you dont have to search for song lyrics anymore!";
    Song s1("What Makes You Beautiful"); //constructor called
     cout<<"\n";
    s1.addLine("You're Insecure, Don't know what for", 3);//member function put each of the line as one element of the array
    s1.addLine("Your turning heads when you walk through the door ", 2);
    s1.addLine("Don't need makeup to cover up", 2);//keep more delay if the next line is lengthy

    s1.addLine("Being the way that you are is Enough",2);
    s1.addLine("Everyone else in the room can see it",1.8);
    s1.addLine("Everyone else but YOU",1.8);
    s1.addLine("Babyy you light up my world like nobody else",1.8);
    s1.addLine("The way that you flip your hair gets me overwhelmed",1.8);
    s1.addLine("But when you smile at the ground",0.3);
    s1.addLine("It ain't hard to tell",0.1);
    s1.addLine("You don't know , OH , OH",1.5);
    s1.addLine("THATS WHAT MAKES YOU BEAUTIFUL <3",1);
    s1.addDetails("One Direction", "September 11 2011","Savan Kotecha" , "Up All Night","Teen Pop");
    s1.play();
    return 0;
}
