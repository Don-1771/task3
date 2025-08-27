
#include <iostream>
#include <string>
#include <vector>

//------------------------------------------------------------------------------------------
std::string function(int k) {

   std::string zero = "1";
   std::string first = "3";

   std::string result = first;

   if (k == 0)
      return zero;
   
   if (k == 1)
      return first;
  
   char ch;
   int n, ost_n = 0;
   while (k - 1) {
      for (int i = 0; i <= first.size() - 1; i++) {
         ch = first[i];
         n = atoi(&ch);
         n = n*5 + ost_n;
         result[i] = n%10 + '0';
         ost_n = n / 10;
      }
      if (ost_n)
         result.push_back(ost_n + '0');
      
      ost_n = 0;
      for (int i = 0; i <= zero.size() - 1; i++) {
         ch = zero[i];
         n = atoi(&ch);
         ch = result[i];
         n = n + atoi(&ch);
         result[i] = n%10 + '0';
         ost_n = n / 10;
      }

      int i = zero.size();
      while (ost_n) {
         
         if (result.size() - zero.size()) {
            ch = result[i];
            n = atoi(&ch);
            n += ost_n;
            result[i] = n%10 + '0';
            ost_n = n / 10;
            ++i;
         }
         else {
            result.push_back(ost_n + '0');
         }
      }
      
   

      zero = first;
      first = result;

      ch = result[0];
      n = atoi(&ch);
      if (n % 2 == 0)
         k++;

      k--;
   }

   std::reverse(result.begin(), result.end());

   return result;
}

//------------------------------------------------------------------------------------------
int main()
{
   std::string num;
   num = function(40);
   std::cout << num << std::endl;
}
