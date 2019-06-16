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
        
        string ans = answer();
        string check = quest();
        string your_ans = cipher(check);
        
        testcase.CHECK_EQUAL(your_ans, ans);
        
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
