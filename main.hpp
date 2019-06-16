#pragma once
#include <map>
#include <string>
#include <iostream>
using namespace std;

double gc_content(string dna);

int hamming_distance(string dna1, string dna2);

string reverse_complement(string dna);

string find_substring(string reference, string dna);


//Complete your quest!

string quest();
