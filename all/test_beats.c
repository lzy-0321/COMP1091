// Assignment 2 21T2 DPST1091: CS bEats
// test_beats.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// Version 1.0.0: Assignment released.

#include <stdio.h>
#include <stdlib.h>

#include "test_beats.h"
#include "beats.h"


// Test function for `add_note_to_beat`
int test_add_note_to_beat(void) {

    // Test 1:
    Beat test_beat = create_beat();
    if (add_note_to_beat(test_beat, -1, -1) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, -1, 0) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 1, -1) != INVALID_KEY) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 2
    if (add_note_to_beat(test_beat, 10, 1) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 9, 12) != INVALID_KEY) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 12, 15) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 3
    (add_note_to_beat(test_beat, 3, 4));
    if (add_note_to_beat(test_beat, 3, 4) != NOT_HIGHEST_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    
    (add_note_to_beat(test_beat, 5, 5));
    if (add_note_to_beat(test_beat, 5, 5) != NOT_HIGHEST_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    
    return MEETS_SPEC;
     
}       

// Test function for `count_notes_in_octave`
int test_count_notes_in_octave(void) {

    // Test 1
    Beat test_beat = create_beat();
    add_note_to_beat(test_beat, 1, 1);
    if (count_notes_in_octave(test_beat, -1) != 0) {
        return DOES_NOT_MEET_SPEC;
    }
    if (count_notes_in_octave(test_beat, 11) != 0) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 2
    add_note_to_beat(test_beat, 1, 1);
    add_note_to_beat(test_beat, 1, 2);

    
    if (count_notes_in_octave(test_beat, 3) != 0) {
        return DOES_NOT_MEET_SPEC;
    }
    if (count_notes_in_octave(test_beat, 2) != 1) {
        return DOES_NOT_MEET_SPEC;
    }
}
    // Test 3
    


// Test function for `add_beat_to_track`
int test_add_beat_to_track(void){
    
    // Test 1
    
    Track test_track = create_track();
    Beat test_beat = create_beat();
    
    if (count_beats_left_in_track(test_track) != 0 ) {
        return DOES_NOT_MEET_SPEC;
    }
    
    test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    
    if (count_beats_left_in_track(test_track) != 1 ) {
        return DOES_NOT_MEET_SPEC;
    }
    
    // Test 2:

    // Test 3


    return MEETS_SPEC;   
}

// Test function for `remove_selected_beat`
int test_remove_selected_beat(void){
    
    // Test 1
    
    
    Track test_track = create_track();
    Beat test_beat = create_beat();

    add_beat_to_track(test_track, test_beat);
    
    test_beat = create_beat();

    select_next_beat(test_track);
    
    remove_selected_beat(test_track);
    
    if (count_beats_left_in_track(test_track) != 1 ) {
        return DOES_NOT_MEET_SPEC;
    }  
    select_next_beat(test_track);
    remove_selected_beat(test_track);  
    if (count_beats_left_in_track(test_track) != 1 ) {
        return DOES_NOT_MEET_SPEC;
    }
    
   
    // Test 2


    // Test 3

    return MEETS_SPEC;
}

// Test function for `add_musical_note_to_beat`
int test_add_musical_note_to_beat(void){
    
    // Test 1
    Beat test_beat = create_beat();
    if (add_musical_note_to_beat(test_beat, "3G") != VALID_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_musical_note_to_beat(test_beat, "4B#") != VALID_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_musical_note_to_beat(test_beat, "1A######") != VALID_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 2

    
    // Test 3 

    return MEETS_SPEC;    
}
