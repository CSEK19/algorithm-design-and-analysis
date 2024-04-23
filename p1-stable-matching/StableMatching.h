/*
 * @file StableMatching.h
 * @brief Declaration of the performStableMatching function for stable matching using the Gale-Shapley algorithm.
 *
 * This file contains the declaration of the performStableMatching function, which implements the Gale-Shapley
 * algorithm for stable matching between people and pets. It takes references to the People and Pet objects as
 * parameters and returns true if the stable matching is successful, and false otherwise.
 *
 * The Gale-Shapley algorithm involves iteratively proposing and rejecting matches until a stable matching is achieved,
 * where no pair of individuals would prefer each other over their current matches.
 *
 * @author Phat Tran
 */

#pragma once

#include "People.h"
#include "Pet.h"

using namespace std;

/*
 * @brief Perform stable matching algorithm between people and pets.
 * @param people Reference to the People object.
 * @param pets Reference to the Pet object.
 * @return True if stable matching is successful, false otherwise.
 */
bool performStableMatching(People &people, Pet &pets);
