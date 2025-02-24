import java.util.*;
public class Candies{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t;
        t=sc.nextInt();
        while(sc.hasNextInt()){
            int a;
            a=sc.nextInt();
            System.out.println(t-a);
            t=a;
        }
    }
}