#pragma once
//#include "Screens.h"
#include <iostream>
using namespace std;
class logout
{
public:
	 void test()
	{
	}

	 static void loginOptions()
	 {
		 cout << "\t\t\t\t\t\tLogin As\n";
		 cout << "1 - Client\n\n";
		 cout << "2 - Employee\n\n";
		 cout << "3 - Admin\n\n";
		 cout << "4 - Exit\n\n";
	 }
	 static int loginAs()
	 {
		 int x;
		 cout << "Login As : ";
		 cin >> x;

		 switch (x)
		 {
		 case 1:
		 {
			 return 1;
			 break;
		 }
		 case 2:
		 {
			 return 2;
			 break;
		 }
		 case 3:
		 {
			 return 3;
			 break;
		 }
		 case 4:
		 {
			 return 4;
			 break;
		 }
		 default:
		 {
			 Invalid(x);
			 break;
		 }
		 }
	 }
	 static void Invalid(int c)
	 {
		 cout << "Your Choise Not Found In List\n";
		 loginAs();
	 }
};

