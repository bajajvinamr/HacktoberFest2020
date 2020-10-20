// Posts file in routes folder

const express = require("express");

// import our checkAuth Middleware
const checkAuth = require("../middlewares/checkAuth");

const postController = require("../controllers/posts");

const router = express.Router();

//A user needs to be logged in before a post can be added, so we would add our middleware to the endpoint
router.post("/add", checkAuth, postController.addPosts);

router.get("/", postController.fetchPosts);

module.exports = router;
