#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the golf course
void print_course(int ball_position, int course_length) {
    for (int i = 0; i < course_length; i++) {
        if (i == ball_position) {
            printf("O"); // Represents the ball
        } else if (i == course_length - 1) {
            printf("|"); // Represents the flag (hole)
        } else {
            printf("-"); // Represents the course
        }
    }
    printf("\n");
}

int main() {
    int ball_position;     // Ball's position on the course
    int stroke_count;      // Total number of strokes taken
    int club_choice;       // Player's chosen club
    int shot_distance;     // Distance the ball travels for the current shot
    int record[50];        // Array to store distances of shots
    int shot_count;        // Counter for the number of shots
    int course_length;     // Length of the course (randomized each round)
    int driver_min, driver_max, iron_min, iron_max, chipper_min, chipper_max, putter_min, putter_max; // Randomized distance ranges for each club
    char play_again;       // Option to play again
    
    srand(time(0));        // Seed for random number generation

    do {
        // Randomize the course length between 250 to 500 yards for each round
        course_length = 250 + rand() % 251; // Random course length between 250-500 yards

        // Randomize club distances for each round
        driver_min = 150 + rand() % 51;     // Driver hits between 150-200 yards
        driver_max = driver_min + 50;
        iron_min = 100 + rand() % 51;       // Iron hits between 100-150 yards
        iron_max = iron_min + 50;
        chipper_min = 60 + rand() % 21;     // Chipper hits between 60-80 yards
        chipper_max = chipper_min + 20;
        putter_min = 10 + rand() % 6;       // Putter hits between 10-15 yards
        putter_max = putter_min + 5;

        // Initialize game variables
        ball_position = 0;
        stroke_count = 0;
        shot_count = 0;

        // Game introduction
        printf("\nWelcome to the Golf Game!\n");
        printf("This round, the course is %d yards long.\n", course_length);
        printf("Choose your clubs wisely and hit the ball as few times as possible.\n");
        printf("Let's get started!\n\n");

        // Game loop: continues until the ball reaches the hole
        while (ball_position < course_length - 1) {
            // Display the golf course with the current ball position
            print_course(ball_position, course_length);

            // Prompt the player to choose a club
            printf("\nChoose a club:\n");
            printf("1. Driver (%d-%d yards)\n", driver_min, driver_max);
            printf("2. Iron (%d-%d yards)\n", iron_min, iron_max);
            printf("3. Chipper (%d-%d yards)\n", chipper_min, chipper_max);
            printf("4. Putter (%d-%d yards)\n", putter_min, putter_max);
            printf("Enter your choice (1-4): ");
            scanf("%d", &club_choice);

            // Determine the shot distance based on the chosen club
            if (club_choice == 1) {
                shot_distance = driver_min + rand() % (driver_max - driver_min + 1);  // Driver hits within randomized range
            } else if (club_choice == 2) {
                shot_distance = iron_min + rand() % (iron_max - iron_min + 1);  // Iron hits within randomized range
            } else if (club_choice == 3) {
                shot_distance = chipper_min + rand() % (chipper_max - chipper_min + 1);  // Chipper hits within randomized range
            } else if (club_choice == 4) {
                shot_distance = putter_min + rand() % (putter_max - putter_min + 1);  // Putter hits within randomized range
            } else {
                // Handle invalid club choices
                printf("Invalid club choice! You lost a turn.\n");
                continue; // Skip the rest of the loop and prompt again
            }

            // Update ball position
            ball_position += shot_distance;

            // Ensure the ball doesn't go past the hole (course end)
            if (ball_position >= course_length - 1) {
                ball_position = course_length - 1; // Snap the ball to the hole
            }

            // Record the shot distance
            record[shot_count++] = shot_distance;

            // Increment stroke count
            stroke_count++;

            // Provide feedback to the player
            printf("You hit the ball %d yards! Ball is now at position %d.\n", shot_distance, ball_position);
        }

        // Game completed
        printf("\nCongratulations! You reached the hole in %d strokes.\n", stroke_count);
        printf("Here's your record of shots:\n");

        // Print the record of each shot
        for (int i = 0; i < shot_count; i++) {
            printf("Shot %d: %d yards\n", i + 1, record[i]);
        }

        // Display final course with the ball at the hole
        print_course(ball_position, course_length);

        // Ask if the player wants to play again
        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y'); // Loop if the player chooses to play again

    // Exit message
    printf("\nThanks for playing! See you on the course next time!\n");

    return 0;
}