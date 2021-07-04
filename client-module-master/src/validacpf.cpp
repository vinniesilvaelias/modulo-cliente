#include "validacpf.h"

void split(string& data)
{
  string str = "";
  for (auto i: data)
  {
    if (isdigit(i)) str += i;
  }
  data = str;
}

int quoc(int sum)
{
  sum %= 11;
  return (sum < 2) ? 0: 11-sum;
}

int mult(char n1,int n2)
{
  return (n1-'0') * n2;
}

char getDigit(string data)
{
  reverse(data.begin(),data.end());
  int sum = 0, count = 2;
  for (auto i: data)
  {
          sum += mult(i,count);
          count++;
  }
  sum = quoc(sum) + '0';
  return sum;
}

bool valid(string data)
{
  split(data);
  if (data.length() != 11)
  {
    return false;
  }
  int checkDigits = stoi(data.substr(9,2));
  string str = data.substr(0,9);
  str += getDigit(str);
  str += getDigit(str);
  int result = stoi(str.substr(9,2));
  return checkDigits == result;
}
