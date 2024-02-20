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
#include <ctype.h>
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    questions[0].value = 100;
    strcpy(questions[0].category, "Programming");
    strcpy(questions[0].question, "What is the term for a variable that is accessible throughout the entire program?");
    strcpy(questions[0].answer, "What is a global variable?");
    questions[0].answered = false;

    questions[1].value = 150;
    strcpy(questions[1].category, "Programming");
    strcpy(questions[1].question, "What algorithmic paradigm involves dividing a problem into smaller subproblems, solving each subproblem independently, and then combining the solutions?");
    strcpy(questions[1].answer, "What is divide and conquer?");
    questions[1].answered = false;

    questions[2].value = 200;
    strcpy(questions[2].category, "Programming");
    strcpy(questions[2].question, "What type of database model organizes data into tables, where each table consists of rows and columns?");
    strcpy(questions[2].answer, "What is the relational database model?");
    questions[2].answered = false;

    questions[3].value = 250;
    strcpy(questions[2].category, "Programming");
    strcpy(questions[2].question, "What type of database model organizes data into tables, where each table consists of rows and columns?");
    strcpy(questions[2].answer, "What is the relational database model?");
    questions[3].answered = false;

    // initialize each question struct and assign it to the questions array
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    for (int i=0; i<NUM_QUESTIONS; i++) {
        if (!questions[i].answered){
            printf( "Remaining Categories and Dollar Values: %s - %d\n", questions[i].category, questions[i].value);
        }
    }

    // print categories and dollar values for each unanswered question in questions array
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for ( int i=0; i < NUM_QUESTIONS; i++) {
        if (!strcmp(questions[i].category, category) && questions[i].value == value)
            printf("Questions: %s\n", questions[i].question);
            break;
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
/* bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (strcmp(questions[i].answer, answer) == 0) {
                return true;
            }
            break; // Exit loop if the category and value match but answer does not
        }
    }
    return false;
} */


extern bool all_questions_answered(void) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (!questions[i].answered) {
            return false;
        }
    }
    return true;
}
bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            // Convert both answers to lowercase for case-insensitive comparison
            char answer_lower[MAX_LEN];
            char player_answer_lower[MAX_LEN];
            
            strcpy(answer_lower, questions[i].answer);
            strcpy(player_answer_lower, answer);
            
            for (int j = 0; answer_lower[j]; j++) {
                answer_lower[j] = tolower(answer_lower[j]);
            }
            
            for (int j = 0; player_answer_lower[j]; j++) {
                player_answer_lower[j] = tolower(player_answer_lower[j]);
            }

            if (strcmp(answer_lower, player_answer_lower) == 0) {
                return true;
            }
            break; // Exit loop if the category and value match but answer does not
        }
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for (int i =0; i < NUM_QUESTIONS; i++) {
        if (!strcmp(questions[i].category, category) && questions[i].value == value)
        return questions[i].answered;
    }
    // lookup the question and see if it's already been marked as answered
    return false;
}
