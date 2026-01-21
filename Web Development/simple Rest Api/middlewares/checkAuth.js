// checkAuth.js file in middlewares folder

const User = require("../models/user");
const jwt = require("jsonwebtoken");

module.exports = (req, res, next) => {
  // The token is sent through an header labelled authorization

  const authHeader = req.get("Authorization");

  if (!authHeader) {
    const error = new Error("A token is needed with this request");
    error.statusCode = 401;
    throw error;
  }

  // If we get here, then the token was present, so we retrive it and verify to see if it is legit
  // The token is sent in this format "Bearer bhhchvcgjvgjbjcgjcvhb" so lets split the header to retrive the token

  const token = req.get("Authorization").split(" ")[1];

  let decodedToken;
  // Now we decode the token using jwt and store it in the variable decodedToken
  try {
    decodedToken = jwt.verify(token, "Thegreywolfsecret");
  } catch (err) {
    err.statusCode = 401;
    throw err;
  }

  // if we get here, it means the token was decoded successfully and legit. so lets get the user details
  // associated with the token. and save it as a request header that would be added to all requests that need auth.

  const userId = decodedToken.userId;

  User.findById(userId)
    .then((user) => {
      req.user = user;
      next();
    })
    .catch((err) => {
      if (!err.statusCode) {
        err.statusCode = 500;
      }
      next(err);
    });
};
