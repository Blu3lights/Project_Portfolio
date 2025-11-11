/******************************************************************************
Static Local Variable Example
*******************************************************************************/
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

// function prototype
void showStatic();

int main()
{
   
// call the showStatic function 5 times 
for(int count =0; count < 2; count++)
showStatic();

    return 0;
} // end main 

// function 
void showStatic() {
    static int numCalls = 0; // static local Variable
    
    cout << "This function has been called " << ++numCalls << " times. " << endl;
    
}

