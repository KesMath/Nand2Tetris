import java.util.LinkedList;

class TruncateSentence {
    public String truncateSentence(String s, int k) {
        String[] strArr = s.split(" ");

        LinkedList<String> list = new LinkedList<String>();
        // load list
        for(int i = 0; i < strArr.length; i++){
            list.add(strArr[i]);
        }

        // pop off elements from the tail of the list
        // 1 <= k <= s.length();
        int diff = strArr.length - k;
        for(int i = 0; i < diff; i++){
            list.removeLast();
        }

        //convert back to string
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i < list.size(); i++){
            sb.append(list.get(i));
            sb.append(" ");
        }
        return sb.toString().trim();
    }

    public static void main(String args){

    }
}
