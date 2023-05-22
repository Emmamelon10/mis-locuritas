#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#define color SetConsoleTextAttribute
using namespace std;
HANDLE hconsole = GetStdHandle( STD_OUTPUT_HANDLE );

int i;

main () {
	do
	{
		i++;
  		color(hconsole,i);
  		printf("%d\n\n",i);
		sleep(1);		
	}
	while(i>0);
}
