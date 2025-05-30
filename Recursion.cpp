
#include <iostream>
#include <string>
#include <vector>

std::string fib(int k)
{
   std::string str;
   std::string str2;
   std::string str3;

   
   if (k == 0) 
   {      
      str3 = "1";
      return str3;
   }
      
   if (k == 1)
   {
      str3 = "3";
      return str3;
   }
   
   str = fib(k - 1);
   str2 = fib(k - 2);
   int n = 0, n_ost = 0;
   std::string str4;
   for (int i = 0; i <= str.size()-1; ++i)
   {
      n_ost = n/10;
      n = std::atoi(&str[i]);     
      n = n * 5 + n_ost;
      str4.push_back((n % 10) + '0');
   }
   n_ost = n/10;
   if (n_ost>0)
      str4.push_back(n_ost + '0');

   str = str4;
   n = 0, n_ost = 0;
   int i = 0;
   int j = 0;
  
   while (i <= str.size() - 1 && j <= str2.size() - 1) {
      n_ost = n/10;
      n = str[i] - '0';      
      n= n + (str2[j] - '0');
      str3.push_back((n % 10) + '0');
      ++i;
      ++j;
   }
   while (i <= str.size() - 1)
   {
      n_ost = n/10;
      n = str[i] - '0';
      str3.push_back((n % 10) + '0');
      ++i;
   }
   while (j <= str2.size() - 1)
   {
      n_ost = n/10;
      n = str2[j] - '0';
      str3.push_back((n % 10) + '0');
      ++j;
   }

   n_ost = n/10;
   if(n_ost!=0)
      str3.push_back(n_ost + '0');

   return str3;
}

int main()
{
   std::string num;
   num = fib(39);
   for (int i = num.size() - 1; i >= 0; --i)
      std::cout << num[i];
   
}
