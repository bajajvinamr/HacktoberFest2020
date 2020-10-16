package DataStructures.Lists;

/*
 * This class implements a SinglyLinked List. 
 * A linked list is similar to an array, it hold values.
 * However, links in a linked list do not have indexes. With
 * a linked list you do not need to predetermine it's size as
 * it grows and shrinks as it is edited. 
 *it has functions called mid that gives node at mid 
 * in addn to linked list there is algo that 
 * construct a linked list with alternate sums of linked list 
 * and added to new one and add mid value 
 * i.e sum of first and last value of inital list
 
 Test Case:
 
 
 LinkedList LL1 = new LinkedList();    
	        Scanner scn=new Scanner(System.in);
	        int numNodes=scn.nextInt();
	        for(int i=0;i<2*numNodes;i++) {
	        	LL1.addLast(scn.nextInt());
	        }    
	        LL1.display();    
	        LinkedList LL2=new LinkedList();
	        LL2.formLL2(LL1);
	        LL2.display();
	        LinkedList LL3=new LinkedList();
	        LL3.formLL3(LL1);
	        LL3.display();
	        Node MID=LL1.midValue();	        
	        System.out.println(MID.data);
	        LinkedList updLL1=new LinkedList();
	        updLL1.formRes(LL1,LL2,LL3,MID);
	        updLL1.display();
	        updLL1.size();
 
 */
 
import java.util.*;
import java.lang.*;
import java.io.*;

public class LinkedList {

	    private class Node{    
	        int data;    
	        Node next;    
	            
	        Node(int data) {    
	            this.data = data;    
	            this.next = null;    
	        }    
	    }
	    
	    private Node head;  
	    private Node tail;    
	    private int size;  
	    
	    public LinkedList() {
	    	head = null;
		tail = null;
		size = 0;
	    }
	    
	    public void addLast(int data) {    
	        Node newNode = new Node(data);    
	            
	        if(this.head == null) {    
	            this.head = newNode;    
	            this.tail = newNode;  
	            this.size++;
	        }    
	        else {    
	            this.tail.next = newNode;    
	            this.tail = newNode;    
	            this.size++;
	        }    
	    }    
	    
	        
	    public void display() {    
	        Node current = this.head;    
	        if(this.head == null) {    
	            return;    
	        }    
	        while(current != null) {    
	            System.out.print(current.data + " ");    
	            current = current.next;    
	        }    
	        System.out.println();    
	    }    
	    
	    public void formLL2(LinkedList LL1) {
	    	Node current=LL1.head;
	    	while(current.next!=null&&current.next.next!=null) {
	    		int sum=current.data+current.next.next.data;
	    		this.addLast(sum);
	    		current=current.next.next;
	    	}	
	    }
	    
	    public void formLL3(LinkedList LL1) {
	    	Node current=LL1.head.next;
	    	while(current.next!=null&&current.next.next!=null) {
	    		int sum=current.data+current.next.next.data;
	    		this.addLast(sum);
	    		current=current.next.next;	    		
	    	}	
	    }
	    
	    public Node mid() {
	    	Node slow=this.head;
	    	Node fast=this.head;
	    	while(fast.next!=null && fast.next.next!=null) {
	    		slow=slow.next;
	    		fast=fast.next.next;
	    	}
	    	return slow;
	    }
	    
	    public Node midValue() {
	    	int sum=this.head.data+this.tail.data;
	    	Node mid=new Node(sum);
	    	return mid;
	    }
	    
	    public void formRes(LinkedList LL1,LinkedList LL2,LinkedList LL3,Node MID) {
	    	Node LL1mid=LL1.mid();
	    	Node currentLL1=LL1.head;
	    	Node currentLL2=LL2.head;
	    	Node currentLL3=LL3.head;
	    	while(currentLL1!=null) {
    			this.addLast(currentLL1.data);

	    		if(currentLL2!=null) {
	    			this.addLast(currentLL2.data);
	    			currentLL2=currentLL2.next;
	    		}else if(currentLL1.equals(LL1mid)) {
	    			this.addLast(MID.data);
	    		}
	    		else if(currentLL2==null&&currentLL3!=null) {
	    			this.addLast(currentLL3.data);
	    			currentLL3=currentLL3.next;
	    		}
    			currentLL1=currentLL1.next;	
	    	}
	    }
	    
	    public void size() {
	    	System.out.println(this.size);
	    }
  }
