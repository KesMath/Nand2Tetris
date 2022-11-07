class MostWordsFound {
    public int mostWordsFound(String[] sentences) {
        int max = 0;
        int tmp = 0;

        for(String s : sentences){
            String[] strArr = s.split(" ");
            for(String str: strArr){
                tmp++;
            }
            if(tmp > max){
                max = tmp;
            }
            tmp = 0;
        }

        return max;
    }

    public static void main(String args){

    }
}
