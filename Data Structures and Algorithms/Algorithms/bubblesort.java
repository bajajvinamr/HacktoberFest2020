import java.util.ArrayList;
import java.util.Random;

public class bubblesort {

    public static void BubbleSort(ArrayList<Integer> v){
        int size = v.size();
        int aux;
        
        for (int i = 0; i < size-1; i++){
            for (int j = 0; j < size-i-1; j++){
                if (v.get(j) > v.get(j+1)){
                    aux = v.get(j);
                    v.set(j, v.get(j+1));
                    v.set(j+1,aux);
                }
            }
        }
    }
    public static void main(String[] args) {
        ArrayList<Integer> v = new ArrayList<>();
        Random r = new Random();
        int size = 10;
        
        System.out.print("Initial values on vector: ");
        for (int i = 0; i < size; i++){
            Integer random_int = r.nextInt(50);
            v.add(random_int);
            System.out.print(random_int+" ");
        }
        System.out.println("");
        
        BubbleSort(v);
        
        System.out.print("Ordered vector: ");
        for (int i = 0; i < size; i++){
            System.out.print(v.get(i)+" ");
        }
    }
    
}
