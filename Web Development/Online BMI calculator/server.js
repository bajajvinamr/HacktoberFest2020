const exp = require("express");
const bp = require("body-parser")
const app = exp();
app.use(bp.urlencoded({extended: true}));

app.listen("3000", function(){console.log("The server is running on port 3000");});
app.get("/", function(req, res) {  res.sendFile("E:/Projects/WEB development Projects/Online BMI calculator/index.html");  });
app.post("/results", function(req, res)
  {
    var h = Number(req.body.height);
    var w = Number(req.body.weight);
    var r = w/(h*h) ;
    var s = (Math.round(r*100))/100;
    res.send("Your BMI is " + s + ".");
  }
);
