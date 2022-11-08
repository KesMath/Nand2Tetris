class IsPrefixOfWord {

    public boolean isPrefix(String needle, String haystack){
        //the subset (i.e. needle) cannot be greater than larger set (i.e. haystack)
        // the subset must be less than or equal to the entire set
        if(needle.compareTo(haystack) > 0){
            return false;
        }
        else{
            for(int i = 0; i < needle.length(); i++){
                if(needle.charAt(i) != haystack.charAt(i)){
                    return false;
                }
            }
            return true;
        }
    }
    public int isPrefixOfWord(String sentence, String searchWord) {
        String[] arr = sentence.split(" ");

        for(int i = 0; i < arr.length; i++){
            if(isPrefix(searchWord, arr[i])){
                return i + 1;
            }
        }
        return -1;
    }

}