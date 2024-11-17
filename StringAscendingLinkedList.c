#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Long function that assigns a digit to each letter
int alpha_Values(char input)
{
    switch (input)
    {
    case 'a':
    case 'A':
        return 1;
        break;
    case 'b':
    case 'B':
        return 2;
        break;
    case 'c':
    case 'C':
        return 3;
        break;
    case 'd':
    case 'D':
        return 4;
        break;
    case 'e':
    case 'E':
        return 5;
    case 'f':
    case 'F':
        return 6;
        break;
    case 'g':
    case 'G':
        return 7;
        break;
    case 'h':
    case 'H':
        return 8;
        break;
    case 'i':
    case 'I':
        return 9;
        break;
    case 'j':
    case 'J':
        return 10;
        break;
    case 'k':
    case 'K':
        return 11;
        break;
    case 'l':
    case 'L':
        return 12;
        break;
    case 'm':
    case 'M':
        return 13;
        break;
    case 'n':
    case 'N':
        return 14;
        break;
    case 'o':
    case 'O':
        return 15;
        break;
    case 'p':
    case 'P':
        return 16;
        break;
    case 'q':
    case 'Q':
        return 17;
        break;
    case 'r':
    case 'R':
        return 18;
        break;
    case 's':
    case 'S':
        return 19;
        break;
    case 't':
    case 'T':
        return 20;
        break;
    case 'u':
    case 'U':
        return 21;
        break;
    case 'v':
    case 'V':
        return 22;
        break;
    case 'w':
    case 'W':
        return 23;
        break;
    case 'x':
    case 'X':
        return 24;
        break;
    case 'y':
    case 'Y':
        return 25;
        break;
    case 'z':
    case 'Z':
        return 26;
        break;
    default:
        return 69;
        break;
    }
}

//------------------------------------------------------------------------------------------------------------

// creating the data structure of the node, which is used to store the data of the linked list
typedef struct node
{
    char name[99];
    int number_count[99];
    struct node *ptr_next;
} node;
/*
main cuz ofc, using argc argv for ease of input, incase i forget, use ./{name of the program} followed by
the input to use command line arguments, gosh this is bad commenting
make sure to run the program first otherwise nothing is gonna be compiled
*/
int main(int argc, char *argv[])
{
    // initialising the pointer to our linked list without allocating to it any storage, cuz we will do that later
    node *name_list = NULL;

    // for loop to go through the given input in argv
    for (int i = 1; i < argc; i++)
    {
        // too lazy to find the bool library. using an int as true or false
        int incoming_greater = 0;
        // this is to store the length of the shorter text when we are comparing
        int lesser_name_count = 0;

        // creating a temporary list using malloc which allocates memory
        node *temp_list = malloc(sizeof(node));
        // creating a temp array to store the value taken from argv
        char value_Holder[99];
        strcpy(value_Holder, argv[i]);
        strcpy(temp_list->name, argv[i]);
        // this variable is to skip any input thats not an alphabet
        int non_Alpha_count = 0;
        // this here is to translate the text into numbers, for example: abc will be translated to 123, def to 456
        for (int x = 0; x < strlen(argv[i]); x++)
        {
            // When the input to alpha_Values() is not a letter, 69 is returned
            if (alpha_Values(value_Holder[x]) != 69)
            {
                temp_list->number_count[x - non_Alpha_count] = alpha_Values(value_Holder[x]);
            }
            else
            {
                non_Alpha_count++;
            }
        }
        // this is when appending to a list that already has a value so its not null
        if (name_list != NULL)
        {
            // check if the previous value or the new one has a shorter length
            if (strlen(temp_list->name) < strlen(name_list->name))
            {
                lesser_name_count = strlen(temp_list->name);
            }
            else
            {
                lesser_name_count = strlen(name_list->name);
            }
            // this loop determines if the upcoming value to be inputted into the linked list is greater or less than the previous one
            for (int c = 0; c < lesser_name_count; c++)
            {
                if (temp_list->number_count[c] >= name_list->number_count[c])
                {
                    if (temp_list->number_count[c] < name_list->number_count[c])
                    {
                        break;
                    }
                    if (temp_list->number_count[c] != name_list->number_count[c])
                    {
                        incoming_greater = 1;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        /*
        this is just to set the next pointer of the incoming value to null, couldve been added at any
        point after initialising temp_list with malloc
        */
        temp_list->ptr_next = NULL;
        // if its the first value being added to the linked list, name_list would be null
        if (name_list == NULL)
        {
            name_list = temp_list;
        }
        // if the next value is less than the previous one, it slides behind the previous one
        else if (incoming_greater == 0)
        {
            temp_list->ptr_next = name_list;
            name_list = temp_list;
        }
        // if the next value being added to the linked list is greater than or equal to the previous one
        else
        {
            // honestly idk if this loop is neccesary
            for (node *ptr = name_list; ptr != NULL; ptr = ptr->ptr_next)
            {
                // this here checks if the first value is the only value in the linked list
                if (ptr->ptr_next == NULL)
                {
                    ptr->ptr_next = temp_list;
                    break;
                }

                // variable to check if the incoming value is less than the second? value
                int new_incoming_less_than_after_pointer = 0;

                // checks for lessername count
                if (strlen(temp_list->name) < strlen(ptr->ptr_next->name))
                {
                    lesser_name_count = strlen(temp_list->name);
                }
                else
                {
                    lesser_name_count = strlen(ptr->ptr_next->name);
                }
                // checking which one is actually less,. between our new value and the second one in
                // the existing linked list
                for (int c = 0; c < lesser_name_count; c++)
                {
                    if (temp_list->number_count[c] <= ptr->ptr_next->number_count[c])
                    {
                        if (ptr->ptr_next->number_count[c] == temp_list->number_count[c])
                        {
                            continue;
                        }
                        new_incoming_less_than_after_pointer = 1;
                    }
                    else
                    {
                        break;
                    }
                }
                /*
                if the new value is less than the second one in the linked list
                slide the new value behind the second one in the linked list
                making our new value the second one in the linked list and the previous
                second value the third value
                */
                if (new_incoming_less_than_after_pointer == 1)
                {
                    temp_list->ptr_next = ptr->ptr_next;
                    ptr->ptr_next = temp_list;
                    break;
                }
            }
        }
    }
    // printing the sorted linked list
    node *ptr = name_list;

    while (ptr != NULL)
    {
        printf("%s, ", ptr->name);
        ptr = ptr->ptr_next;
    }
}