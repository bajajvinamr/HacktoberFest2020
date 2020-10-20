// Posts file in controllers folder

const Post = require("../models/post");
// Controller to add a post

exports.addPosts = (req, res, next) => {
  const { title, body } = req.body;
  const post = new Post({
    name: req.user.fullname,
    title: title,
    body: body,
  });

  post
    .save()
    .then(() => {
      res.status(201).json({
        message: "Post added Successfully",
      });
    })
    .catch((err) => {
      if (!err.statusCode) {
        err.statusCode = 500;
      }
      next(err);
    });
};

exports.fetchPosts = (req, res, next) => {
  Post.find()
    .then((posts) => {
      res.status(200).json({
        message: "Posts fetched successfully",
        posts: posts,
      });
    })
    .catch((err) => {
      if (!err.statusCode) {
        err.statusCode = 500;
      }
      next(err);
    });
};
