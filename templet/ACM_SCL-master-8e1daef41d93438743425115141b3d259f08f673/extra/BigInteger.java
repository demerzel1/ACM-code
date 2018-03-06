BigInteger tmp = new BigInteger("32");

public static final BigInteger ZERO
public static final BigInteger ONE
public static final BigInteger TEN

public static BigInteger valueOf(long val)
public BigInteger add(BigInteger val)
public BigInteger subtract(BigInteger val)
public BigInteger multiply(BigInteger val)
public BigInteger divide(BigInteger val)
public BigInteger pow(int exponent)
public BigInteger gcd(BigInteger val)
public BigInteger abs()
public BigInteger negate()//-this
public int signum()//-1,0,1
public BigInteger mod(BigInteger m)
public BigInteger modPow(BigInteger exponent,BigInteger m)
public BigInteger modInverse(BigInteger m)

public BigInteger shiftLeft(int n)//this<<n
public BigInteger shiftRight(int n)//this>>n
public BigInteger and(BigInteger val)
public BigInteger or(BigInteger val)
public BigInteger xor(BigInteger val)
public BigInteger not()//~this

public int compareTo(BigInteger val)
//-1,0,1:less than, equal to, greater than

public boolean equals(Object x)
public BigInteger min(BigInteger val)
public BigInteger max(BigInteger val)
public int intValue()
public long longValue()
public double doubleValue()