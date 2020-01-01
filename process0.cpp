#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

int main(){
int turn,sha_var,sha_vart,x;
fstream turnRW;
fstream shared;
for(int i=1;i<=3;i++)
{
turnRW.open("turn.txt",ios::in|ios::out);
turnRW>>turn;
//cout<<turn;

turnRW.close();

	
  while(turn!=0){
  
  	turnRW.open("turn.txt",ios::in|ios::out);
turnRW>>turn;
 turnRW.close();
  }
  cout<<"Process 0 is in critical section now!!"<<endl<<endl;
 shared.open("shared.txt",ios::in|ios::out|ios::app);
 	
   ifstream infile; 
   infile.open("shared.txt"); 
   infile >> x; 
   
   infile.close();
  
  
   ofstream outfile;
   outfile.open("shared.txt",ios::trunc);
   cout<<"\tthe Value of shared value received from a file is "<<x<<endl;
   x=x+1;
   cout<<"\tthe Value of shared value incremented to "<<x<<endl<<endl;
   outfile <<x  << endl;
   outfile.close();

 sleep(1);
 turnRW.open ("turn.txt", ios::out | ios::in | ofstream::trunc );

	turn=1;
	cout<<"Process 0 is in critical section now!!"<<endl<<endl;
    turnRW << turn;
    turnRW.close();
    sleep(1);
    
}
return 0;
 

}
