const genMsg = (username, text) => {
  return {
    username,
    text,
    createdAt: new Date().getTime(),
  };
};
const genLoc = (username, url) => {
  return {
    username,
    url,
    createdAt: new Date().getTime(),
  };
};
module.exports = { genMsg, genLoc };
