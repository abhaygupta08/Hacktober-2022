//Submitted by - Syed M Osama
//GitHub - github.com/syed-m-osama

//Concept
//Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// Example 200 = CC, 451 = CDLI

// TODO
// Given an integer return its roman form.
// Constraints
// 1 <= integer <= 3999

#include <iostream>

using namespace std;

string integerToRoman(int num) {

        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }

int main(){

    int num;
    cout<<"Enter a number in range[1,3999]: ";
    cin>>num;
    cout<<endl<<integerToRoman(num);

    return 0;
}