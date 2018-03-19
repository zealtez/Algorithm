
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int cnt = 0;
		int N = scan.nextInt();
		int buffer = 0;
		
		if(N <= 9 && N > 0){
			buffer += N*11;
			cnt += 1;
		}
		else if(N == 0){
			System.out.println("0");
			return ;
		}else{
			buffer = N;
		}
		
		for(;;){
		
			int temp = (buffer/10) + buffer%10;
			buffer = (buffer%10)*10 + temp%10;
			cnt++;
			//System.out.print(buffer + " ");
			if(buffer == N)
				break;
		}
		System.out.println(cnt);
		
	}

}
