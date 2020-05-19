#include "vote.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vote::vote(const vector<candidate>& prefs) : //constuctor definition
	preferences(prefs) {
	
} 


candidate vote::first_preference() const //returns the current first preference of the vote. Only called if spent() is false.
{
	if (spent() == false )
	{
		return preferences.front();
	}
}

void vote::discard(candidate c) //removes any occurrence of the named candidate(c) from the vote.
{
	preferences.erase(remove(preferences.begin(), preferences.end(), c), preferences.end());
}


bool vote::spent() const //returns true if the vote has no preferences left
{
	return preferences.empty();
}
