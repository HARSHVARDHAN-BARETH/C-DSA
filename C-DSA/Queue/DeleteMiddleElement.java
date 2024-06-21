import java.util.Stack;

public class DeleteMiddleElement {
    
    public static void solve(Stack<Integer> inputStack, int count, int size) {
        if(count == size / 2) {
            inputStack.pop();
            return;
        }

        int num = inputStack.pop();
        solve(inputStack, count + 1, size);
        inputStack.push(num);
    }

    public static void deleteMiddle(Stack<Integer> inputStack, int N) {
        int count = 0;
        solve(inputStack, count, N);
    }

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);

        deleteMiddle(stack, stack.size());

        while(!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
    }
}
