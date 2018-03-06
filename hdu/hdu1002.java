import java.math.*;
import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		int T=cin.nextInt();
		for(int cas=1;cas<=T;cas++){
			BigInteger a,b;
			a=cin.nextBigInteger();
			b=cin.nextBigInteger();
			BigInteger c=a.add(b);
			System.out.println("Case "+cas+":");
			System.out.println(a+" + "+b+" = "+c);
			if(cas!=T)
				System.out.println("");
		}
	}
}
