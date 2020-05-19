#include "main.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <istream>
#include "vote.h"
#include "election.h"


using namespace std;

candidate c;

election readVotes(istream& in) {
	//-------initaliser--------
	election tempElection;
	vector<candidate> tempVote;
	//-------------------------
	string line;
	while (getline(in, line))
	{
		stringstream s(line);
		for (candidate c : s.str())
		{
			if (c > 32) {
				tempVote.push_back((candidate)c - '0');
			}
		}
		tempElection.add_vote(tempVote);
		tempVote.clear();
	}
	return tempElection;

}


int main() {

	fstream in("votes.txt");
	election election = readVotes(in);
	in.close();
	election.runElection();
	return 0;
}