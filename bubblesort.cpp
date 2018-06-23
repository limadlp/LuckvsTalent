#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUBBLE 10
using namespace std;
int main()
{
	int myArray[BUBBLE];
	int i, j;
	int temp = 0;
	int num;
    
	srand(time(NULL));
    
	//fill array
	for (i = 0; i < BUBBLE; i ++)
	{
		   cin >> myArray[i];
	}
   
	
	//sort array
	for(i = 0; i < BUBBLE; i++)
	{

		for (j = 0; j < BUBBLE-1; j++)
        {
            if (myArray[j] > myArray[j+1])
			{
				temp = myArray[j];
				myArray[j] = myArray[j+1];
				myArray[j+1] = temp;
			}
        }/*End inner for loop*/
	}/*End outer for loop*/
  
	
	//print array
	for (i = 0; i < BUBBLE; i++)
	{
		printf("%d\n",myArray[i]);
	}
	
	system("PAUSE");	
	return 0;
}/*End of main*/