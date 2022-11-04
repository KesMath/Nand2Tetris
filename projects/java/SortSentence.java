class SortSentence {

    public String sortSentence(String s) {
        String[] strArr = s.split(" ");
        StringBuffer buff = new StringBuffer();
        TreeMap<Integer, StringBuffer> map = new TreeMap<Integer, StringBuffer>();
        for(String str: strArr){
            map.put(Integer.valueOf("" + str.charAt(str.length()-1)), new StringBuffer(str).deleteCharAt(str.length()-1));
        }
        
        for(Map.Entry<Integer, StringBuffer> entry : map.entrySet()) {
            System.out.println("Key: " + entry.getKey() + "\nValue: " + entry.getValue());
        }

        for(Map.Entry<Integer, StringBuffer> entry : map.entrySet()){
            buff.append(entry.getValue().toString());
            buff.append(" ");
        }
        return buff.toString().trim();
    }

    public static void main(String args){

    }

}
