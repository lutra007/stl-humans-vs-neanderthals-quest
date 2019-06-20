/**
 * Solve the Quest!
 * 
 * @author Kira Kondratyeva
 * @since  2019-05
 */
#include "main.hpp"
#include "sequence.hpp"
#include "badkan.hpp"

int main() {
    
    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {
        
        testcase.setname("test range");
        
        string your_answer = quest();
        your_answer = cipher(your_answer);
        map <string, string> genbank = getSequences();
        map <string, string>::iterator it;        
        for (it = genbank.begin(); it != genbank.end(); ++it) {
            bool compare1 = answer(it->first);
            bool compare2 = answer(it->first, your_answer);
            testcase.CHECK_EQUAL(compare2, !compare1);  
        }
        
        grade = testcase.grade();
        
    } else {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: "  << grade << endl;
    
    if (grade == 100)
        secret_message();
    
    return 0;
}
