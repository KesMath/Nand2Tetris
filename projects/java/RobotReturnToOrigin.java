class RobotReturnToOrigin {

    public class Coordinates{
        private int x;
        private int y;

        public Coordinates(int xpos, int ypos){
            this.x = xpos;
            this.y = ypos;
        }

        public int getXPos(){
            return this.x;
        }

        public int getYPos(){
            return this.y;
        }

        public void moveX(int x){
            this.x += x;
        }

        public void moveY(int y){
            this.y += y;
        }

    }
    public boolean judgeCircle(String moves) {
        Coordinates origin = new Coordinates(0,0);

        HashMap<Character, Coordinates> movesMap = new HashMap<Character, Coordinates>();
        movesMap.put('U', new Coordinates(0,1));
        movesMap.put('D', new Coordinates(0,-1));
        movesMap.put('L', new Coordinates(-1,0));
        movesMap.put('R', new Coordinates(1,0));

        for(int i = 0; i < moves.length(); i++){
            if(movesMap.containsKey(moves.charAt(i))){
                origin.moveX(movesMap.get(moves.charAt(i)).getXPos());
                origin.moveY(movesMap.get(moves.charAt(i)).getYPos());
            }
        }
        return origin.getXPos() == 0 && origin.getYPos() == 0;
    }
}
