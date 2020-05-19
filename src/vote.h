#pragma once

#include <vector>

typedef unsigned int candidate;
using namespace std;

class vote{
	
	vector<candidate> preferences;




public:

	vote(const vector<candidate>& prefs);//Constructor declaration
	
	//functions
	bool spent() const;
	candidate first_preference() const;
	void discard(candidate c); 


};

