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
    strcpy(questions[0].answer, "Global variable");
    questions[0].answered = false;

    questions[1].value = 150;
    strcpy(questions[1].category, "Programming");
    strcpy(questions[1].question, "Which programming language is known for its use of curly braces and semicolons to denote code blocks and statements?");
    strcpy(questions[1].answer, "Programming language");
    questions[1].answered = false;

    questions[2].value = 200;
    strcpy(questions[2].category, "Programming");
    strcpy(questions[2].question, "In object-oriented programming, what is the term for bundling data and methods that operate on the data into a single unit?");
    strcpy(questions[2].answer, "Encapsulation");
    questions[2].answered = false;

    questions[3].value = 250;
    strcpy(questions[3].category, "Programming");
    strcpy(questions[3].question, "What type of loop in programming executes a block of code as long as a specified condition is false?");
    strcpy(questions[3].answer, "While loop");
    questions[3].answered = false;

    questions[4].value = 100;
    strcpy(questions[4].category, "Algorithms");
    strcpy(questions[4].question, "What algorithmic paradigm involves dividing a problem into smaller subproblems, solving each subproblem independently, and then combining the solutions?");
    strcpy(questions[4].answer, "Divide and conquer");
    questions[4].answered = false;

    questions[5].value = 150;
    strcpy(questions[5].category, "Algorithms");
    strcpy(questions[5].question, "Which sorting algorithm has a worst-case time complexity of O(n^2) and works by repeatedly swapping adjacent elements if they are in the wrong order?");
    strcpy(questions[5].answer, "Bubble Sort");
    questions[5].answered = false;

    questions[6].value = 200;
    strcpy(questions[6].category, "Algorithms");
    strcpy(questions[6].question, "Which searching algorithm operates by repeatedly dividing in half the portion of the list that could contain the item being searched for?");
    strcpy(questions[6].answer, "Binary search");
    questions[6].answered = false;

    questions[7].value = 250;
    strcpy(questions[7].category, "Algorithms");
    strcpy(questions[7].question, "Which algorithmic problem involves rearranging elements in an array or list such that smaller elements come before larger elements?");
    strcpy(questions[7].answer, "Sorting algorithm");
    questions[7].answered = false;

    questions[8].value = 100;
    strcpy(questions[8].category, "Databases");
    strcpy(questions[8].question, "What type of database model organizes data into tables, where each table consists of rows and columns?");
    strcpy(questions[8].answer, "Relational database model");
    questions[8].answered = false;

    questions[9].value = 150;
    strcpy(questions[9].category, "Databases");
    strcpy(questions[9].question, "Which SQL keyword is used to retrieve data from a database table?");
    strcpy(questions[9].answer, "SELECT");
    questions[9].answered = false;

    questions[10].value = 200;
    strcpy(questions[10].category, "Databases");
    strcpy(questions[10].question, "What type of database constraint ensures that each row in a table has a unique value for a specified column or set of columns?");
    strcpy(questions[10].answer, "Unique constraint");
    questions[10].answered = false;

    questions[11].value = 250;
    strcpy(questions[11].category, "Databases");
    strcpy(questions[11].question, "In database terminology, what does the acronym SQL stand for?");
    strcpy(questions[11].answer, "Structured Query Language");
    questions[11].answered = false;


    // initialize each question struct and assign it to the questions array
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_question(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("Question: %s\n", questions[i].question);
            break;
        }
    }
}


// Returns false if the answer is correct for the question for that category and dollar value
/* bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (strcmp(questions[i].answer, answer) == 0) {
                return false;
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
    return false;

}

void display_categories(void) {
    printf("Remaining Categories and Dollar Values:\n");
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (!questions[i].answered) {
            printf("%s - %d\n", questions[i].category, questions[i].value);
        }
    }
}


/*bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("Correct Answer: %s\n", questions[i].answer);
            printf("Player's Answer: %s\n", answer);
            
            // Compare the player's answer with the correct answer (case insensitive)
            if (strcasecmp(questions[i].answer, answer) == 0) {
                return false; // Return false if the answers match
            } else {
                return false; // Return false if the answers do not match
            }
        }
    }
    return false; // Return false if the question is not found
} */

bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (strcmp(questions[i].answer, answer) == 0) {
                return true;
            }
        }
    }
    return false;
}

// Returns false if the question has already been answered
bool already_answered(char *category, int value)
{
    for (int i =0; i < NUM_QUESTIONS; i++) {
        if (!strcmp(questions[i].category, category) && questions[i].value == value)
        return questions[i].answered;
    }
    // lookup the question and see if it's already been marked as answered
    return false;
}
