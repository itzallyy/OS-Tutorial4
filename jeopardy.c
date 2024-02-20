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

#define BUFFER_LEN 256
#define NUM_PLAYERS 4

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main(int argc, char *argv[]) {
    player players[NUM_PLAYERS];
    char category[MAX_LEN];
    int value;

    // Prompt for players names and initialize scores
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // Display the game introduction and initialize the questions
    initialize_game();

    // Game loop
    while (true) {
        display_categories();

        // Player loop
        for (int i = 0; i < NUM_PLAYERS; i++) {
            printf("Player %s, pick your category and dollar value (e.g., 'Programming 100'): ", players[i].name);
            scanf("%s %d", category, &value);
            getchar();

            // Display the question for the selected category and dollar value
            display_question(category, value);

            // Accept player answer
            printf("Player %s, enter your answer: ", players[i].name);
            char buffer[BUFFER_LEN];
            fgets(buffer, BUFFER_LEN, stdin);
            // Validate player answer
            if (valid_answer(category, value, buffer)) {
                printf("Correct answer! Player %s earns $%d.\n", players[i].name, value);
                // Update player score
                update_score(players, NUM_PLAYERS, players[i].name, value);
            } else {
                printf("Incorrect answer! Player %s loses $%d.\n", players[i].name, value);
                // Deduct points if the answer is incorrect (optional)
            }

            clear_input_buffer();
        }

        // Check for game end condition (all questions answered)
        if (all_questions_answered()) {

            break; // Exit the game loop
        }
    }

    // Display final results
    printf("Game over! Final scores:\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %s: $%d\n", players[i].name, players[i].score);
    }

    return 0;
}
