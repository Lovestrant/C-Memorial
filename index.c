/* Your Name and G Number
   CS 262, Lab Section <lab section>
   Lab 5
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 20
#define WSIZE 50

void get_animal(char letter, char animal[]);
void get_verb(char month[], char verb[]);
void get_adjective(int digit, char adjective[]);

int main() {
    // declare variables, all of them
    char animal[SIZE], verb[SIZE], adjective[SIZE], sentence[WSIZE], lname;
    char month[4], cell_digit, quit;

    // prompt the user for the first letter of their last name
    do {
        printf("Enter the first letter of your last name [A-Z]: ");
        scanf(" %c", &lname);
        lname = toupper(lname);
        if (lname < 'A' || lname > 'Z') {
            printf("Error: Invalid entry, please try again.\n");
            continue;
        }
        break;
    } while (1);

    // Ask the user for their birth month
    do {
        printf("Enter your birth month [JAN|FEB|...|DEC]: ");
        scanf(" %s", month);
        month[0] = toupper(month[0]);
        month[1] = toupper(month[1]);
        month[2] = toupper(month[2]);
        if (strcmp(month, "JAN") && strcmp(month, "FEB") && strcmp(month, "MAR") &&
            strcmp(month, "APR") && strcmp(month, "MAY") && strcmp(month, "JUN") &&
            strcmp(month, "JUL") && strcmp(month, "AUG") && strcmp(month, "SEP") &&
            strcmp(month, "OCT") && strcmp(month, "NOV") && strcmp(month, "DEC")) {
            printf("Error: Invalid entry, please try again.\n");
            continue;
        }
        break;
    } while (1);

    // prompt user for the last digit of their cellphone number
    do {
        printf("Enter the last digit of your cellphone [0-9]: ");
        scanf(" %c", &cell_digit);
        if (cell_digit < '0' || cell_digit > '9') {
            printf("Error: Invalid entry, please try again.\n");
            continue;
        }
        break;
    } while (1);

    // get the animal, verb, and adjective based on the user's inputs
    get_animal(lname, animal);
    get_verb(month, verb);
    get_adjective(cell_digit - '0', adjective);

    // construct the sentence
    strcpy(sentence, "Your spirit animal is ");
    strcat(sentence, animal);
    strcat(sentence, ", which ");
    strcat(sentence, verb);
    strcat(sentence, " ");
    strcat(sentence, adjective);
    strcat(sentence, ".");

    // print the sentence
    printf("%s\n", sentence);

    // ask the user if they want to quit or start over
    do {
        printf("Do you want to quit [Y|y]? ");
        scanf(" %c", &quit);
        if (quit == 'Y' || quit == 'y') {
            break;
        }
        else {
            printf("\n");
            main();
        }
    } while (1);

    return 0;
}
// This function takes a letter and an empty array to store the animal name.
void get_animal(char letter, char animal[]) {

    // Use a switch statement to determine which animal to return based on the letter input.
    switch(letter) {

        // If the letter is 'A', 'B', 'C', 'D', or 'E', set animal to "the macaw".
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
            strcpy(animal, "the macaw");
            break;

        // If the letter is 'F', 'G', 'H', 'I', or 'J', set animal to "the penguin".
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
            strcpy(animal, "the penguin");
            break;

        // If the letter is 'K', 'L', 'M', 'N', or 'O', set animal to "the emu".
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
            strcpy(animal, "the emu");
            break;

        // If the letter is 'P', 'Q', 'R', 'S', or 'T', set animal to "the aardvark".
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
            strcpy(animal, "the aardvark");
            break;

        // If the letter is 'U', 'V', 'W', 'X', 'Y', or 'Z', set animal to "the shiba inu".
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            strcpy(animal, "the shiba inu");
            break;

        // If the letter is not one of the expected letters, print an error message.
        default:
            printf("Error: Invalid letter. Please enter a letter from A-Z.\n");
            break;
    }
}


// This function takes a month abbreviation and returns a verb associated with that month.
// If the month is not recognized, an error message is printed.
void get_verb(char month[], char verb[]) {
    // Check if the month is in the first quarter of the year and assign verb accordingly
    if(strcmp(month, "JAN") == 0 || strcmp(month, "FEB") == 0 || strcmp(month, "MAR") == 0) {
        strcpy(verb, "pranced");
    }
    // Check if the month is in the second quarter of the year and assign verb accordingly
    else if(strcmp(month, "APR") == 0 || strcmp(month, "MAY") == 0 || strcmp(month, "JUN") == 0) {
        strcpy(verb, "swam");
    }
    // Check if the month is in the third quarter of the year and assign verb accordingly
    else if(strcmp(month, "JUL") == 0 || strcmp(month, "AUG") == 0 || strcmp(month, "SEP") == 0) {
        strcpy(verb, "dived");
    }
    // Check if the month is in the fourth quarter of the year and assign verb accordingly
    else if(strcmp(month, "OCT") == 0 || strcmp(month, "NOV") == 0 || strcmp(month, "DEC") == 0) {
        strcpy(verb, "fled");
    }
    // If the month is not recognized, print an error message
    else {
        printf("Error: Invalid month. Please enter a valid month in the format JAN, FEB, ..., DEC.\n");
    }
}

// This function takes an integer digit and populates a character array adjective
// with a corresponding adjective based on the value of the digit.
void get_adjective(int digit, char adjective[]) {
    switch(digit) {
        // If digit is 0 or 1, set the adjective to "remarkably"
        case 0:
        case 1:
            strcpy(adjective, "remarkably");
            break;
        // If digit is 2 or 3, set the adjective to "outlandishly"
        case 2:
        case 3:
            strcpy(adjective, "outlandishly");
            break;
        // If digit is 4 or 5, set the adjective to "dashingly"
        case 4:
        case 5:
            strcpy(adjective, "dashingly");
            break;
        // If digit is 6 or 7, set the adjective to "impressively"
        case 6:
        case 7:
            strcpy(adjective, "impressively");
            break;
        // If digit is 8 or 9, set the adjective to "diabolically"
        case 8:
        case 9:
            strcpy(adjective, "diabolically");
            break;
        // If the digit is invalid, print an error message
        default:
            printf("Error: Invalid digit. Please enter a digit from 0-9.\n");
            break;
    }
}
