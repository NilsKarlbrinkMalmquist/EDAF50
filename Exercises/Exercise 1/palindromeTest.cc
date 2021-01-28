 #include <iostream>

 using namespace std;
 //using std::cout;
// using std::cin;


/*bool isPalindrome(String s){

}*/

int main() {
   cout <<"Type a word: ";
   string word;
   while (cin >> word) {
     if(word == string(word.rbegin(), word.rend())){
       cout << word <<" is a palindrome. \n";
     }
     else {
       cout << word <<" is not a palindrome. \n";
     }
     cout <<"\nType another word: ";
   }
   return 0;
 }
