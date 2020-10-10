/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class UCL
{
	public static void main (String[] args) throws java.lang.Exception
	{
	try {
	   BufferedReader buf=new BufferedReader(new InputStreamReader(System.in));
	   int T;
	   T=Integer.parseInt(buf.readLine());
	   if(T>=1 && T<=50)
	   {
	       int answers=2*T;
	       String finalstandings[]=new String[answers];
	       int c=0;
	   for(int i=0;i<T;i++) //variables for storing database
	   {
	   String Results[]=new String[12];
	   String Hometeam[]=new String[12];
	   String Awayteam[]=new String[12];
	   int homescore[]=new int[12];
	   int awayscore[]=new int[12];
	   String teams[]=new String[4];
	   String tempteams[]=new String[12];
	   int Points[]=new int[4];
	   int GD[]=new int[4];
	   int len;
	   int firstspace;
	   int lastspace;
	   String first;
	   String second;
	   int secondspace;
	   int thirdspace;
	   int j=0;
	   int k=0;
	   String firstf;
	   String secondf;
	   String score1;
	   String score2;
	    for(j=0;j<12;j++)
	   {
	       Results[j]=buf.readLine();
	   }
	   j=0;
	   for(j=0;j<12;j++) //entering database
	   {
	       len=Results[j].length();
	       firstspace=Results[j].indexOf(' ');
	       lastspace=Results[j].lastIndexOf(' ');
	       first=Results[j].substring(0,firstspace);
	       second=Results[j].substring(lastspace+1,len);
	       firstf=first.toLowerCase();
	       secondf=second.toLowerCase();
	       if(first.length()<11 && second.length()<11)
	       {
	       Hometeam[j]=firstf;
	       tempteams[j]=firstf;
	       Awayteam[j]=secondf;
	       }
	       else if(first.length()>10)
	       {
	           Hometeam[j]=firstf.substring(0,10);
	           tempteams[j]=firstf.substring(0,10);
	       }
	       else if(second.length()>10)
	       Awayteam[j]=secondf.substring(0,10);
	       secondspace=Results[j].indexOf(' ',firstspace+1);
	       thirdspace=Results[j].indexOf(' ',secondspace+1);
	       score1=Results[j].substring(firstspace+1,secondspace);
	       score2=Results[j].substring(thirdspace+1,lastspace);
	       int check1=Integer.parseInt(score1);
	       int check2=Integer.parseInt(score2);
	       if(check1>=0 && check1<=100 && check2>=0 && check2<=100)
	       {
	       homescore[j]=check1;
	       awayscore[j]=check2;
	       }
	   }
	   j=0;
	   k=0;
	   String qw;
	   for(j=0;j<12;j++)
	   {
	       for(k=0;k<12-j-1;k++)
	       {
	           if(tempteams[k].compareTo(tempteams[k+1])>0)
	           {
	            qw=tempteams[k];
	            tempteams[k]=tempteams[k+1];
	            tempteams[k+1]=qw;
	           }
	       }
	   }
	   int n=0;
	   for(int m=0;m<11;m++) //removing repetitive elements to get the names of teams
	   if(tempteams[m].equals(tempteams[m+1])==false)
	   teams[n++]=tempteams[m];
	   teams[n++]=tempteams[11];
	   j=0;
	   k=0;
	   for(j=0;j<12;j++) //points and GD based on Results
	   {
	       for(k=0;k<4;k++)
	       {
	           if (Hometeam[j].equals(teams[k]))
	           {
	               if(homescore[j]>awayscore[j])
	               {
	                   Points[k]=Points[k]+3;
	                   GD[k]=GD[k]+homescore[j]-awayscore[j];
	               }
	               else if(homescore[j]==awayscore[j])
	               {
	                   Points[k]=Points[k]+1;
	               }
	               else
	               {
	                   GD[k]=GD[k]-awayscore[j]+homescore[j];
	               }
	               }
	               else if(Awayteam[j].equals(teams[k]))
	               {
	                   if(homescore[j]>awayscore[j])
	                   {
	                       GD[k]=GD[k]-homescore[j]+awayscore[j];
	                   }
	                   else if(homescore[j]==awayscore[j])
	                   {
	                       Points[k]=Points[k]+1;
	                   }
	                   else{
	                       Points[k]=Points[k]+3;
	                       GD[k]=GD[k]+awayscore[j]-homescore[j];
	                   }
	               }
	           }
	       }
	       int x=0;
	       int y=0;
	       String temps;
	       int tempi;
	       int tempgg;
	       for(x=0;x<4;x++) //sorting teams based on Points
	       {
	       for(y=0;y<4-x-1;y++)
	       {
	        if(Points[y]>Points[y+1])
	        {
	            temps=teams[y];
	            tempi=Points[y];
	            tempgg=GD[y];
	            teams[y]=teams[y+1];
	            Points[y]=Points[y+1];
	            GD[y]=GD[y+1];
	            teams[y+1]=temps;
	            Points[y+1]=tempi;
	            GD[y+1]=tempgg;
	        }
	       }
	   }
	   x=0;
	   int max=Points[3];
	   int max2=Points[2];
	   int count1=0;
	   int count2=0;
	   for(x=0;x<4;x++)
	   {
	      if(Points[x]==max)
	      count1++;
	   }
	   if(count1 >1)
	   {
	       String tempaz;
	       int temgd;
	       int tempoints;
	       for(int xy=0;xy<4;xy++) //sorting teams based on GD 
	       {
	       for(int yz=0;yz<4-xy-1;yz++)
	       {
	        if(GD[yz]>GD[yz+1] && Points[yz]>=Points[yz+1])
	        {
	            temgd=GD[yz];
	            tempaz=teams[yz];
	            tempoints=Points[yz];
	     	    GD[yz]=GD[yz+1];
	            teams[yz]=teams[yz+1];
	            Points[yz]=Points[yz+1];
	            GD[yz+1]=temgd;
	            teams[yz+1]=tempaz;
	            Points[yz+1]=tempoints;
	   }}}}
	   x=0;
	   for(x=0;x<3;x++)
	   {
	       if(Points[x]==max2)
	       count2++;
	   }
	   if(count2 >1)
	   {
x=0;
y=0;
String temporary1;
int temporary2;
int temporary4;
     for(x=0;x<3;x++)
     {
         for(y=0;y<3-x-1;y++)
         {
             if(GD[y]>GD[y+1] && Points[y]>=Points[y+1])
             {
              temporary1=teams[y];
              temporary2=GD[y];
              temporary4=Points[y];
              teams[y]=teams[y+1];
              GD[y]=GD[y+1];
              Points[y]=Points[y+1];
              teams[y+1]=temporary1;
              GD[y+1]=temporary2;
              Points[y+1]=temporary4;
}}}}
	   finalstandings[c++]=teams[3];
	   finalstandings[c++]=teams[2];
}
for(int oi=0;oi<answers;oi=oi+2)
{
    System.out.println(finalstandings[oi]+" "+finalstandings[oi+1]);
}}} catch(NumberFormatException e) {
	}
	}
}

