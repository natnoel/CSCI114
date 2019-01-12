import java.text.NumberFormat;
import java.util.Locale;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author user
 *
 */
public class JavaCurrencyFormatter {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
        double payment = scanner.nextDouble();
        scanner.close();

        // Write your code here.
        NumberFormat nf = NumberFormat.getCurrencyInstance(new Locale("en", "US"));
        String us = nf.format(payment), 
        		india = NumberFormat.getCurrencyInstance(new Locale("en", "IN")).format(payment),
        		china = NumberFormat.getCurrencyInstance(Locale.CHINA).format(payment),
        		france = NumberFormat.getCurrencyInstance(Locale.FRANCE).format(payment);
        
        System.out.println("US: " + us);
        System.out.println("India: " + india);
        System.out.println("China: " + china);
        System.out.println("France: " + france);
	}

}
