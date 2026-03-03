// ## PROGRAM - 02 
// 2. Design, Develop and Implement a Program in C for the following operations on Strings 
// a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP) 
// b. Perform Pattern Matching Operation: 
// Find and Replace all occurrences of PAT in STR with REP if PAT exists in STR. 
// Report suitable messages in case PAT does not exist in STR. 
// Support the program with functions for each of the above operations. 
// Don't use Built-in functions.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char inpStr[100], searchPtr[100],  replaceStr[100], ansStr[100];
    int i=0,j=0,k=0,found=0,match=0;
    int patLen = 0;

    printf("Enter the String: ");
    fgets(inpStr,sizeof(inpStr),stdin);

    printf("Enter the Pattern To search String: ");
    fgets(searchPtr,sizeof(searchPtr),stdin);

    printf("Enter the Replace String: ");
    fgets(replaceStr,sizeof(replaceStr),stdin);

    patLen = strlen(searchPtr);
    while(inpStr[i] != '\0'){

        match = 1;

        for( j=0; searchPtr[j] != '\n' && searchPtr[j] != '\0'; j++ ){
            if (searchPtr[j] != inpStr[i + j]){
                match = 0;
                break;
            }
        }

        if(match){
            found = 1;
            for(j=0; replaceStr[j] != '\n' && replaceStr[j] != '\0'; j++){
                ansStr[k++] = replaceStr[j];
            }
            i+=(patLen-1);
        }else{
            ansStr[k++] = inpStr[i++];
        }

    }

    ansStr[k] = '\0';

    if (!found) {
        printf("\nPattern not found.\n");
        printf("Original string: %s", inpStr);
        return 0;
    }

    printf("\nResult: %s", ansStr);

    return 0;
}

// ### Output

// Enter the String: Today is Thrusday     
// Enter the Pattern To search String: Thrusday
// Enter the Replace String: Saturday

// Result: Today is Saturday

// ### Output 2

// Enter the String: Today is Wednesday
// Enter the Pattern To search String: pop
// Enter the Replace String: monday

// Pattern not found.
// Original string: Today is Wednesday