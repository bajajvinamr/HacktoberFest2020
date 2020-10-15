//Depth-First-Search-Recurive-Bactrack-Maze-Genertion-Algorithm.... :)
//Pseudocode:

//1.Make the initial cell the current cell and mark it as visited
//2.While there are unvisited cells :
//...If the current cell has any neighbours which have not been visited
//Choose randomly one of the unvisited neighbours
//Push the current cell to the stack
//Remove the wall between the current cell and the chosen cell
//Make the chosen cell the current cell and mark it as visited
//...Else if stack is not empty 
//Pop a cell from the stack
//Make it hte current cell

// KEEP CALM AND LOVE CODE...
// LOL

var path = [];
var cols, rows;
var w = 30;
var maze = [];
var current;
var stack = [];


function setup() {
    var canvas = createCanvas(450,450);
    canvas.parent("hold");
    cols = floor(width/w);
    rows = floor(height/w);

    
    for(var r = 0; r < rows; r++ ){
        for(var c = 0; c < cols; c++){
            var cell = new Cell(c,r);
            maze.push(cell);
            
        }
    }
    
    current = maze[0];
}

function draw() {
    background(50);
    for(var i = 0; i < maze.length; i++){
        maze[i].show();
    }
    
    current.visited = true;
    current.highlight();
    
    var next = current.checkNeighbours();
    if(next){
        next.visited = true;
        stack.push(current);
        removeWalls(current, next);
        current = next;
    }else if (stack.length > 0) {

    current = stack.pop();   

  }
    
}


function place(c,r){
    if(r < 0 || c < 0 || r > cols -  1 || c > rows - 1){
        return -1
       }else{
           return c + r*cols;
       }
}

function Cell(c,r){
    this.r = r;
    this.c = c;
    this.walls = [true, true, true, true];
    this.visited = false;
    
    this.checkNeighbours = function(){
        var neighbours = []; 
        
        var top    = maze[place(c, r - 1)];
        var right  = maze[place(c+1, r)];
        var bottom = maze[place(c, r + 1)];
        var left   = maze[place(c-1, r)];
        
        if(top && !top.visited){
            neighbours.push(top);
        }
        if(right && !right.visited){
            neighbours.push(right);
        }
        if(bottom && !bottom.visited){
            neighbours.push(bottom);
        }
        if(left && !left.visited){
            neighbours.push(left);
        }
        
        if(neighbours.length > 0){
            var x = floor(random(0, neighbours.length));
            return neighbours[x];
        }
        else{
            return undefined;
        }
    }
    
    this.highlight = function() {

    var x = this.c*w;
    var y = this.r*w;
    noStroke();
    fill(0,255,255);
    rect(x, y, w, w);

  }
    
    
 this.show = function() {

    var x = this.c*w;
    var y = this.r*w;
    stroke(255); 

    if (this.walls[0]) {
      line(x    , y    , x + w, y);
    }

    if (this.walls[1]) {
     line(x + w, y    , x + w, y + w);
    }

    if (this.walls[2]) {
      line(x + w, y + w, x    , y + w);
    }

    if (this.walls[3]) {
      line(x    , y + w, x    , y);
    }

    if (this.visited) {

      noStroke();
      fill(255, 0, 100,100);
      rect(x, y, w, w);

    }

  }

}

function removeWalls(a, b) {

  var x = a.c - b.c;

  if (x === 1) {

    a.walls[3] = false;
    b.walls[1] = false;

  } else if (x === -1) {

    a.walls[1] = false;
    b.walls[3] = false;

  }

  var y = a.r - b.r;

  if (y === 1) {

    a.walls[0] = false;
    b.walls[2] = false;

  } else if (y === -1) {

    a.walls[2] = false;
    b.walls[0] = false;

  }

}  



