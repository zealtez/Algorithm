import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
		for(int i = 0; i<T; i++){
			int[] nums = {scan.nextInt(),scan.nextInt(),scan.nextInt()}; //이렇게 입력이 가능 하구나 
			
			if(nums[0] == nums[1]-nums[2]){
				System.out.println("does not matter");
			}
			else if(nums[0]> nums[1] - nums[2]){
				System.out.println("do not advertise");
			}else{
				System.out.println("advertise");
			}
		}
	}

}
