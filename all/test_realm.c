// Assignment 2 20T2 COMP1511: Castle Defense
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// Version 1.0.0 (2020-07-20): Assignment released.
// Version 1.0.1 (2020-07-21): Add return value to main.
// Version 1.1.0 (2020-07-23): Add test_apply_buff to main.

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "realm.h"
#include "test_realm.h"
#include "capture.h"

////////////////////////////////////////////////////////////////////
//                        Function Protoypes                      //
////////////////////////////////////////////////////////////////////

// TODO: Add your own prototypes here, if necessary.

////////////////////////////////////////////////////////////////////
//                         Helper Functions                       //
////////////////////////////////////////////////////////////////////

// Find the string 'needle' in 'haystack'
int string_contains(char *haystack, char *needle) {
    return strstr(haystack, needle) != NULL;
}

// NOTE: You should not declare any structs from realm.c here.
// Declaring structs from realm.c in this function is against the
// rules of the assignment. 

// Main function: this function will not be used in testing, you do not
// need to change it.
// If you want to write your own tests, add them in `extra_tests`.
int main(int argc, char *argv[]) {
    printf("\n================== Castle Defense Tests ==================\n");

    test_add_location();
    test_print_realm();
    test_new_enemy();
    test_new_tower();
    test_apply_damage();
    test_apply_buff();
    extra_tests();

    return 0;
}

// NOTE: These tests are explained in `test_realm.h`

void test_add_location(void) {
    printf("Test whether this add_location follows the spec: ");

    // Test 1: Does add_location's return value count the Castle & Lair?

    Realm test_realm = new_realm();

    int num_locations = add_location(test_realm, "Location");
    if (num_locations != 3) {
        printf(DOES_NOT_FOLLOW_SPEC);
        // since we don't want to print FOLLOWS_SPEC at the end,
        // we just return to the main function here.
        return;
    }

    // Test 2: Does add_location return the correct amount for lots of locations?

    Realm test2_realm = new_realm();
    num_locations = 0;
    num_locations = add_location(test2_realm, "DarthVader");
    num_locations = add_location(test2_realm, "HYDRA");
    num_locations = add_location(test2_realm, "Ultron");

    if (num_locations!= 8) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    // Test 3: Add your own test, and explain it below:
    Realm test3_realm = new_realm();
    
    
    
    printf(FOLLOWS_SPEC);
}

void test_print_realm(void) {
    printf("Test whether this print_realm follows the spec: ");

    // Test 1: Does print_realm show the Castle?

    Realm test_realm = new_realm();

    char print_text[10000];
    CAPTURE(print_realm(test_realm), print_text, 10000);

    if (!string_contains(print_text, "Castle")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        // since we don't want to print FOLLOWS_SPEC at the end,
        // we just return to the main function here.
        return;
    }

    // Test 2: Does print_realm show the correct HP of the castle?

    Realm test2_realm = new_realm();

    char print_text2[10000];
    CAPTURE(print_realm(test2_realm), print_text2, 10000);

    if (!string_contains(print_text2, "Castle : 100")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    // Test 3: Add your own test, and explain it below: 
    // ........

    // TODO: Change Here

    printf(FOLLOWS_SPEC);
}

// Stage 2

void test_new_enemy(void) {
    printf("Test whether this new_enemy follows the spec: ");

    // Test 1: Does new_enemy work if you're adding to the Lair?
    Realm test_realm = new_realm();
    int E_C = new_enemy(test_realm, "Lair", "Zfg", 5);
    
    if (E_C != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    // Test 2: Add your own test, and explain it below:
    Realm test2_realm = new_realm();
    
    int E_H_C = new_enemy(test2_realm, "Lair", "Yjtj", 5);
    if (E_H_C != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    printf(FOLLOWS_SPEC);
}

void test_new_tower(void) {
    printf("Test whether this new_tower follows the spec: ");

    // Test 1: Does new_tower work if you're adding after another tower?

    Realm test_realm = new_realm();
    new_tower(test_realm, "Castle", "Bth", 3, 3);
    new_tower(test_realm, "Bbdr", "Csfb", 3, 3);
    
    if (&new_tower != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    // Test 2: Add your own test, and explain it below:
    

    printf(FOLLOWS_SPEC);
}

// Stage 3 (2 marks)

void test_apply_damage(void) {
    printf("Test whether this apply_damage follows the spec: ");

    // Test 1: Does apply_damage actually destroy enemies?

    Realm test_realm = new_realm();
    int D_E;
    int C_T = new_tower(test_realm, "Castle", "Dth", 3, 3);
    int C_E = new_enemy(test_realm, "Ejgy", "Fth", 2);
    D_E = apply_damage(test_realm);
    char print_text[10000];
    CAPTURE(print_realm(test_realm), print_text, 10000);
    
    // Checks if enemy is removed from the realm after destroyed
    if (!string_contains(print_text, " ^                             Eden [pow:   5 | uses:   2] {n}\n ^                             Lair [____________________]\n")) {
        C_T = 0;
        C_E = 0;
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    // Test 2: Add your own test, and explain it below:
    // ........

    // TODO: Change Here

    printf(FOLLOWS_SPEC);
}

// Stage 4 (1 marks)

void test_apply_buff(void) {
    printf("Test whether this apply_buff follows the spec: ");
    // Test 1: Add your own test, and explain it below:
    // ........

    // TODO: Change Here

    // Test 2: Add your own test, and explain it below:
    // ........

    // TODO: Change Here

    printf(FOLLOWS_SPEC);
}

// Extra Tests (not worth marks, but fun!)

void extra_tests(void) {
    // TODO: add extra tests, if you'd like to.
}
