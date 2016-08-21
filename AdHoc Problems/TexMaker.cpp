#include <iostream>
using namespace std;
void main(void){
	char s[100000];
	int count = 1;
	while (gets_s(s)){
		int i = 0;
		while (s[i] != '\0'){
			if (s[i] == '"' && (count & 1)){
				count++;
				printf("``");
			}
			else if (s[i] == '"' && !(count & 1)){
				count++;
				printf("''");
			}
			else{
				printf("%c", s[i]);
			}
			i++;
		}
		printf("\n");
	}
}