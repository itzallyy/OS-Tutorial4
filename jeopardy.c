/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    char chr;
    int value;
    int i;
    char *category;

    category =(char *)malloc(sizeof(char));

    if (category == NULL) {
        printf("Category not available!\n");
        return -1;
    }
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    printf("Enter the name of player1: ");
    scanf(" %c", &chr);

    printf("Enter the name of player2: ");
    scanf(" %c", &chr);

    printf("Enter the name of player3: ");
    scanf(" %c", &chr);

    printf("Enter the name of player4: ");
    scanf(" %c", &chr);

    
    // initialize each of the players in the array

    for(i=0; i<4; i++) {
        display_categories();
        printf("Player, I hope you're excited for your question! Pick your category > %s %d", category, value);
        scanf(" %d %c" , &value , category);
        initialize_game();
    
        display_question(category , value);

        free(category); 

    }   
 
    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {   
        display_categories();
        // Call functions from the questions and players source files

        // Execute the game until all questions are answered

        // Display the final results and exit
    }
    
    return EXIT_SUCCESS;
}
