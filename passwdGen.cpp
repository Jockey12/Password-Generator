// jockey
// 1/23/24
#include <fstream>
#include <iostream>
#include <string>
#include <random>

const int MAX = 90;

std::string passGen(int n) {
  
  std::ofstream passwordtext("password.txt");

  std::random_device rd;
  std::mt19937 g(rd());

  char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P','Q','R','S','T','U',
    'V','W','X','Y','Z', '0','1','2','3','4','5','6','7','8','9','!','@','#','$','%','^','&','*','(',')'};
  
  std::string res;
  std::string number;
  std::string combined;

  if(n <5) {
    std::cout << "Please enter a length of 5 or more to be a strong password.\n";
    return "Try again";
    
  } else if(n >=5){
    for(int p = 0; p < n; p++) {
      res = res+alphabet[g()%MAX];
      number = numbers[g()%MAX];
      combined = number+=res;
      //Generates random numbers but isnt needed. (If needed Put in combined variable after number+=res >> res+std::to_string(g()) )
    }
  } 
  
  if(n >110) {
    std::cout << "Please enter a length LESS than or equal to 110\n";
    return "Try Again"; 
  }

  passwordtext << combined;
  passwordtext.close();

    return combined;
  }
    

int main () {
  int n;
  
  std::cout << "Version 3\n";
  std::cout << "Welcome to Password Creator\n";
  std::cout << "Length of the password: ";
  std::cin >> n;
  std::cout << passGen(n);
  
  return 0;
}
