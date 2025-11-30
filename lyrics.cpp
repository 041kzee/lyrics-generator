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

       cout << "\n\n"; 

    Song s2("Perfect");
    s2.addLine("I found a love for me", 2);
    s2.addLine("Darling just dive right in and follow my lead", 3);
    s2.addLine("Well I found a girl, beautiful and sweet", 2);
    s2.addLine("I never knew you were the someone waiting for me", 3);

    s2.addLine("Cause we were just kids when we fell in love", 2);
    s2.addLine("Not knowing what it was", 1);
    s2.addLine("I will not give you up this time", 2);
    s2.addLine("Darling just kiss me slow, your heart is all I own", 3);
    s2.addLine("And in your eyes you're holding mine", 2);

    s2.addLine("Baby, I'm dancing in the dark", 2);
    s2.addLine("With you between my arms", 2);
    s2.addLine("Barefoot on the grass", 1);
    s2.addLine("Listening to our favorite song", 2);
    s2.addLine("When you said you looked a mess", 2);
    s2.addLine("I whispered underneath my breath", 1);
    s2.addLine("But you heard it, darling", 1);
    s2.addLine("You look perfect tonight", 3);

    s2.addDetails("Ed Sheeran", "March 3 2017", "Ed Sheeran", "÷ (Divide)", "Pop");
    s2.play();


    return 0;
}
