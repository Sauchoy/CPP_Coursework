#pragma once

#include <string>
#include <vector>
#include "vote.h"

typedef unsigned int candidate;

class election
{
	vector<vote> electionVotes;
	


public:

	election();

	void add_vote(const vote& v);

	int vote_count() const;

	void eliminate(candidate c);

	vector<pair<candidate, int>> ranked_candidates() const;

	//--------------------------------------------------------------------
	int getRound() const;
	void increaseRound();
	void runElection();


	
};

