import java.io.*;
import java.math.*;
import java.util.*;

class j
{
	public static void main(String args[])throws IOException
	{
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Scanner sc = new Scanner(System.in);

		int n,t;
		t = sc.nextInt();
		while(t!=0)
		{
			n = sc.nextInt();
			int a[] = new int[n+1];
			for(int i=1;i<=n;++i)
			{
				a[i] = sc.nextInt();
			}
			
			int count=0;

			for(int i=1;i<=n;++i)
			{
				for(int j=i+1;j<=n;++j)
				{
					BigInteger bi = BigInteger.valueOf(a[i]);
					BigInteger bj = BigInteger.valueOf(a[j]);
					BigInteger m =  bi.multiply(bj);//.())
					BigInteger s = bi.add(bj);
					if(m.compareTo(s)==0)
						count++;	
				}
			}
			System.out.println(count);
			t--;
		}
	}
}