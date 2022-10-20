//Submitted by - Syed M Osama
//GitHub - github.com/syed-m-osama
// Concept
// A pangram is a sentence where every letter of the English alphabet appears at least once.

// TODO
// Given a string sentence containing only lowercase English letters,
// return true if sentence is a pangram, or false otherwise.

#include <iostream>
#include <set>

using namespace std;

string checkIfPangram(string sentence) {
        set<char> st (sentence.begin(),sentence.end());
        char alpha = 'a';
        for(auto i: st){
            if(i == alpha) alpha++;
            else return "false";
        }
        return alpha == '{'?"true":"false";
}

int main(){

    //Example string ex = "hello world" //false
    string ex = "thequickbrownfoxjumpsoverthelazydog"; //true

    cout<<checkIfPangram(ex);

    return 0;
}
