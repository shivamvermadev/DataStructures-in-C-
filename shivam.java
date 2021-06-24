import java.io.*;
public class shivam {

	public static int toInt(String str) {
		return Integer.parseInt(str);
	}
	
	public static String[] input(BufferedReader br) throws IOException {
		return br.readLine().split("\\s+");
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input[] =  input(br);
		int r = toInt(input[0]);
		int d[] = new int[3];
		int x[] = new int[4];
		x[0]=r;
		
		for(int i=1;i<=3;i++) {
			d[i-1]= toInt(input[i]);
			x[i]= x[i]+ d[i-1];
			
		}
		
		input= input(br);
		int pos [] = new int[4];
		for(int i=0;i<4;i++)
		{
			pos[i]= toInt(input[i]);
			if(pos[i]==90)
				pos[i]=270;
			else
			if(pos[i]==270)
				pos[i]=90;
		}
		
		input= input(br);
		int vel[] = new int[4];
		for(int i=0;i<4;i++)
			vel[i] = toInt(input[i]);
		
		input=input(br);
		int dir[] = new int[4];
		for(int i=0;i<4;i++)
		{
			dir[i]= toInt(input[i]);
		}

		
		int time = toInt(br.readLine());
		
		
		
		double pointX[] = new double[4];
		double pointY[] = new double[4];
		
		for(int i=0;i<4;i++)
		{
			double point[] = getPoint(r,pos[i],vel[i],dir[i],time);
			pointX[i] = point[0];
			pointX[i]+=x[i];
			if(i!=0)
				pointX[i]+=x[0];
			pointY[i] = point[1];
			
			pointY[i]=pointY[i]+(-r); //orgin change
			
			
		}
		
		double totalDis=0;
		for(int i=1;i<=3;i++)
		{
			totalDis+= dis(pointX[i-1],pointY[i-1],pointX[i],pointY[i]);
		}
		System.out.print(Math.round(totalDis*10)/10);
		System.out.println(totalDis);
	}
	
	/*
	 
10 25 50 75
0 0 0 0
1 1 1 1
1 1 1 1
90

	 */
	
	public static double dis(double x1, double y1, double x2, double y2) {
		double dis= Math.pow(x2-(x1),2 )+ Math.pow(y2-(y1), 2);
		
		dis = Math.sqrt(dis);
		return dis;
	}
	public static double[] getPoint(int r,int startPos, int vel, int dir, int time) {
		double point[] = new double[2];
		int theta =0;
		int totalDis = time*vel+startPos;
		theta = (totalDis)%360;
		if(dir==0)
		{
			theta= 360-theta;
		}
		
		if(theta==90)
			theta=270;
		else
		if(theta==270)
			theta=90;
		
	//	System.out.println(round(Math.cos(theta))+" "+round(Math.sin(Math.toRadians(theta)))+" "+r);
		point[0] = r*round(Math.cos(Math.toRadians(theta)));
		point[1] = r*round(Math.sin(Math.toRadians(theta)));
	//	System.out.println(theta+" th");
		return point;
	}

	
	public static double round(double num) {
		
		int roundValue =10000;
		 return Math.round(num * roundValue)/roundValue;
	}
}
