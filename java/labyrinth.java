//014. Labyrinth

import java.util.Scanner;

public class labyrinth {
    public static void main(String[] args) {
        Scanner in= new Scanner(System.in);
        int n;
        int m;
        int count=0;
        n=in.nextInt();
        m=in.nextInt();
        for(int i=1;i<=n;i++){
                String s;
                char ch;
                s=in.next();
                for(int k=0;k<n;k++){
                    ch=s.charAt(k);
                    if(ch=='x'){
                         count++;
                }
            }
        }System.out.println(count);
        in.close();
    }
}
