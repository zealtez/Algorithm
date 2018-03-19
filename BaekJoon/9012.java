import java.util.LinkedList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();
		scan.nextLine();
		
		while ((T--) != 0) {
			boolean fail = false;
			int start = 1;
			Stack S = new Stack();
			String str = scan.nextLine();
			for (int i = 0; i < str.length(); i++) {
				if (str.charAt(i) == '(') {
					S.push(start++);
				} else if (str.charAt(i) == ')') {
					if (S.top() == -1) {
						fail = true;
						break;
					} else {
						S.pop();
					}
				}
			}
			
			if(fail || S.top() != -1){
				System.out.println("NO");
			}else{
				System.out.println("YES");
			}
			
		}
	}

}

class Stack {
	LinkedList<Integer> Stack = new LinkedList<>();

	void push(int x) {
		Stack.add(x);
	}

	void pop() {
		Stack.removeLast();
	}

	int top() {
		if (Stack.isEmpty()) {
			return -1;
		} else {
			return Stack.getLast();

		}
	}
}
