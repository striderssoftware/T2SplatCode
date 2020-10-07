/*
/ This is code to determine the next frequency 
/ for the next note in the western tonal system.
/ this starts at a = 440 and provides frequencies for
/ the next 7 notes.
*/


#include <iostream>
#include <complex>

using namespace std;

int main()
{
  cout << "test" << endl;

  complex<double> base = 440;
  complex<double> a = 1.0594;    // (2)^1/12
  complex<double> halfSteps = 0;
  complex<double> answer;
  
  for ( int i= 1; i < 7; i++ )
    {
      if ( i != 2 && i != 5 )
	halfSteps += 2;
      else
	halfSteps += 1;

      //cout << halfSteps;
      answer = base * pow(a,halfSteps); 
            
      cout << "here is a note freq:" << endl;
      cout << answer << endl;
    }
}
