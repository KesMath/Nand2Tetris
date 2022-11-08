class ConcatenationOfArray {
    public int[] getConcatenation(int[] nums) {
        int[] concatArray = new int[nums.length*2];
        for(int i = 0; i < concatArray.length; i++){
            concatArray[i] = nums[i % (nums.length)];
        }
        return concatArray;
    }
}
