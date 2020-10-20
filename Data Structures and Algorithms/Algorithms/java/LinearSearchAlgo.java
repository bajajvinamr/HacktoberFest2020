public class LinearSearchAlgo {
    
  public static int linearSearch(int[] array, int key) {    
            for(int i=0;i<array.length;i++) {    
                if(array[i] == key){    
                    return i;    
                }    
            }    
            return -1;    
  }    
  
  public static void main(String a[]){    

            int[] values= {102,320,430,150,170,32,34,50,90};
            int key = 32;
            if (linearSearch(values,key)==-1) {
               System.out.println("value not found");
            } else {
               System.out.println(key+" is found at index: "+linearSearch(values, key));    
            }
  }    
}    
