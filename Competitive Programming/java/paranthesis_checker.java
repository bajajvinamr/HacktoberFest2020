/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
public static boolean isValid(String str) {

if (str == null || str.length() == 0) {
return true;
}

int count = 0;
int i = 0;
while (i < str.length()) {
char ch = str.charAt(i);
if (ch == '('||ch=='{'||ch=='[') {
count++;
} else if (ch == ')'||ch=='}'||ch==']') {
if (count == 0)
return false;
else
count--;
}
i++;
}

if(count != 0)
return false;

return true;
}
public static void main (String[] args) {

Scanner sc =new Scanner(System.in);
int t=sc.nextInt();
while(t--!=0)
{
String a = sc.next();
if(isValid(a)){
System.out.println("balanced");
}
else{
System.out.println("not balanced");
	}
}}}
