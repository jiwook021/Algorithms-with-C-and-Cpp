#include <iostream>
#include <regex>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

struct Coefficient{
  double a, b, c;
};

vector<string> splitPolynomial(string& poly){
  vector<string> terms;
  size_t start = 0;
  int bracketCount = 0;
  int absCount = 0;
  for(size_t i = 0; i < poly.size(); ++i){
    if(poly[i] == '('){
      bracketCount++;
    } else if(poly[i] == ')'){
      bracketCount--;
    } else if(poly[i] == '|'){
      absCount = 1 - absCount;
    } else if((poly[i] == '+' || poly[i] == '-') && bracketCount == 0 && absCount == 0){
      terms.push_back(poly.substr(start, i - start));
      start = i;
    }
  }
  terms.push_back(poly.substr(start));
  return terms;
}

bool hasNumber(string& s){
  return any_of(s.begin(), s.end(), ::isdigit);
}

bool containsAsterisk(string& s){
  return s.find('*') != string::npos;
}

string removeSpaces(string s){
  string result = s;
  result.erase(remove(result.begin(), result.end(), ' '), result.end());
  return result;
}

string replaceLogWithValues(const string& s){
  regex r("log\\(([^)]+)\\)");
  smatch match;
  string result = s;

  while(regex_search(result, match, r)){
    double value = stod(match[1]);
    double logValue = log(value);
    ostringstream os;
    os << fixed << setprecision(3) << logValue;
    result.replace(match.position(), match.length(), os.str());
  }
  return result;
}


Coefficient calc(string s){
  Coefficient result;
  result.a = result.b = result.c = 0.0;
  regex r_coeff_x2("([-+]?\\d*\\.?\\d*)\\s*\\*?\\s*x\\^2");
  regex r_coeff_x("([-+]?\\d*\\.?\\d*)\\s*\\*?\\s*x");
  regex r_constant("([-+]?\\d+\\.?\\d*)");
  vector<string> tokens = splitPolynomial(s);
  for(auto& token : tokens){
    if((token[0] == '|' || token[1] == '|') && token[token.size() - 1] == '|'){
      double sign = token[0] == '-' ? -1.0 : 1.0;
      size_t start = token[0] == '|' ? 0 : 1;
      double val = sign * abs(stod(token.substr(start + 1, token.size() - start - 2)));
      result.c += val;
    } else if(regex_match(token, r_coeff_x2)){
      if(!hasNumber(token)){
        int val = token[0] == '-' ? -1 : 1;
        result.b += double(val);
        continue;
      }
      int len = containsAsterisk(token) ? 4 : 3;
      token.erase(token.end() - len, token.end());
      result.a += double(stod(token));
    } else if(regex_match(token, r_coeff_x)){
      if(!hasNumber(token)){
        int val = token[0] == '-' ? -1 : 1;
        result.b += double(val);
        continue;
      }
      int len = containsAsterisk(token) ? 2 : 1;
      token.erase(token.end() - len, token.end());
      result.b += stod(token);
    } else if(regex_match(token, r_constant)){
      result.c += stod(token);
    }
  }
  return result;
}

Coefficient getEquation(string s){
  string trimedS = removeSpaces(s);
  size_t pos = trimedS.find('=');
  string leftEquation = trimedS.substr(0, pos);
  string rightEquation = trimedS.substr(pos + 1);
  Coefficient leftResult = calc(replaceLogWithValues(leftEquation));
  Coefficient rightResult = calc(replaceLogWithValues(rightEquation));
  Coefficient result;
  cout << leftResult.a << " " << leftResult.b << " " << leftResult.c << endl;
  cout << rightResult.a << " " << rightResult.b << " " << rightResult.c << endl;
  result.a = rightResult.a - leftResult.a;
  result.b = rightResult.b - leftResult.b;
  result.c = rightResult.c - leftResult.c;
  return result;
}

int main(){
  string s = "|-30|+log(10)*x+10*x^2  = 2 x ^ 2 + log(1 0) * x -x-10*x^2+1-2-|-log(10)|";
  Coefficient res = getEquation(s);
  cout << res.a << " " << res.b << " " << res.c << endl;
  return 0;
}