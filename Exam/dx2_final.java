import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class StudyCode {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++) {
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
            String data = br.readLine();
            StringTokenizer st = new StringTokenizer(data);

            String N = st.nextToken();
            String x = st.nextToken();
            String y = st.nextToken();

            StringBuilder ans = new StringBuilder("");
            int len = N.length();
            boolean flag = false;
            boolean canMake = true;
            char x_data = x.charAt(0);
            char y_data = y.charAt(0);

            if (x_data == '0') {
                if (len == 1){
                    if (N.charAt(0) >= y_data){
                        bw.write("#" + test_case + " " + y_data + "\n");
                    }
                    else{
                        bw.write("#" + test_case + " -1\n");
                    }

                    bw.flush();
                    continue;
                }

                if (N.charAt(0) < y_data){
                    for(int i = 0; i<len - 1; i++){
                        ans.append(y);
                    }

                    bw.write("#" + test_case + " " + ans + "\n");
                    bw.flush();
                    continue;
                }
            }

            Deque<String> deque = new ArrayDeque<>();

            for (int i = 0; i < len; i++) {
                char element = N.charAt(i);

                if (element > y_data) {
                    flag = true;
                    break;
                } else if (x_data < element && element < y_data) {
                    deque.add(x);
                    flag = true;
                    break;
                } else if (element < x_data){
                    while(true){
                        if (deque.size() == 0){
                            canMake = false;
                            break;
                        }

                        if (deque.removeLast().charAt(0) > x_data){
                            break;
                        }
                    }

                    if (!canMake){
                        break;
                    }
                    deque.add(x);
                    flag = true;
                    break;

                } else if (element == y_data){
                    deque.add(y);
                } else if (element == x_data){
                    deque.add(x);
                }
            }

            if (!canMake){
                for (int i = 0; i < len - 1; i++){
                    ans.append(y);
                }

                if (ans.toString().equals("")){
                    bw.write("#" + test_case + " -1\n");
                } else{
                    bw.write("#" + test_case + " " + ans + "\n");
                }

                bw.flush();
                continue;
            }

            for (String tmp : deque) {
                ans.append(tmp);
            }

            if (flag){
                int ans_length = ans.length();
                for(int i = ans_length; i< len; i++){
                    ans.append(y);
                }
            }

            if (ans.toString().equals("")){
                bw.write("#" + test_case + " -1\n");
            }
            else{
                bw.write("#" + test_case + " " + ans + "\n");
            }
            bw.flush();
        }
        bw.close();
    }
}
// 해당 코드의 접근방법을 간략히 서술합니다.

// 예를 들어 N = 623455 x = 1, y = 5 라고 가정해 봅시다.
// N[0] = 6이고 y보다 크기 때문에 모든 자릿수에 y를 붙이면 그것이 최대 수가 될 것입니다.

// N = 143455, x = 1, y = 5
// N[0] = 1이고 x와 같기 때문에 1을 추가합니다.
// N[1] = 4이고 x보다 크고 y보다 작기 때문에 x인 1을 추가합니다. x, y 두 수를 사용해야만 하기 때문입니다.
// 그럼 11xxxx이 될 것입니다. 이미 이 시점에서 만들어진 수가 N보다 작다는 것이 보장되어 있기 때문에 다음 자릿수부터는 무조건 y를 추가하면 될 것입니다. 즉 115555가 답이 될 것입니다.

// x < y라는게 조건에서 보장되어있었기 때문에 y를 어느 시점에서 붙여야 하는지를 알아내고 알아낸다면 그 이후의 자릿수를 모두 y로 바꾸어 붙이는 방식으로 접근하였습니다.