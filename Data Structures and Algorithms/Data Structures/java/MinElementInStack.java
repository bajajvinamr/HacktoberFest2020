class GfG
{
    int minEle=-1;
    Stack<Integer> s=new Stack<>();
    /*returns min element from stack*/
    int getMin()
    {
       return minEle;
    }
    
    /*returns poped element from stack*/
    int pop()
    {
        int p=-1;
         if (s.isEmpty()) 
        { 
            
            return p; 
        } 
  
        else
        {
            
            v=s.peek();
            s.pop();
            if(s.empty())
            {
                minEle=-1;
                return p;
            }
            else
            {
                //Stack<Integer> s2=new Stack<>();
                 Stack<Integer> s2 = (Stack)s.clone();
                
                
                    minEle=s2.peek();
                    s2.pop();
                    while(!s2.empty())
                    {
                        if(s2.peek()<minEle)
                        {
                            minEle=s2.peek();
                        }
                        s2.pop();
                    }
               
                return p;
            
            }
            
        }
    }
    /*push element x into the stack*/
    void push(int x)
    {
        if(s.empty())
        {
            minEle=x;
            s.push(x);
        }
        else
        {
            if(x<minEle)
            {
                minEle=x;
            }
            s.push(x);
            
        }
    }	
}