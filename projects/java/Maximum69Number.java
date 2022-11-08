class Maximum69Number {
    public static final int ASCII_DIGIT_OFFSET = 48;
    public static final int THREE = 3;
    public static final int SIX = 6;

    public int maximum69Number (int num) {
        int max = num;
        int tmpComparator = 0;
        String numStr = Integer.toString(num);
        for(int i = numStr.length() - 1, base10 = 1; i >= 0; i--, base10*=10){
            char digit = numStr.charAt(i);
            if(digit == '6'){
                // tmpComparator will either be (positive) 3/30/300/3000
                tmpComparator = (((int)digit - ASCII_DIGIT_OFFSET) - THREE) * base10;
            }
            else if(digit == '9'){
                // tmpComparator will either be (negative) 3/30/300/3000
                tmpComparator = (((int)digit - ASCII_DIGIT_OFFSET) - SIX) * base10;
                tmpComparator *= -1;
            }
            tmpComparator += num;
            if(tmpComparator > max){
                max = tmpComparator;
            }
            // reset comparator
            tmpComparator = 0;
        }
        return max;
    }
}
