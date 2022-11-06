class ReplaceDigits {

public String replaceDigits(String s) {
        StringBuilder sb = new StringBuilder();

        if(s.length() % 2 == 0){
            for(int i = 0; i < s.length(); i+=2){
                sb.append((char)(s.charAt(i)));
                sb.append((char)(s.charAt(i) + Integer.valueOf("" + s.charAt(i+1))));
            }
        }
        else{
            for(int i = 0; i < s.length() - 1; i+=2){
                sb.append((char)(s.charAt(i)));
                sb.append((char)(s.charAt(i) +
                                 Integer.valueOf("" + s.charAt(i+1))));
            }
            sb.append(s.charAt(s.length()-1));
        }

        return sb.toString();
    }

    public static void main(String args){

    }
}

