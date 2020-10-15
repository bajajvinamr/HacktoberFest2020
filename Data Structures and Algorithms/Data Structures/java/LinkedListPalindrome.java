class Palindrome
{
    // Function to check if linked list is palindrome
    boolean isPalindrome(Node head) 
    {
        //Your code here
        Node slow=head;
        boolean flag=true;
        Stack<Integer> stack = new Stack<Integer>(); 
        while(slow!=null){
            stack.push(slow.data); 
            slow = slow.next;
        }
        while(head!=null){
            int i = stack.pop(); 
            if (head.data == i) { 
                flag = true; 
            } 
            else { 
                flag = false; 
                break; 
            } 
            head = head.next; 
        } 
        return flag; 
        }
        
    } 
