// Assignment 2 20T2 COMP1511: Castle Defense
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// Version 1.0.0 (2020-07-20): Assignment released.
// Version 1.0.1 (2020-08-04): Changed wording in advance_enemies comment

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "realm.h"
///////////////////////////////////////////////////////////////////////

// `struct realm` represents a realm, which represents the state of the
// entire program. It is mainly used to point to a linked list of 
// locations, though you may want to add other fields to it.
//
// You may need to add fields to struct realm.
struct realm {
    struct location *castle;
    struct location *lair;
};

// `struct location` represents a location, which could be a land,
// a tower, or a castle. Each of those places has a different type
// of information that this struct will need to store.
//
// You will need to add fields to struct location.
// Struct with fields name, power, uses, enemy pointer and a next pointer
// for the next location in the realm
struct location {
    char name[MAX_NAME_LENGTH];
    int power;
    int uses;
    struct enemy *enemies;
    struct location *next;

};

// `struct enemy` represents an enemy, which will move through the
// realm (to each location). Towers can deal damage to it, and
// it can deal damage to the Castle.
//
// You will need to add fields to struct enemy.
struct enemy {
    char name[MAX_NAME_LENGTH];
    int HP;
    struct enemy *next;
};

// Add any other structs you define here.

///////////////////////////////////////////////////////////////////////

// Function prototypes for helper functions
static Location new_location(char *name);
static void print_tower(char *name, int power, int uses, Effect effect);
static void print_land(char *name);
static void print_castle(char *name, int defense);
static void print_enemy(char *name, int cur_hp, int max_hp);

// Add prototypes for any extra functions you create here.
static struct location *NT(char *name, int power, int uses);
static struct enemy *NE (char *name, int hp);
static void Eprint(struct enemy *enemy_location);
static struct enemy *Eloop(struct location *location_find);
static void DE_E(struct location *free_location);
static int I(Realm realm);

///////////////////////////////////////////////////////////////////////

// You need to implement the following 9 functions.
// In other words, write code to make the function work as described 
// in realm.h.

// Create a new realm, and return a pointer to it.
// You may need to change this function in later stages.
Realm new_realm(void) {
    struct realm *realm = malloc(sizeof(struct realm));
    realm->castle = new_location("Castle");
    realm->lair = new_location("Lair");

    if (realm->castle != NULL && realm->lair != NULL) {
        realm->castle->next = realm->lair;
    }
    
    return realm;
}


// Return a new location created with malloc.
static Location new_location(char *name) {
    struct location *new_location = malloc(sizeof(struct location));
    strcpy(new_location->name, name);
    new_location->power = 0;
    new_location->uses = 0;
    new_location->next = NULL;
    new_location->enemies = NULL;
    return new_location;
}
    
////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add a new location to the realm, and return the total locations 
// locations in the realm.
int add_location(Realm realm, char *name) {
    struct location *input_position = new_location(name);
    int Loc = 0;
    struct location *head = realm->castle;
    struct location *current = head;
    struct location *previous = NULL;
    while (current != NULL) {
        if (current == realm->lair) {
            input_position->next = realm->lair;
            previous->next = input_position;
            current = NULL;
            Loc++;
        }
        if (current != NULL) {
            previous = current;
            current = current->next;
        }
        Loc++;
    }
    return Loc; 
}

// Print out the realm.
void print_realm(Realm realm) {
    struct location *head = realm->castle;
    struct location *current = head;
    struct enemy *E_Loc = current->enemies;
    if (current == head) {
        print_castle(current->name, STARTING_CASTLE_HP);
        if (E_Loc != NULL) {
            Eprint(E_Loc);
        }
    }
    current = current->next;
    while (current != NULL) {
        E_Loc = current->enemies;
        if (current->power == 0) {
            print_land(current->name);
            if (E_Loc != NULL) {
                Eprint(E_Loc);
            }
            
        }
        if (current->power >= 1) {
            print_tower(current->name, current->power, current->uses, 0);
            if (E_Loc != NULL) {
                Eprint(E_Loc);
            }
        }
        current = current->next;
    }

}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add an enemy to the realm.
int new_enemy(Realm realm, char *location_name, char *name, int HP) {
    if (HP < 1) {
        return ERROR_INVALID_STAT;
    }
    struct location *head = realm->castle;
    struct location *location_find = head;
    while (location_find != NULL) {
        if (strcmp(location_find->name, location_name) == 0) {
            struct enemy *new_enemy = NE(name, HP);
            if (location_find->enemies == NULL) {
                
                new_enemy->next = location_find->enemies;
                location_find->enemies = new_enemy;
                return SUCCESS;
            }
            if (location_find->enemies != NULL) {
                struct enemy *current_enemy = Eloop(location_find);
                new_enemy->next = current_enemy->next;
                current_enemy->next = new_enemy;
                return SUCCESS;
            }
            location_find = NULL;
        }
        location_find = location_find->next;
    }
    return ERROR_NO_LOCATION;
}

// Add a new tower to the realm.
int new_tower(Realm realm, char *prev_name, char *name, int power, int uses) {
    if (power < 1 || uses < 1) {
        return ERROR_INVALID_STAT;
    }
    struct location *head = realm->castle;
    struct location *current = head;
    while (current != NULL) {
        if (strcmp(current->name, prev_name) == 0) {
            struct location *new_tower = NT(name, power, uses);
            new_tower->next = current->next;
            current->next = new_tower;
            current = NULL;
            return SUCCESS;
        }
        current = current->next;
    }
    return ERROR_NO_LOCATION;
}


////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

// Destroy the realm, and free any associated memory.
void destroy_realm(Realm realm) {
    struct location *head = realm->castle;
    struct location *current = head;
    struct location *free_location = NULL;
    while (current != NULL) {
        free_location = current;
        if (free_location->enemies) {
            DE_E(free_location);  
        }
        current = current->next;
        free(free_location);
    }
    free(realm);    
}

// Advance enemies towards the castle.
int advance_enemies(Realm realm) {
    struct location *head = realm->castle;
    struct location *current_pos = head;
    struct location *previous_pos = NULL;
    int num_enemies = 0;
    while (current_pos != NULL) {
        if (current_pos->enemies != NULL && previous_pos == NULL) {
            num_enemies = I(realm);
            current_pos->enemies = NULL;
        }
        if (current_pos->enemies != NULL) {
            previous_pos->enemies = current_pos->enemies;
            current_pos->enemies = NULL;
        }
        previous_pos = current_pos;
        current_pos = current_pos->next;
    }
    return num_enemies;
}

// Apply damage from the enemies at each tower to that tower.
// defense.
int apply_damage(Realm realm) {
    return 0;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

// Apply the specified buff to the relevant towers or enemies.
int apply_buff(Realm realm, char *search_term, Buff buff, int amount){
    return 0;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

// Apply the specified effect to each tower whose name matches the
// specified search term.
int apply_effect(Realm realm, char *search_term, Effect effect) {
    return 0;
}

////////////////////////////////////////////////////////////////////////

// Add definitions for your own functions below.
// Make them static to limit their scope to this file.

static struct enemy *NE (char *name, int HP) {
    struct enemy *N_E = malloc(sizeof(struct enemy));
    strcpy(N_E->name, name);
    N_E->next = NULL;
    N_E->HP = HP;
    return N_E;
}

static void Eprint(struct enemy *enemy_location) {
    struct enemy *E_H = enemy_location;
    struct enemy *C_E = E_H;
    while (C_E != NULL) {
        print_enemy(
            C_E->name, C_E->HP, 
            C_E->HP
        );
        C_E = C_E->next;
    }

}
static struct enemy *Eloop(struct location *location_find) {
    struct enemy *H_D = location_find->enemies;
    struct enemy *C_E = H_D;
    while (C_E->next != NULL) {
        C_E = C_E->next;
    }
    return C_E;
}

static struct location *NT(char *name, int power, int uses) {
    struct location *N_T = malloc(sizeof(struct location));
    strcpy(N_T->name, name);
    N_T->power = power;
    N_T->uses = uses;
    N_T->enemies = NULL;
    N_T->next = NULL;
    return N_T;
}

static void DE_E(struct location *free_location) {
    struct enemy *H_E = free_location->enemies;
    struct enemy *C_E = H_E;
    struct enemy *F_E = NULL;
    while (C_E != NULL) {
        F_E = C_E;
        C_E = C_E->next;
        free(F_E);
    }
}

static int I(Realm realm) {
    struct enemy *head = realm->castle->enemies;
    struct enemy *used = head;
    struct enemy *old = NULL;
    int i = 0;
    while (used != NULL) {
        i++;
        old = used;               
        used = used->next;
        free(old);
    }
    
    return i;
}

////////////////////////////////////////////////////////////////////////
//                    Provided print functions                        //
//         NOTE: YOU SHOULD NOT MODIFY THE FOLLOWING FUNCTIONS        //
////////////////////////////////////////////////////////////////////////

void print_tower(char *name, int power, int uses, int effect) {
    printf(" ^ %32s [pow: %3d | uses: %3d]", name, power, uses);
    if (effect == EFFECT_NONE) printf(" {%c}", EFFECT_NONE_CHAR);
    if (effect == EFFECT_PORTAL) printf(" {%c}", EFFECT_PORTAL_CHAR);
    if (effect == EFFECT_ICE) printf(" {%c}", EFFECT_ICE_CHAR);
    printf("\n");
}

void print_land(char *name) {
    printf(" ^ %32s [____________________]\n", name);
}

void print_castle(char *name, int defense) {
    printf(" ^ %32s [Castle Defenses: %3d]\n", name, defense);
}

void print_enemy(char *name, int cur_hp, int max_hp) {
    printf(" ^ %40s [hp: %d/%d]\n", name, cur_hp, max_hp);
}

////////////////////////////////////////////////////////////////////////
//               End of provided print functions                      //
////////////////////////////////////////////////////////////////////////

