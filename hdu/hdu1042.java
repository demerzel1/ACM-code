import java.math.*;
import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		BigInteger a[]=new BigInteger[10005];
		a[0]=BigInteger.ONE;
		for(int i=1;i<=10000;i++){
			a[i]=a[i-1].multiply(BigInteger.valueOf(i));
		}
		while(cin.hasNext()){
			int x=cin.nextInt();
			System.out.println(a[x]);
		}
	}
}
