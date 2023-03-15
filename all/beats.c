// Assignment 2 21T2 DPST1091: CS bEats
// beats.c
//
// This program was written by Lu Ziyao (z5340468)
// on 25/7/21
//
// Version 1.0.0: Assignment released.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.

#include "beats.h"

#include <string.h>

// Add your own #defines here.

#define MIN_OCTAVE 0
#define MAX_OCTAVE 9

#define MIN_KEY 0
#define MAX_KEY 11

////////////////////////////////////////////////////////////////////////

// You don't have to use the provided struct track, you are free to
// make your own struct instead.
// If you use the provided struct track, you will have to add fields
// to store other information.

struct track {
    struct beat *head;
    struct beat *selected_beat;
};

struct beat {
    struct note *notes;
    struct beat *next;
    struct note *last;
};

struct note {
    int octave;
    int key;
    struct note *next;
};

// Add any other structs you define here.

////////////////////////////////////////////////////////////////////////

// Add prototypes for any extra functions you create here.

////////////////////////////////////////////////////////////////////////

// Return a malloced Beat with fields initialized.
Beat create_beat(void) {
    Beat new_beat = malloc(sizeof (struct beat));
    assert(new_beat != NULL);

    new_beat->next = NULL;
    new_beat->notes = NULL;
    new_beat->last = NULL;

    return new_beat;
}

// You can find descriptions of what each function should do in beats.h

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add a note to the end of a beat.
int add_note_to_beat(Beat beat, int octave, int key) {


    struct note *a = malloc(sizeof(struct note));
    struct note *b;
 
    a->octave = octave;
    a->key = key;
    a->next = NULL;
    
    b = beat->notes;
 
    if (octave < MIN_OCTAVE || octave > MAX_OCTAVE) {
        return INVALID_OCTAVE;
    } else if (key < MIN_KEY || key > MAX_KEY) {
        return INVALID_KEY;
    } else {      

        if (b == NULL) {
            beat->notes = a;
        } else {
            while (b->next != NULL) {
                b = b->next;
            }  

            if (octave == b->octave && key == b->key) {
                return NOT_HIGHEST_NOTE;
            } else if (octave == b->octave && key < b->key) {
                return NOT_HIGHEST_NOTE;
            } else if (octave < b->octave) {
                return NOT_HIGHEST_NOTE;
            } else { 
                b->next = a;   
            } 
        }
        return VALID_NOTE;
    }      
}

void print_beat(Beat beat) {

    if (beat->notes == NULL) {
        printf("\n");
    } else {
        struct note *a = beat->notes;
        while (a != NULL) {
            printf("%d %02d ", a->octave, a->key);
            a = a->next;   
            if (a != NULL) {
                printf ("| ");
            }
        }
        printf("\n");
    }
    return;
}

int count_notes_in_octave(Beat beat, int octave) {
    struct note *h = beat->notes;
    struct note *c = NULL;
    c = h;
    
    int count = 0;
    while (c != NULL) {
        if (c->octave == octave) {
            count ++;
        }
        c = c->next;
    }
    return count;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

// Return a malloced track with fields initialized.
Track create_track(void) {
    // Note: there is no fprintf in this function, as the
    // Stage 1 autotests call create_track but expect it to return NULL
    // (so this function should do nothing in Stage 1).

    //Allocate memory to track
    Track t = malloc(sizeof(struct track));   
    assert(t!= NULL);
 
    t->head = NULL;
    t->selected_beat = NULL;
    
    return t;
}


void add_beat_to_track(Track track, Beat beat) {    
    if (track->selected_beat == NULL) {
        if (track->head == NULL) {
            track->head = beat;   
        }
        else if (track->head != NULL) {
            beat->next = track->head;
            track->head = beat;
        } 
    } 
    else if (track->selected_beat != NULL) {
        struct beat *current = track->head;
        while (current != track->selected_beat) {
            current = current->next;
        }
        beat->next = current->next;
        current->next = beat;  
    }    
     
    return;
}


int select_next_beat(Track track) {
    if (track->selected_beat == NULL) {
        track->selected_beat = track->head;
    } else {
        track->selected_beat = track->selected_beat->next; 
    }
    if (track->selected_beat == NULL) {
        return TRACK_STOPPED;
    } else {
        return TRACK_PLAYING;
    }
    
}

void print_track(Track track) {

    int count = 1;
    struct beat *new_beat = track->head;
    struct beat *selected = track->selected_beat;
    
    while (new_beat != NULL) {
   
        if (new_beat == selected) {
            printf (">[%d] ", count);
        } else {
            printf(" [%d] ", count);
        }

        print_beat(new_beat);
     
        new_beat = new_beat->next;
        count ++;
    }
  
    return;
}


int count_beats_left_in_track(Track track) {

    struct beat *current = track->selected_beat;
    struct beat *A = track->head;
    int count = 0;
    if (current != NULL) {
        while (current->next != NULL) {
            current = current->next;
            count ++;      
        }
    } else {
        while (A != NULL) {  
            count ++;
            A = A->next;
        }
    }
    return count;
   
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

// Free the memory of a beat, and any memory it points to.
void free_beat(Beat beat) {

    struct note *c;
    c = beat->notes;
    struct note *b = NULL;
    
    while (c != NULL) {
        b = c;
        c = c->next;
        free(b);
    }
    free(beat);
        
    return;
}

void free_track(Track track) {
    // Note: there is no printf in this function, as the
    // Stage 1 & 2 autotests call free_track but don't check whether
    // the memory has been freed (so this function should do nothing in
    // Stage 1 & 2, rather than print an error).
    
    struct beat *c;
    c = track->head;
    struct beat *b = NULL;
    
    while (c != NULL) {
        b = c;
        c = c->next;
        free_beat(b);
    }
    free(track);
}
int remove_selected_beat(Track track) {
    struct beat *a = NULL; 
    struct beat *b = track->head;
    struct beat *c = track->selected_beat;
    int result;

    if (c != NULL) {
        if (c == track->head) {  
            track->head = track->head->next;           
            result = select_next_beat(track);
            free_beat(c);
            return result;    
        } else if (c->next == NULL) {
            while (b->next != c) {
                a = b;
                b = b->next;
            }      
            b->next = NULL;
            track->selected_beat = NULL;
            free_beat(c);
            return TRACK_STOPPED;   
        } else {
            while (b != c) {
                a = b;
               a = b->next;
            }
            a->next = b->next;
            result = select_next_beat(track);
            free_beat(c);
            return result;     
        }
    } else {
        return TRACK_STOPPED; 
    }
      
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add note to beat, given its 'musical notation'.
int add_musical_note_to_beat(Beat beat, char *musical_notation) {
    printf("add_musical_note_to_beat not implemented yet.");
    return VALID_NOTE;
}


////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

// Cut a range of beats to the end of a track.
void cut_range_to_end(Track track, int range_length) {
    printf("cut_range_to_end not implemented yet.");
    return;
}

// Reverse a list of beats within a range of a track.
int reverse_range(Track track, int range_length) {
    printf("reverse_range not implemented yet.");
    return 0;
}


