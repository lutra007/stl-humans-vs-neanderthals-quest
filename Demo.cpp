/**
 * A demo program for humans vs neanderthals quest
 * 
 * @author Kira Kondratyeva
 * @since  2019-05
 */

#include "main.hpp"
#include "sequence.hpp"

int main() {
    map <string, string> reference = getReference();
    map <string, string> genbank = getSequences();
    
    map <string, string>::iterator it;
    
    cout << "Access GenBank IDs" << endl;
    for (it = genbank.begin(); it != genbank.end(); ++it)
        cout << it->first << endl;
    cout << endl;

    cout << "Access references" << endl;
    auto human = reference.find("human");
    cout << human->first << endl;
    cout << human->second << endl;
    
    auto neanderthal = reference.find("neanderthal");
    cout << neanderthal->first << endl;
    cout << neanderthal->second << endl;
    
    cout << "Great! You have all sequences you need!" << endl;
    cout << endl;
    

    //Let's check gc_content
    cout << "GC content" << endl;
    double gc = gc_content("AACC"); 
    cout << gc << endl; //print 50
    
    gc = gc_content("AAAA"); 
    cout << gc << endl; //print 0
    
    string example = "GGCGCTAGCCGATC";
    gc = gc_content(example); 
    cout << gc << endl; //print 71.4286
    
    gc = gc_content(human->second); 
    cout << gc << endl; //print 45
    
    gc = gc_content(neanderthal->second); 
    cout << gc << endl; //print 43.3333
    cout << endl;
    
    
    //Let's check hamming_distance
    cout << "Hamming distance" << endl;
    int dist = hamming_distance("AACC", "AACC");
    cout << dist << endl; //print 0
    
    dist = hamming_distance(human->second, neanderthal->second);
    cout << dist << endl; //print 16
    cout << endl;
    
    
    //Let's check reverse_complement
    cout << "Reverse complement" << endl;
    string rev_comp = reverse_complement("AACC");
    cout << rev_comp << endl; //print GGTT
    
    rev_comp = reverse_complement(example);
    cout << rev_comp << endl; //print GATCGGCTAGCGCC
    if ( rev_comp == "GATCGGCTAGCGCC" )
        cout << "Correct!" << endl;
    else
        cout << "Fail! Check your reverse_complement function!" << endl;
    cout << endl;
    
    
    //Let's check find_substring
    cout << "Find substring" << endl;
    string match = find_substring("AC", "AACC");
    cout << rev_comp << endl; //print AC
    
    match = find_substring("AC", "GGTT");
    cout << rev_comp << endl; //print AC
    
    string easy = example + human->second;
    match = find_substring(neanderthal->second, easy);
    if (match == human->second)
        cout << "Good match!" << endl;
    else
        cout << "Easy fail! Check your find_substring function!" << endl;
    
    string puzzle = reverse_complement(neanderthal->second);
    puzzle = example + puzzle + human->second + example;
    match = find_substring(neanderthal->second, puzzle);
    if (match == neanderthal->second)
        cout << "Awesome!" << endl;
    else
        cout << "Fail! Check your find_substring function!" << endl;
    
    return 0;
}