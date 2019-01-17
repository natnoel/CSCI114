import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        String B=sc.next();
        /* Enter your code here. Print output to STDOUT. */
        System.out.println(A.length() + B.length());

        if (A.compareTo(B) > 0)
            System.out.println("Yes");
        else
            System.out.println("No");
        
        //System.out.println(A + ' ' + B + ' ' + A.compareTo(B));

        StringBuffer aBuffer = new StringBuffer(A);
        StringBuffer bBuffer =  new StringBuffer(B);
        aBuffer.setCharAt(0, Character.toUpperCase(A.charAt(0)));
        bBuffer.setCharAt(0, Character.toUpperCase(B.charAt(0)));
        System.out.println(aBuffer.toString() + ' ' + bBuffer.toString());
    }
}
