/*


Luke Adams...


*/

var drawingOption = 0;
var allowDiagonals = true;
var canPassThroughCorners = false;
var cols = 50;
var rows = 50;
var percentWalls = (allowDiagonals ? (canPassThroughCorners ? 0.4 : 0.3) : 0.2);
var t;
var timings = {};
var gamemap;
var uiElements = [];
var paused = true;
var pathfinder;
var status = "";
var stepsAllowed = 0;
var runPauseButton;



function initaliseSearchExample(rows, cols) {

    mapGraphic = null;

    gamemap = new MapFactory().getMap(cols, rows, 10, 10, 410, 410, allowDiagonals, percentWalls);

    start = gamemap.grid[0][0];

    end = gamemap.grid[cols - 1][rows - 1];

    start.wall = false;

    end.wall = false;



    pathfinder = new AStarPathFinder(gamemap, start, end, allowDiagonals);

}



function setup() {

    startTime();



    if (getURL().toLowerCase().indexOf("fullscreen") === -1) {

        var canvas = createCanvas(600, 600);
        canvas.parent("hold");

    } else {

        var sz = min(windowWidth, windowHeight);
        var frame = createCanvas(sz, sz);
        frame.parent("hold");

    }

    console.log('A*');



    initaliseSearchExample(cols, rows);



    runPauseButton = new Button("Solve", 480, 40, 48, 30, runpause);

    uiElements.push(runPauseButton);

    uiElements.push(new Button("Regenerate", 470, 100, 80, 30, restart));




    recordTime("Setup");

}



function searchStep() {

    if (!paused || stepsAllowed > 0) {

        startTime();

        var result = pathfinder.step();

        recordTime("AStar Iteration");

        stepsAllowed--;



        switch (result) {

            case -1:

                status = "No Solution";

                logTimings();

                pauseUnpause(true);

                break;

            case 1:

                status = "Maze Solved:)";

                logTimings();

                pauseUnpause(true);

                break;

            case 0:

                status = "Solving..."

                break;
            
            case 2:
                
                status = "";
                
                break;

        }

    }

}



var mapGraphic = null;



function drawMap() {

    if (mapGraphic == null) {

        for (var i = 0; i < gamemap.cols; i++) {

            for (var j = 0; j < gamemap.rows; j++) {

                if (gamemap.grid[i][j].wall) {

                    gamemap.grid[i][j].show(color(255));

                }

            }

        }

        mapGraphic = get(gamemap.x, gamemap.y, gamemap.w, gamemap.h);

    }



    image(mapGraphic, gamemap.x, gamemap.y);

}



function draw() {



    searchStep();



    // Draw current state of everything

    background(255);



    doGUI();



    text( status, 200, 450);



    startTime();



    drawMap();



    for (var i = 0; i < pathfinder.closedSet.length; i++) {

        pathfinder.closedSet[i].show(color(255, 0, 0, 50));

    }



    var infoNode = null;



    for (var i = 0; i < pathfinder.openSet.length; i++) {

        var node = pathfinder.openSet[i];

        node.show(color(0, 255, 0, 50));

        if (mouseX > node.x && mouseX < node.x + node.width &&

            mouseY > node.y && mouseY < node.y + node.height) {

            infoNode = node;

        }

    }

    recordTime("Draw Grid");



    fill(0);

    if (infoNode != null) {

        text("f = " + infoNode.f, 430, 230);

        text("g = " + infoNode.g, 430, 250);

        text("h = " + infoNode.h, 430, 270);

        text("vh = " + infoNode.vh, 430, 290);



    }



    var path = calcPath(pathfinder.lastCheckedNode);

    drawPath(path);

}



function calcPath(endNode) {

    startTime();

    // Find the path by working backwards

    path = [];

    var temp = endNode;

    path.push(temp);

    while (temp.previous) {

        path.push(temp.previous);

        temp = temp.previous;

    }

    recordTime("Calc Path");

    return path;

}



function drawPath(path) {

    noFill();
    stroke(255, 0, 200);
    strokeWeight(gamemap.w / gamemap.cols / 2);
    beginShape();

    for (var i = 0; i < path.length; i++) {

        vertex(path[i].x + path[i].width / 2, path[i].y + path[i].height / 2);

    }

    endShape();

}

function clearTimings() {

    timings = {};

}


function startTime() {

    t = millis();

}


function recordTime(n) {

    if (!timings[n]) {

        timings[n] = {

            sum: millis() - t,

            count: 1

        };

    } else {

        timings[n].sum = timings[n].sum + millis() - t;
        timings[n].count = timings[n].count + 1;

    }

}



function logTimings() {

    for (var prop in timings) {

        if (timings.hasOwnProperty(prop)) {

            console.log(prop + " = " + (timings[prop].sum / timings[prop].count).toString() + " ms");

        }

    }

}





function SettingBox(label, x, y, isSet, callback) {

    this.label = label;
    this.x = x;
    this.y = y;
    this.isSet = isSet;
    this.callback = callback;



    this.show = function() {

        strokeWeight(1);
        stroke(0);
        noFill();
        ellipse(this.x + 10, this.y + 10, 20, 20);

        if (this.isSet) {

            fill(0);
            ellipse(this.x + 10, this.y + 10, 3, 3);

        }

        fill(0);
        noStroke();
        text(label, this.x + 25, this.y + 15);

    }



    this.mouseClick = function(x, y) {

        if (x > this.x && x <= this.x + 20 &&
            y > this.y && y <= this.y + 20) {
            this.isSet = !this.isSet;
            if (this.callback != null)
                this.callback(this);

        }

    }

}



function Button(label, x, y, w, h, callback) {

    this.label = label;
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
    this.callback = callback;



    this.show = function() {
        strokeWeight(2);
       // noFill();
        stroke(255, 100, 0);
        textSize(19);
        textAlign(CENTER);
        if(this.label == "Solve" || this.label == "Pause" ){
            ellipse(this.x + 30, this.y +15, w+ 60, h + 20);
        }
        else{
            ellipse(this.x + 43, this.y +15, w+ 60, h + 20);
        }
        text(this.label, this.x + 5, this.y + 5, this.w, this.h);
        

    }



    this.mouseClick = function(x, y) {

        if (this.callback != null &&
            x > this.x && x <= this.x + this.w &&
            y > this.y && y <= this.y + this.h) {
            this.callback(this);

        }

    }

}



function pauseUnpause(pause) {

    paused = pause;
    runPauseButton.label = paused ? "Solve" : "Pause";

}



function runpause(button) {

    pauseUnpause(!paused);

}



function restart(button) {

    logTimings();
    clearTimings();
    initaliseSearchExample(cols, rows);
    pauseUnpause(true);

}



function mouseClicked() {

    for (var i = 0; i < uiElements.length; i++) {
        uiElements[i].mouseClick(mouseX, mouseY);

    }
}



function doGUI() {

    for (var i = 0; i < uiElements.length; i++) {
        uiElements[i].show();

    }

}

function Spot(i, j, x, y, width, height, isWall, grid) {


   this.grid = grid;

    this.i = i;
    this.j = j;
    this.x = x;
    this.y = y;
    this.width = width;
    this.height = height;

    this.f = 0;
    this.g = 0;
    this.h = 0;
    this.vh = 0; //visual heuristic for prioritising path option

    this.neighbors = undefined;
    this.neighboringWalls = undefined;

    // Where did I come from?

    this.previous = undefined;

    // Am I an wall?

    this.wall = isWall;



    // Did the maze algorithm already visit me?

    this.visited = false;



    // Display me

    this.show = function(color) {

        if (this.wall) {

            fill(0);

            noStroke();



            if (drawingOption === 0) {

                ellipse(this.x + this.width * 0.5, this.y + this.width * 0.5, this.width * 0.5, this.height * 0.5);

            } else {

                rect(this.x, this.y, this.width, this.height);

            }



            stroke(0);

            strokeWeight(this.width / 2);



            var nWalls = this.getNeighboringWalls(this.grid);

            for (var i = 0; i < nWalls.length; i++) {

                var nw = nWalls[i];



                // Draw line between this and bottom/right neighbor walls

                if ((nw.i > this.i && nw.j == this.j) ||

                    (nw.i == this.i && nw.j > this.j)) {

                    line(this.x + this.width / 2,

                        this.y + this.height / 2,

                        nw.x + nw.width / 2,

                        nw.y + nw.height / 2);

                }



                // Draw line between this and bottom-left/bottom-right neighbor walls

                if (!canPassThroughCorners && (nw.j > this.j) &&

                    (nw.i < this.i || nw.i > this.i)) {

                    line(this.x + this.width / 2,

                        this.y + this.height / 2,

                        nw.x + nw.width / 2,

                        nw.y + nw.height / 2);

                }

            }

        } else if (color) {

            fill(color);

            noStroke();

            rect(this.x, this.y, this.width, this.height);

        }

    }



    this.getNeighbors = function() {

        if (!this.neighbors) {

            this.populateNeighbors();

        }

        return this.neighbors;

    }



    this.getNeighboringWalls = function(grid) {



        if (!this.neighboringWalls) {

            this.populateNeighbors();

        }



        return this.neighboringWalls;

    }



    //maybe should be static properties?

    var LURDMoves = [

        [-1, 0],

        [0, -1],

        [1, 0],

        [0, 1]

    ];

    var DiagonalMoves = [

        [-1, -1],

        [1, -1],

        [1, 1],

        [-1, 1]

    ];

    //references to the LURDMoves entries that would block the diagonal

    //if they are both walls and canPassThroughCorners = false

    var DiagonalBlockers = [

        [0, 1],

        [1, 2],

        [2, 3],

        [3, 0]

    ];



    //return node or null if request is out of bounds

    this.getNode = function(i, j) {

        if (i < 0 || i >= this.grid.length ||

            j < 0 || j >= this.grid[0].length) {

            return null;

        }

        return this.grid[i][j];

    }



    //populate neighbor move and neighbor wall arrays

    this.populateNeighbors = function() {

        this.neighbors = [];

        this.neighboringWalls = [];



        //Add Left/Up/Right/Down Moves

        for (var i = 0; i < 4; i++) {

            var node = this.getNode(this.i + LURDMoves[i][0], this.j + LURDMoves[i][1]);

            if (node != null) {

                if (!node.wall) {

                    this.neighbors.push(node);

                } else {

                    this.neighboringWalls.push(node);

                }

            }

        }



        //Add Diagonals



        for (var i = 0; i < 4; i++) {

            var gridX = this.i + DiagonalMoves[i][0];

            var gridY = this.j + DiagonalMoves[i][1];



            var node = this.getNode(gridX, gridY);



            if (node != null) {

                if (allowDiagonals && !node.wall) {

                    if (!canPassThroughCorners) {

                        //Check if blocked by surrounding walls

                        var border1 = DiagonalBlockers[i][0];

                        var border2 = DiagonalBlockers[i][1];

                        //no need to protect against OOB as diagonal move

                        //check ensures that blocker refs must be valid

                        var blocker1 = this.grid[this.i + LURDMoves[border1][0]]

                                                [this.j + LURDMoves[border1][1]];

                        var blocker2 = this.grid[this.i + LURDMoves[border2][0]]

                                                [this.j + LURDMoves[border2][1]];





                        if (!blocker1.wall || !blocker2.wall) {

                            //one or both are open so we can move past

                            this.neighbors.push(node);

                        }

                    }else {

                        this.neighbors.push(node);

                    }

                }

                if (node.wall) {

                    this.neighboringWalls.push(node);

                }

            }

        }

    }

}

function AStarPathFinder(map, start, end, allowDiagonals) {

    this.map = map;

    this.lastCheckedNode = start;

    this.openSet = [];

    // openSet starts with beginning node only

    this.openSet.push(start);

    this.closedSet = [];

    this.start = start;

    this.end = end;

    this.allowDiagonals = allowDiagonals;



    //This function returns a measure of aesthetic preference for

    //use when ordering the openSet. It is used to prioritise

    //between equal standard heuristic scores. It can therefore

    //be anything you like without affecting the ability to find

    //a minimum cost path.



    this.visualDist = function(a, b) {

        return dist(a.i, a.j, b.i, b.j);

    }



    // An educated guess of how far it is between two points



    this.heuristic = function(a, b) {

        var d;

        if (allowDiagonals) {

            d = dist(a.i, a.j, b.i, b.j);

        } else {

            d = abs(a.i - b.i) + abs(a.j - b.j);

        }

        return d;

    }



    // Function to delete element from the array

    this.removeFromArray = function(arr, elt) {

        // Could use indexOf here instead to be more efficient

        for (var i = arr.length - 1; i >= 0; i--) {

            if (arr[i] == elt) {

                arr.splice(i, 1);

            }

        }

    }



    //Run one finding step.

    //returns 0 if search ongoing

    //returns 1 if goal reached

    //returns -1 if no solution

    this.step = function() {



        if (this.openSet.length > 0) {



            // Best next option

            var winner = 0;

            for (var i = 1; i < this.openSet.length; i++) {

                if (this.openSet[i].f < this.openSet[winner].f) {

                    winner = i;

                }

                //if we have a tie according to the standard heuristic

                if (this.openSet[i].f == this.openSet[winner].f) {

                    //Prefer to explore options with longer known paths (closer to goal)

                    if (this.openSet[i].g > this.openSet[winner].g) {

                        winner = i;

                    }

                    //if we're using Manhattan distances then also break ties

                    //of the known distance measure by using the visual heuristic.

                    //This ensures that the search concentrates on routes that look

                    //more direct. This makes no difference to the actual path distance

                    //but improves the look for things like games or more closely

                    //approximates the real shortest path if using grid sampled data for

                    //planning natural paths.

                    if (!this.allowDiagonals) {

                        if (this.openSet[i].g == this.openSet[winner].g &&

                            this.openSet[i].vh < this.openSet[winner].vh) {

                            winner = i;

                        }

                    }

                }

            }

            var current = this.openSet[winner];

            this.lastCheckedNode = current;



            // Did I finish?

            if (current === this.end) {

                console.log("DONE!");

                return 1;

            }



            // Best option moves from openSet to closedSet

            this.removeFromArray(this.openSet, current);

            this.closedSet.push(current);



            // Check all the neighbors

            var neighbors = current.getNeighbors();



            for (var i = 0; i < neighbors.length; i++) {

                var neighbor = neighbors[i];



                // Valid next spot?

                if (!this.closedSet.includes(neighbor)) {

                    // Is this a better path than before?

                    var tempG = current.g + this.heuristic(neighbor, current);



                    // Is this a better path than before?

                    if (!this.openSet.includes(neighbor)) {

                        this.openSet.push(neighbor);

                    } else if (tempG >= neighbor.g) {

                        // No, it's not a better path

                        continue;

                    }



                    neighbor.g = tempG;

                    neighbor.h = this.heuristic(neighbor, end);

                    if (!allowDiagonals) {

                        neighbor.vh = this.visualDist(neighbor, end);

                    }

                    neighbor.f = neighbor.g + neighbor.h;

                    neighbor.previous = current;

                }



            }

            return 0;

            // Uh oh, no solution

        } else {

            console.log('no solution');

            return -1;

        }

    }

}

function MapFactory()

{

    this.maps = [];

    this.maps.push(MazeMap);



    this.getMap = function(cols, rows, x, y, w, h, allowDiagonals, percentWalls)

    {

        if(this.maps.length == 0) return undefined;



        var selected = floor(random(this.maps.length));

        return new this.maps[selected](cols, rows, x, y, w, h, allowDiagonals, percentWalls);

    }

}

function MazeMap(cols, rows, x, y, w, h, allowDiagonals, percentWalls) {

  this.cols = cols;

  this.rows = rows;

  this.x = x;

  this.y = y;

  this.w = w;
  this.h = h;

  this.allowDiagonals = allowDiagonals;



  this.grid = [];

  this.path = [];

  this.start = { x: 0, y: 0 };

  this.end = { x: cols - 1, y: rows - 1 };



  this.grid = [];

  for (var i = 0; i < this.cols; i++) {

      this.grid[i] = [];

      for (var j = 0; j < this.rows; j++) {

          this.grid[i][j] = new Spot(i, j, x + i * w /this.cols, y + j * h / this.rows, w / this.cols, h / this.rows, true, this.grid);

      }

  }

  // collumn and row

  var c = 0;

  var r = 0;

  var history = [[0, 0]];



  // As long as there is at least one location in history

  while (history.length) {

    var left = this.grid[c][r - 2];

    var right = this.grid[c][r + 2];

    var up = this.grid[c - 2] && this.grid[c - 2][r];

    var down = this.grid[c + 2] && this.grid[c + 2][r];

    var current = this.grid[c][r];

    current.visited = true;

    current.wall = false;



    var check = [] // The neighbors that need to be checked

    if (left && !left.visited) {

      check.push(left);

    }



    if (up && !up.visited) {

      check.push(up);

    }



    if (right && !right.visited) {

      check.push(right);

    }



    if (down && !down.visited) {

      check.push(down);

    }



    // If there is a valid neighbor location

    if (check.length) {

      history.push([c, r]);

      // We choose a random location to make a path

      var direction = check[Math.floor(Math.random() * check.length)];

      if (direction == left) {

        left.wall = false;

        this.grid[c][r - 1].wall = false;

        r -= 2;

      }



      else if (direction == up) {

        up.wall = false;

        this.grid[c - 1][r].wall = false;

        c -= 2;

      }



      else if (direction == right) {

        right.wall = false;

        this.grid[c][r + 1].wall = false;

        r += 2;

      }



      else if (direction == down) {

        down.wall = false;

        this.grid[c + 1][r].wall = false;

        c += 2;

      }

    }

    else {


      var next = history.pop();

      c = next[0];

      r = next[1];

    }

  }



  this.grid[cols - 1][rows - 2].wall = false;

  this.grid[cols - 2][rows - 1].wall = false;

  this.grid[this.end.x][this.end.y].wall = false;

  this.grid[this.start.x][this.start.y].wall = false;

}
// I am so tired...