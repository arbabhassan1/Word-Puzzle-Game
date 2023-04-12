/*
             World Puzzle Game
             Semester Project

                Group No 6
                
Name:-                  Roll NO:
Arbab Hassan            21011556-184
Muhammad Amir           21011556-145
Muhammad Anas           21011556-187
Abdullah Aazam          21011556-171
Zain Ali                21011556-186

                      Word Puzzle Game
            Srearch Words from randomly Generated Alphabet
            
*/


#include<iostream>
#include<cstdlib>
#include<cstring>
#include<windows.h>
#include"conio.h"
using namespace std;
class Puzzle{
	
	private:
	 char a;
      char n;
       string Name;
        int score;
        public:                                     // Public Member Functions of Class Puzzle
        
		//Function to get Name of Player and Process the game call function to Run Game
		
		
		void data(){
             cout<<"Enter name  :       ";
              getline(cin,Name);
     cout<<endl;
score=0;
      do                                     //using do While Loop to run loop At-lest  one time must
     {
     	system("cls");
     	display(); 	
        score=score+call();
        cout<<"Do you want to play again y/n   :   ";
        cin>>n;
        cout<<endl;
     }while(n!='n');
     cout<<Name<<"  ";
     cout<<"your score is   :   "<<score<<endl;
     cout<<"\n\t\t\t\tTHANK YOU\n\n";
     cout<<"\n\t*********************************************************************\n\n"<<endl;
          }


// Function to Randomly Generated Alphabets block of 10x10  
// it also include Dictionary words in the Alphabets block


          int call()
{
	int exit_code=10;

    string hint;
    string output;
    string a[10]={"facebook","html","python",
					"java","coding","keyboard","mouse","kotlin"
							,"swift","samsung"};
							HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);     // Handel Console to change Text Colour
    char arr[10][10];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            char c;
            int r;
            r= rand() % 26;   // generate a random number
            c= 'a' + r;            // Convert to a character from a-z
            arr[i][j]=c;
        }
    }
    int index=rand()%10;
    output=a[index];
    if(a[index].length()%2==0)
    {
        // for even string length case
            int row=rand()%10;
            int col=rand()%3;
            for(int i=0;a[index][i]!='\0';i++,col++)
            {
                arr[row][col]=a[index][i];
            }
        
    }
    else
    {
        // for odd string length case
                // for even string length case
            int row=rand()%3;
            int col=rand()%10;
            for(int i=0;a[index][i]!='\0';i++,row++)
            {
                arr[row][col]=a[index][i];
            }
    }
     for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {SetConsoleTextAttribute(console, j+1); 
          cout<<" "<<arr[i][j];
          Sleep(60);
        }
        cout<<endl;
    }
    SetConsoleTextAttribute(console, 15);      // Change the colour of Console Text
    string guess;
	cout<<"Press 1 for Guess number	"<<endl;
	cout<<"Press 2 for see Hint and then guess number	"<<endl;
	
	cout<<"Enter input		:	";
	cin>>hint;
	cout<<endl;
	if(hint=="1")
	{
	}
       else if(hint=="2")
       {
       cout<<"Guessed word in puzzle size is  :       ";
       cout<<output.size();
       cout<<endl;
       }
       else
       {
    	cout<<"Invalid input	";
    	Beep(200,800);
    	Sleep(1000);
    	//data();
    //	return 2;
    cout<<"	\n\n\t\tALAS! Restart the Game\n";
    	_Exit(exit_code);

	}
    cout<<"\nEnter word you guess         :       ";
    cin>>guess;
    cout<<endl;
    if(guess==a[index])
    {
        cout<<"Congratulations ! You have guessed correct word  "<<endl;
        return 1;
       
    }
    else
    {
        cout<<"Sorry ! Your guessed word is incorrect.Please Try again "<<endl;
        Beep(200,800);                   // System Beep a Sound if enter wrong word
        return 0;
    }
}


// Funcction to Display Instruction of game


        void display(){
	    cout<<"\n\t\t**********************************Word Gussing Game*********************************************\n\n"<<endl;
   cout<<"Instructions:"<<endl;
    cout<<"You have to guess the word in this puzzle"<<endl;
    cout<<"For example word in this puzzle can be Tech world (c++,Node.js,twitter etc )"<<endl;
    cout<<"If you guess Wrong word System will Beep a Sound"<<endl;
    cout<<"You can also take help for hint from the system"<<endl<<endl;
    
}

//Function to Display Loading Animation

void loading(){
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    cout<<"\n\n\n\n\n\n\n";
SetConsoleTextAttribute(console, 15); 
    cout<<"\t\t\t\tLoading\n\n\n";
    for(int i=0;i<80;i++)
{    cout<<"*";
Sleep(30);

}
cout<<"\n\n\t\t\t\tLoading Completed\n\n";
Sleep(1200);
system("cls");
}

             //Function to Display Splash Screen of Game

void intro(){
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(console, 14); 
  cout<<"\n\n\t\t\t\t\t\tWellCome to PUZZLE Game\n\n";
   SetConsoleTextAttribute(console, 7); 
  cout<<"\t\t\t\t\t    Guess The Words and earn points\n\n\n";
  cout<<"\t\t\t\t        Submitted to:       Maam Maryam Ehsan\n\n\n";
    cout<<"\t\t\t\t    \t\t    Students Name    \n\n";



 SetConsoleTextAttribute(console, 6); 
  cout<<"\t\tArbab Hassan";
  
  cout<<"\tMuhammad Amir";

  cout<<"\tZain Ali";

  cout<<"\tMuhammad Anas";

  cout<<"\tAbdullah Azam\n";
  SetConsoleTextAttribute(console, 7); 
  cout<<"\n \t\t\t\t\t Press Enter to Start Game\n";
  
  int a;
  a=getch();
  
  system("cls");
  }



};

// Main Function
        int main(){

            Puzzle a;
            a.intro();
            a.loading();
            a.data();
        }
/*
                          Arbab Hassan
               Department of Information Technology
                     University of Gujrat
                    21011556-184@uog.edu.pk
*/