const express = require("express");
const Mongoose = require("mongoose");
const bodyParser = require("body-parser");

// Import our routes

const authRoutes = require("./routes/auth");
const postRoutes = require("./routes/posts");
//Initialize express

const app = express();

// initialize body-parser

app.use(bodyParser.json());

// Allow Cross Origin Resource Sharing(CORS). Read about CORS errors to understand this

app.use((req, res, next) => {
  res.setHeader("Access-Control-Allow-Origin", "*");
  res.setHeader(
    "Access-Control-Allow-Methods",
    "OPTIONS, GET, POST, PUT, PATCH, DELETE"
  );
  res.setHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");
  next();
});

app.use("/auth", authRoutes);
app.use("/posts", postRoutes);

// This is the error handling function

app.use((error, req, res, next) => {
  const message = error.message;
  const statusCode = error.statusCode || 500;
  res.status(statusCode).json({
    message: message,
  });
});

Mongoose.connect("mongodb://localhost:27017/nodetutorial", {
  useNewUrlParser: true,
  useUnifiedTopology: true,
})
  .then(() => {
    app.listen(3000);
  })
  .catch((err) => {
    console.log(err);
  });
