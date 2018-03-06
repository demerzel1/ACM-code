import java.math.*;
import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		int n,k;
		n=cin.nextInt();
		k=cin.nextInt();
		int maxx=Integer.MIN_VALUE;
		for(int i=0;i<n;i++){
			int a,b;
			a=cin.nextInt();
			b=cin.nextInt();
			int t;
			if(b<=k)
				t=a;
			else
				t=a-(b-k);
			maxx=Math.max(maxx,t);
		}
		System.out.println(maxx);
	}
}
