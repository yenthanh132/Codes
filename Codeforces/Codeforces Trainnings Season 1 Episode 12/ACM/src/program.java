import java.math.BigInteger;
import java.util.Scanner;

public class program {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		while (T-- > 0) {
			int n = scan.nextInt();
			BigInteger x = BigInteger.valueOf(1);
			while (x.toString().length() < n)
				x = x.multiply(BigInteger.valueOf(4));
			System.out.println(x.toString() + x.toString());
		}
		scan.close();
	}
}
