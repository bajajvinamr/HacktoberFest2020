//Auth file in controllers folder

const User = require("../models/user");
const bcrypt = require("bcrypt");
const jwt = require("jsonwebtoken");

// Let's write a controller function for signup

exports.signUp = (req, res, next) => {
  const { fullname, email, password, cPassword } = req.body;

  // Ensure that the password and the confirmed password match

  if (password !== cPassword) {
    const error = new Error("Password Mismatch");
    error.statusCode = 422;
    throw error;
  }

  // check if a user with the received email already exists

  User.findOne({ email: email })
    .then((existingUser) => {
      if (existingUser) {
        const error = new Error("User already exists");
        error.statusCode = 422;
        throw error;
      }

      // if we get to this block, it means user does not exist. lets hash the password using bcrypt and return a promise
      return bcrypt.hash(password, 12);
    })
    .then((hashedPass) => {
      // We will receive an hashed password in this then block. Let's create a new user using that hashed password

      const user = new User({
        fullname: fullname,
        email: email,
        password: hashedPass,
      });

      return user.save();
    })
    .then(() => {
      res.status(201).json({
        message: "New User Created",
      });
    })
    .catch((err) => {
      if (!err.statusCode) {
        err.statusCode = 500;
      }
      next(err);

      // We will create an error handling function in the app.js file
    });
};

// Now a controller function for login

exports.logIn = (req, res, next) => {
  const { email, password } = req.body;

  let fetchedUser;
  // First, we get the user with this email from our database and store it in the fetchedUser variable
  // declared above, so that we can use the user in all then blocks

  User.findOne({ email: email })
    .then((user) => {
      if (!user) {
        const error = new Error("User with this email does not exist");
        error.statusCode = 422;
        throw error;
      }

      // if we get to this block, it means the user with the email exists, so save the user to the
      // fetchedUser variable and check if the password is correct

      fetchedUser = user;
      return bcrypt.compare(password, user.password);
    })
    .then((passwordMatch) => {
      // In this then block, we receive a boolean value(true if the password match the user's password or false if otherwise)

      if (!passwordMatch) {
        const error = new Error("Password Incorrect");
        error.statusCode = 422;
        throw error;
      }

      // if we get here, it means the password entered is correct hence we sign a oken to send to the user.
      // Every endpoint that requires authentication would check for this token.

      const token = jwt.sign(
        {
          email: fetchedUser.email,
          userId: fetchedUser._id.toString(),
        },
        // the token sign secret keyword is a string(the longer the better) that you may want to save in a environment file

        "Thegreywolfsecret",
        { expiresIn: "11h" }
      );

      res.status(201).json({
        message: "User Log In successfull",
        token: token,
      });
    })
    .catch((err) => {
      if (!err.statusCode) {
        err.statusCode = 500;
      }
      console.log(err);
      next(err);
    });
};
