import java.io.*;
import java.util.*;




public class Main {
	
	static InputReader in = new InputReader(System.in);
	static PrintWriter out = new PrintWriter(System.out);
	
	static int n, l, b, mod;
	static int[] a;
	static int[][][] memo = new int[505][505][505];
	
	public static void main(String[] args) {

		n = in.nextInt();
		l = in.nextInt();
		b = in.nextInt();
		mod = in.nextInt();
		a = new int[n];
		for(int i=0; i<n; ++i)
			a[i] = in.nextInt();
		
		for(int i=0; i < 505; ++i) {
			for(int j=0; j < 505; ++j) {
				for(int k=0; k < 505; ++k) {
					memo[i][j][k] = -1;
				}
			}
		}
		
		System.out.println( cnt(0, 0, b) );
		
		out.close();
	}
	
	static int cnt(int i, int j, int b) {
		if(b < 0)
			return 0;
		if(i == n)
			return 0;
		if(j == l)
			return 1;
		
		if(memo[i][j][b] != -1)
			return memo[i][j][b];
		
		int ret = cnt(i, j+1, b - a[i]) + cnt(i+1, j, b);
		ret %= mod;
		return memo[i][j][b] = ret;
	}
}


class InputReader {

	private final InputStream stream;
	private final byte[] buf = new byte[8192];
	private int curChar, snumChars;

	public InputReader(InputStream st) {
		this.stream = st;
	}

	public int read() {
		if (snumChars == -1)
			throw new InputMismatchException();
		if (curChar >= snumChars) {
			curChar = 0;
			try {
				snumChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (snumChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int nextInt() {
		int c = read();
		while (isSpaceChar(c)) {
			c = read();
		}
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public long nextLong() {
		int c = read();
		while (isSpaceChar(c)) {
			c = read();
		}
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public int[] nextIntArray(int n) {
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		return a;
	}

	public String readString() {
		int c = read();
		while (isSpaceChar(c)) {
			c = read();
		}
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public String nextLine() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isEndOfLine(c));
		return res.toString();
	}

	public boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private boolean isEndOfLine(int c) {
		return c == '\n' || c == '\r' || c == -1;
	}

}