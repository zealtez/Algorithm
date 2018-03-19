import java.util.Scanner;

public class Main {
	
	
	
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		scan.nextLine(); //입력 버퍼 비우기
		
		for(int i = 0; i<N; i++){
		String ox = new String();
		
		int sol = 0;
		int cnt = 0;
		ox = scan.nextLine();
			
			for(int j = 0; j<ox.length();j++){
				
				if(ox.charAt(j) == 'O'){
					cnt++;
					sol += cnt;
				}else{
					cnt=0;
				}
			}
			System.out.println(sol);
		}
		
	}

}
