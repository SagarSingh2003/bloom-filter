#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Hash 1
int h1(const char *s, int arrSize)
{
    int hash = 0;
    for (int i = 0; i < strlen(s); i++) {
        hash = (hash + (int)s[i]) % arrSize;
    }
    return hash;
}


bool lookup(int* bitArray , int arrSize , const char *s)
{
    int pos = h1(s , arrSize);

    if(bitArray[pos] == 1) {
        return true;
    } else {
        return false;
    }
}

void insert(int* bitArray , int arrSize , const char*s)
{

    int pos = h1(s , arrSize);
    if(lookup(bitArray , arrSize , s)) {
        return ;
    } else {

        bitArray[pos] = 1;
    }
}

int main()
{
    int bitArray[100] = { 0 };
    int arrSize = 100;

    const char *sarray[36] = {
        "abound",   "abounds",       "abundance",
        "abundant", "accessible",    "bloom",
        "blossom",  "bolster",       "bonny",
        "bonus",    "bonuses",       "coherent",
        "cohesive", "colorful",      "comely",
        "comfort",  "gems",          "generosity",
        "generous", "generously",    "genial",
        "bluff",    "cheater",       "hate",
        "war",      "humanity",      "racism",
        "hurt",     "nuke",          "gloomy",
        "facebook", "geeksforgeeks", "twitter", "diptilal" , "masadursk", "sagar"
    };

    for(int i = 0 ; i < 36 ; i++) {
        insert(bitArray , arrSize , sarray[i] );
    }

    printf("lookup sagar: %B\n " , lookup(bitArray , arrSize , "ragas" ));
    printf("lookup masadur sk: %B\n" , lookup(bitArray , arrSize , "masadursk"));
    printf("lookup diptilal: %B\n\n\n\n" , lookup(bitArray , arrSize , "diptilal"));

}