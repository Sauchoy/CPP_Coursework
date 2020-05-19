#include "election.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>
#include "vote.h"


election::election(){} //default constructor

bool voteIsSpent(const vote& v) {
	return v.spent();
}

void election::add_vote(const vote& v) // adds a vote to the collection
{
	electionVotes.push_back(v);
}

int election::vote_count() const //returns the number of votes currently left
{
	return electionVotes.size();
}

void election::eliminate(candidate c) {

	for (int i = 0; i < electionVotes.size(); i++) 
	{
		electionVotes[i].discard(c);
	}
	electionVotes.erase(remove_if(electionVotes.begin(), electionVotes.end(), voteIsSpent), electionVotes.end());
}



bool sortByDescOrder(const pair<candidate, int>& x, const pair<candidate, int>& y) {
	return(x.second > y.second);
}

vector<pair<candidate, int >> election::ranked_candidates() const
{
	map<candidate, int> count;
	for (vote v : electionVotes) {
		candidate c = v.first_preference();
		++count[c];
	}
	vector<pair<candidate, int>> order(count.cbegin(), count.cend());
	sort(order.begin(), order.end(), sortByDescOrder);
	return order;
}



//functions related to rounds

int rounds = 0;

int election::getRound() const
{
	return rounds;
}

void election::increaseRound()
{
	rounds = rounds + 1;
}

//function that runs that whole election and outputs the results
void election::runElection()
{
	increaseRound();
	cout << "Round" << getRound() << ": " << vote_count() << " votes" << endl;
	cout << "First preferences:" << endl;
	vector<pair<candidate, int>> current_ranking = ranked_candidates();
	eliminate(current_ranking.back().first);
	for (auto pair : current_ranking) {
		cout << " " << "Candidate " << pair.first << ": " << pair.second << endl;
	}
	if (current_ranking.front().second > vote_count() / 2) {
		cout << "Candidate " << current_ranking.front().first << " has won the election.";
	}
	else if (current_ranking.size() == 2 && current_ranking.front().second == current_ranking.back().second) {
		cout << "Candidate " << current_ranking.front().first << " has been eliminated" << endl;
	}
	else
	{
		cout << "Candidate " << current_ranking.back().first << " has been eliminated" << endl;
		runElection();
	}
}


