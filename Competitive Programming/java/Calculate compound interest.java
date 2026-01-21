public class JavaExample {

    public void calculate(int p, int t, double r, int n) {

        double amount = p * Math.pow(1 + (r / n), n * t);

        double cinterest = amount - p;

        System.out.println("Compound Interest after " + t + " years: "+cinterest);

        System.out.println("Amount after " + t + " years: "+amount);

    }

    public static void main(String args[]) {

    	JavaExample obj = new JavaExample();    	obj.calculate(2000, 5, .08, 12);

    }

}
