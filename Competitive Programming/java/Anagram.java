import java.util.Scanner;
/*This java program is used to find whether the strings are is anagram(An anagram is a word or phrase
 *  formed by rearranging the letters of a different word or phrase, typically 
 *  using all the original letters exactly once) of each other or not or not.*/
public class Anagram {

	public static void main(String[] args) {
		
  Scanner sc=new Scanner(System.in);
     String a=sc.nextLine();
     String b=sc.nextLine();
    
      if(a.length()!=b.length())
      {
    	  System.out.println("Not Anagram");
      }
      else
      {
    	 boolean flag=true;
    	  int arr[]=new int[256];
    	  /*Storing Number of characters of string a in array according to ASCII values*/
    	  for(char e: a.toCharArray())
    	  {
    		  arr[(int)e]++;
    	  }
    	  /*Storing Number of characters of string b in array according to ASCII values*/
    	  for(char e: b.toCharArray())
    	  {
    		  arr[(int)e]--;
    	  }
    	  /*Comparing the arrays to find whether the characters are same or not in both strings*/
    	  for(int i=0;i<256;i++)
    	  {
    		  if(arr[i]!=0)
    		  {
    			  flag=false;
    		  }
    	  }
    	  if(!flag)
    	  {
    		  System.out.println("Not Anagram");
    	  }
    	  else
    		  System.out.println("Anagram");
      }
      sc.close();
	}

}