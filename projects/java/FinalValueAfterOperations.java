class FinalValueAfterOperations {

    public int finalValueAfterOperations(String[] operations) {
        HashMap<String, Integer> operationMap = new HashMap<String, Integer>();
        int valofX = 0;
        operationMap.put("X--", -1);
        operationMap.put("--X", -1);
        operationMap.put("++X", 1);
        operationMap.put("X++", 1);

        for(String op : operations){
            if(operationMap.containsKey(op)){
                valofX += operationMap.get(op);
            }
        }
        return valofX;
    }

    public static void main(String args){

    }

}